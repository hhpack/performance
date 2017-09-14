<?hh //strict

namespace HHPack\Performance\Test\Mock;

use HHPack\Performance\ResultReporter;
use HHPack\Performance\Result\BenchmarkedResult;

final class SpyReporter implements ResultReporter {

  private int $stopCount = 0;
  private int $finishCount = 0;

  public function onStop(BenchmarkedResult $result): void {
    $this->stopCount++;
  }

  public function onFinish(): void {
    $this->finishCount++;
  }

  public function result(): (int, int) {
    return tuple($this->stopCount, $this->finishCount);
  }
}
