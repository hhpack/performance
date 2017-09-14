<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\TimeWatcher;
use HackPack\HackUnit\Contract\Assert;

final class TimeWatcherTest {
  <<Test>>
  public function timeResult(Assert $assert): void {
    $watcher = new TimeWatcher();

    $watcher->start();
    $watcher->stop();

    $result = $watcher->result();
    $assert->float($result->value())->gte(0.0);
  }
}
