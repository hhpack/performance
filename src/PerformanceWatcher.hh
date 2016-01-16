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

    private Vector<NamedWatcher<WatchedResult<num>>> $watchers;

    public function __construct(
        Traversable<NamedWatcher<WatchedResult<num>>> $watchers = []
    )
    {
        $this->watchers = Vector::fromItems($watchers);
    }

    public function start() : void
    {
        foreach ($this->watchers as $watcher) {
            $watcher->start();
        }
    }

    public function stop() : void
    {
        foreach ($this->watchers as $watcher) {
            $watcher->stop();
        }
    }

    public function result() : ImmMap<string, WatchedResult<num>>
    {
        $result = Map {};

        foreach ($this->watchers as $watcher) {
            $result->set($watcher->name(), $watcher->result());
        }

        return $result->toImmMap();
    }

}
