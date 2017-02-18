<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Generator;

use HHPack\Performance\Watcher;
use HHPack\Performance\WatchedResult;
use HHPack\Performance\WatcherGenerator;
use HHPack\Performance\PerformanceWatcher;
use HHPack\Performance\TimeWatcher;
use HHPack\Performance\MemoryWatcher;
use HHPack\Performance\Result\ComplexResult;

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
