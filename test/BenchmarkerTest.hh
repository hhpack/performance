<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\Benchmarker;
use HHPack\Performance\Test\Mock\SpyReporter;
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class BenchmarkerTest extends HackTest {
  public function testBenchmark(): void {
    $reporter = new SpyReporter();
    $benchmarker = new Benchmarker();

    $benchmarker->times(3)
      ->reporter($reporter)
      ->run(
        () ==> {
          \usleep(2000);
        },
      );

    list($stopCount, $finishCount) = $reporter->result();
    expect($stopCount)->toBeSame(3);
    expect($finishCount)->toBeSame(1);
  }
}
