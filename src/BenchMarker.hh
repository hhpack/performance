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

final class BenchMarker
{

    private ResultReporter $reporter;
    private WatcherGenerator<ImmMap<string, WatchedResult<num>>> $generator;

    public function __construct(
        WatcherGenerator<ImmMap<string, WatchedResult<num>>> $generator = new DefaultGenerator(),
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

    public async function run((function():Awaitable<void>) $callback) : Awaitable<void>
    {
        foreach ($this->execute($callback) await as $value) {
            $this->reporter->onStop( $value );
        }
    }

    private async function execute((function():Awaitable<void>) $callback) : AsyncIterator<ImmMap<string, WatchedResult<num>>>
    {
        foreach ($this->generator->generate($this->times) as $watcher) {
            $action = async () ==> {
                $watcher->start();
                await $callback();
                $watcher->stop();
                return $watcher->result();
            };
            $result = await $action();
            yield $result;
        }
    }

}
