<?hh //partial

namespace hhpack\performance\spec\reporter;

use hhpack\performance\result\ComplexResult;
use hhpack\performance\result\UsedMemory;
use hhpack\performance\result\ProcessingTime;
use hhpack\performance\reporter\TextReporter;

describe(TextReporter::class, function() {
  describe('->onFinish()', function() {
    beforeEach(function() {
      $this->report = file_get_contents(__DIR__ . '/../fixtures/text_report.txt');
      $this->reporter = new TextReporter();
    });
    it('returns processing result', function() {
      $this->reporter->onStop(new ComplexResult([
        'time' => ProcessingTime::of(Pair { 0, 0.003244 }),
        'memory' => UsedMemory::of(Pair { 0, 132344 })
      ]));
      $this->reporter->onStop(new ComplexResult([
        'time' => ProcessingTime::of(Pair { 0, 0.00324 }),
        'memory' => UsedMemory::of(Pair { 0, 13244 })
      ]));
      expect(function () {
        $this->reporter->onFinish();
      })->toPrint($this->report);
    });
  });
});
