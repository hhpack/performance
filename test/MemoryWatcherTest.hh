<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\MemoryWatcher;
use HackPack\HackUnit\Contract\Assert;

final class MemoryWatcherTest
{
    <<Test>>
    public function memoryResult(Assert $assert) : void
    {
        $watcher = new MemoryWatcher();
        $watcher->start();
        $watcher->stop();

        $result = $watcher->result();
        $assert->int($result->value())->gte(0);
    }
}
