<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\TimeWatcher;
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class TimeWatcherTest extends HackTest {
  public function testTimeResult(): void {
    $watcher = new TimeWatcher();

    $watcher->start();
    $watcher->stop();

    $result = $watcher->result();
    expect($result->value())->toBeGreaterThan(0.0);
  }
}
