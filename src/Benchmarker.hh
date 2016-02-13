<?hh //strict

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance;

use hhpack\performance\reporter\TextReporter;
use hhpack\performance\generator\DefaultGenerator;
use hhpack\performance\result\ComplexResult;
use hhpack\performance\result\BenchmarkedResult;

final class Benchmarker implements BenchmarkRunner<void>
{

    private ResultReporter $reporter;
    private WatcherGenerator<ComplexResult> $generator;

    public function __construct(
        WatcherGenerator<ComplexResult> $generator = new DefaultGenerator(),
        ResultReporter $reporter = new TextReporter(),
        private int $times = 1
    )
    {
        $this->reporter = $reporter;
        $this->generator = $generator;
    }

    public function times(int $times) : this
    {
        $this->times = $times;
        return $this;
    }

    public function reporter(ResultReporter $reporter) : this
    {
        $this->reporter = $reporter;
        return $this;
    }

    public function run((function():void) $callback) : void
    {
        foreach ($this->execute($callback) as $value) {
            $this->reporter->onStop( $value );
        }
        $this->reporter->onFinish();
    }

    private function execute((function():void) $callback) : Iterator<BenchmarkedResult>
    {
        foreach ($this->generator->generate($this->times) as $number => $watcher) {
            $action = () ==> {
                $watcher->start();
                $callback();
                $watcher->stop();
                return $watcher->result();
            };
            yield new BenchmarkedResult($number, $action());
        }
    }

}
