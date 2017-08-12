<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance;

use HHPack\Performance\Reporter\TextReporter;
use HHPack\Performance\Generator\DefaultGenerator;
use HHPack\Performance\Result\{ ComplexResult, BenchmarkedResult };

final class AsyncBenchmarker implements BenchmarkRunner<Awaitable<void>>
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

    public async function run((function():Awaitable<void>) $callback) : Awaitable<void>
    {
        foreach ($this->execute($callback) await as $value) {
            $this->reporter->onStop( $value );
        }
        $this->reporter->onFinish();
    }

    private async function execute((function():Awaitable<void>) $callback) : AsyncIterator<BenchmarkedResult>
    {
        foreach ($this->generator->generate($this->times) as $number => $watcher) {
            $action = async () ==> {
                $watcher->start();
                await $callback();
                $watcher->stop();
                return $watcher->result();
            };
            $result = await $action();
            yield new BenchmarkedResult($number, $result);
        }
    }

}
