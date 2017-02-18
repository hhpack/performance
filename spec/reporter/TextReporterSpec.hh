<?hh //partial

namespace HHPack\Performance\Spec\Reporter;

use HHPack\Performance\Result\ComplexResult;
use HHPack\Performance\Result\BenchmarkedResult;
use HHPack\Performance\Result\UsedMemory;
use HHPack\Performance\Result\ProcessingTime;
use HHPack\Performance\Reporter\TextReporter;
use HHPack\Performance\Writer\BufferedWriter;

describe(TextReporter::class, function() {
  describe('->onFinish()', function() {
    beforeEach(function() {
      $this->writer = new BufferedWriter();
      $this->report = file_get_contents(__DIR__ . '/../fixtures/text_report.txt');
      $this->reporter = new TextReporter($this->writer);
    });
    it('display benchmark result', function() {
      $this->reporter->onStop(new BenchmarkedResult(1, new ComplexResult([
        Pair { 'time', ProcessingTime::of( 0.003244 ) },
        Pair { 'memory', UsedMemory::of( 132344 ) }
      ])));
      $this->reporter->onStop(new BenchmarkedResult(2, new ComplexResult([
        Pair { 'time', ProcessingTime::of( 0.00324 ) },
        Pair { 'memory', UsedMemory::of( 13244 ) }
      ])));
      expect(function () {
        $this->reporter->onFinish();
        echo $this->writer;
      })->toPrint($this->report);
    });
  });
});
