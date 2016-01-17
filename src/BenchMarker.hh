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
        private Reporter $reporter
    )
    {
        $this->watcher = PerformanceWatcher::fromItems([
            Pair { 'time', new TimeWatcher() },
            Pair { 'memory', new MemoryWatcher() }
        ]);
    }

    public function start() : void
    {
        $this->watcher->start();
    }

    public function stop() : void
    {
        $this->watcher->stop();
        $this->reporter->onStop( $this->watcher->result() );
    }

}
