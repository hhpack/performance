<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Example;

require_once __DIR__.'/../vendor/hh_autoload.php';

use HHPack\Performance\{PerformanceWatcher, TimeWatcher, MemoryWatcher};

<<__Entrypoint>>
function watcher_main(): noreturn {
  $watcher = PerformanceWatcher::fromItems(
    [
      Pair { 'time', new TimeWatcher() },
      Pair { 'memory', new MemoryWatcher() },
    ],
  );

  $watcher->start();
  $watcher->stop();

  $result = $watcher->result();
  $texts = $result->mapWithKey(
    ($key, $result) ==> {
      return \sprintf("%s: %s", $key, (string)$result->value());
    },
  )
    ->values();

  foreach ($texts as $text) {
    echo $text, \PHP_EOL;
  }

  exit(0);
}
