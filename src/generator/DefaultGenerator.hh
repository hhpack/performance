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
use hhpack\performance\result\ComplexResult;

final class DefaultGenerator implements WatcherGenerator<ComplexResult>
{

    public function generate(int $count) : KeyedIterator<int, Watcher<ComplexResult>>
    {
        $generator = () ==> {
            for ($i = 0; $i <= $count - 1; $i++) {
                $watcher = PerformanceWatcher::fromItems([
                    Pair { 'time', new TimeWatcher() },
                    Pair { 'memory', new MemoryWatcher() }
                ]);
                yield ($i + 1) => $watcher;
            }
        };
        return $generator();
    }

}
