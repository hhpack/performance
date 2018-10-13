<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\MemoryWatcher;
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class MemoryWatcherTest extends HackTest {
  public function testMemoryResult(): void {
    $watcher = new MemoryWatcher();
    $watcher->start();
    $watcher->stop();

    $result = $watcher->result();
    expect($result->value())->toBeGreaterThan(0);
  }
}
