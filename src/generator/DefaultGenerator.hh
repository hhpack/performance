<?hh //strict

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance\generator;

use hhpack\performance\Watcher;
use hhpack\performance\WatchedResult;
use hhpack\performance\WatcherGenerator;
use hhpack\performance\PerformanceWatcher;
use hhpack\performance\TimeWatcher;
use hhpack\performance\MemoryWatcher;


final class DefaultGenerator implements WatcherGenerator<ImmMap<string, WatchedResult<num>>>
{

    public function generate(int $count) : Iterator<Watcher<ImmMap<string, WatchedResult<num>>>>
    {
        $generator = () ==> {
            for ($i = 0; $i <= $count - 1; $i++) {
                yield PerformanceWatcher::fromItems([
                    Pair { 'time', new TimeWatcher() },
                    Pair { 'memory', new MemoryWatcher() }
                ]);
            }
        };
        return $generator();
    }

}
