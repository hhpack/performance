<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\AsyncBenchmarker;
use HHPack\Performance\Test\Mock\SpyReporter;
use HackPack\HackUnit\Contract\Assert;

final class AsyncBenchmarkerTest {
  <<Test>>
  public function asyncBenchmark(Assert $assert): void {
    $reporter = new SpyReporter();
    $benchmarker = new AsyncBenchmarker();

    $result =
      $benchmarker->times(3)
        ->reporter($reporter)
        ->run(
          async () ==> {
            await \HH\Asio\usleep(2000);
          },
        );

    \HH\Asio\join($result);

    list($stopCount, $finishCount) = $reporter->result();
    $assert->int($stopCount)->eq(3);
    $assert->int($finishCount)->eq(1);
  }
}
