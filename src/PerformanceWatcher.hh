<?hh //strict

/**
 * This file is part of hhpack\stopwatch.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\stopwatch;

use hhpack\stopwatch\result\WatchedResult;

final class PerformanceWatcher implements Watcher<ImmMap<string, WatchedResult<num>>>
{

    private Map<string, Watcher<WatchedResult<num>>> $watchers;

    public function __construct(
        KeyedTraversable<string, Watcher<WatchedResult<num>>> $watchers = []
    )
    {
        $items = Vector {};

        foreach ($watchers as $key => $watcher) {
            $items->add(Pair { $key, $watcher });
        }

        $this->watchers = Map::fromItems($items);
    }

    public function start() : void
    {
        foreach ($this->watchers->values() as $watcher) {
            $watcher->start();
        }
    }

    public function stop() : void
    {
        foreach ($this->watchers->values() as $watcher) {
            $watcher->stop();
        }
    }

    public function result() : ImmMap<string, WatchedResult<num>>
    {
        return $this->watchers->map(($watcher) ==> $watcher->result())
            ->toImmMap();
    }

}
