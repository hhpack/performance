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

final class MemoryWatcher implements Watcher<WatchedResult<int>>
{

    private int $startedMemory;
    private WatchedResult<int> $usedMemory;

    public function __construct()
    {
        $this->startedMemory = (int) memory_get_usage(true);
        $this->usedMemory = WatchedResult::of(Pair { 0, 0 });
    }

    public function start() : void
    {
        $this->startedMemory = (int) memory_get_usage(true);
    }

    public function stop() : void
    {
        $stoppedMemory = (int) memory_get_usage(true);

        $result = Pair { $this->startedMemory, $stoppedMemory };
        $this->usedMemory = WatchedResult::of($result);
    }

    public function result() : WatchedResult<int>
    {
        return $this->usedMemory;
    }

}
