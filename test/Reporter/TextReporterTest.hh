<?hh //strict

namespace HHPack\Performance\Test\Reporter;

use HHPack\Performance\Result\{
  ComplexResult,
  BenchmarkedResult,
  UsedMemory,
  ProcessingTime,
};
use HHPack\Performance\Reporter\TextReporter;
use HHPack\Performance\Writer\BufferedWriter;
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class TextReporterTest extends HackTest {
  public function testReport(): void {
    $writer = new BufferedWriter();
    $report = \file_get_contents(__DIR__.'/../fixtures/text_report.txt');
    $reporter = new TextReporter($writer);

    $reporter->onStop(
      new BenchmarkedResult(
        1,
        new ComplexResult(
          [
            Pair { 'time', ProcessingTime::of(0.003244) },
            Pair { 'memory', UsedMemory::of(132344) },
          ],
        ),
      ),
    );

    $reporter->onStop(
      new BenchmarkedResult(
        2,
        new ComplexResult(
          [
            Pair { 'time', ProcessingTime::of(0.00324) },
            Pair { 'memory', UsedMemory::of(13244) },
          ],
        ),
      ),
    );

    $reporter->onFinish();

    expect((string)$writer)->toBeSame($report);
  }
}
