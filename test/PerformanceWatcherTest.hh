<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\{TimeWatcher, PerformanceWatcher};
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class PerformanceWatcherTest extends HackTest {
  public function testPerformanceResult(): void {
    $watcher = new PerformanceWatcher(['time' => new TimeWatcher()]);

    $watcher->start();
    $watcher->stop();

    $result = $watcher->result();
    expect((float)$result->at('time')->value())->toBeGreaterThan(0.0);
  }
}
