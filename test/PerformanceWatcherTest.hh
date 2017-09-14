<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\{TimeWatcher, PerformanceWatcher};
use HackPack\HackUnit\Contract\Assert;

final class PerformanceWatcherTest {
  <<Test>>
  public function performanceResult(Assert $assert): void {
    $watcher = new PerformanceWatcher(['time' => new TimeWatcher()]);

    $watcher->start();
    $watcher->stop();

    $result = $watcher->result();
    $assert->float((float) $result->at('time')->value())->gte(0.0);
  }
}
