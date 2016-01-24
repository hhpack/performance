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

final class BenchMarker
{

    private PerformanceWatcher $watcher;

    public function __construct(
        private Reporter $reporter,
        private int $times = 1
    )
    {
        $this->watcher = PerformanceWatcher::fromItems([
            Pair { 'time', new TimeWatcher() },
            Pair { 'memory', new MemoryWatcher() }
        ]);
    }

    public function times(int $times) : this
    {
        $this->times = $times;
        return $this;
    }

    public async function run((function():Awaitable<void>) $callback) : Awaitable<void>
    {
        foreach ($this->execute($callback) await as $value) {
            $this->reporter->onStop( $this->watcher->result() );
        }
    }

    private async function execute((function():Awaitable<void>) $callback) : AsyncIterator<ImmMap<string, WatchedResult<num>>>
    {
        for ($i = 0; $i <= $this->times - 1; $i++) {
            $action = async () ==> {
                $this->watcher->start();
                await $callback();
                $this->watcher->stop();
                return $this->watcher->result();
            };
            $watchedResult = await $action();
            yield $watchedResult;
        }
    }

}
