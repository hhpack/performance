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

use hhpack\performance\result\ComplexResult;

final class PerformanceWatcher implements ComplexWatcher<num>
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

    public function result() : ComplexResult
    {
        $collector = ($watcher) ==> $watcher->result();
        $result = $this->watchers->map($collector)->items();

        return ComplexResult::fromItems($result);
    }

    public static function fromItems(Traversable<Pair<string, Watcher<WatchedResult<num>>>> $watchers) : this
    {
        return new static(ImmMap::fromItems($watchers));
    }

}
