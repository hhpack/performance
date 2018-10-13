<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\AsyncBenchmarker;
use HHPack\Performance\Test\Mock\SpyReporter;
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class AsyncBenchmarkerTest extends HackTest {
  public function testAsyncBenchmark(): void {
    $reporter = new SpyReporter();
    $benchmarker = new AsyncBenchmarker();

    $result = $benchmarker->times(3)
      ->reporter($reporter)
      ->run(
        async () ==> {
          await \HH\Asio\usleep(2000);
        },
      );

    \HH\Asio\join($result);

    list($stopCount, $finishCount) = $reporter->result();
    expect($stopCount)->toBeSame(3);
    expect($finishCount)->toBeSame(1);
  }
}
