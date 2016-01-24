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

use hhpack\performance\result\UsedMemory;

final class MemoryWatcher implements Watcher<UsedMemory>
{

    private int $startedMemory;
    private UsedMemory $usedMemory;

    public function __construct()
    {
        $this->startedMemory = (int) memory_get_usage(true);
        $this->usedMemory = UsedMemory::of(Pair { 0, 0 });
    }

    public function start() : void
    {
        $this->startedMemory = (int) memory_get_usage(true);
    }

    public function stop() : void
    {
        $stoppedMemory = (int) memory_get_usage(true);

        $result = Pair { $this->startedMemory, $stoppedMemory };
        $this->usedMemory = UsedMemory::of($result);
    }

    public function result() : UsedMemory
    {
        return $this->usedMemory;
    }

}