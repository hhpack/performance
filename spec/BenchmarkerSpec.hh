<?hh //partial

namespace hhpack\performance\spec;

use hhpack\performance\Benchmarker;
use hhpack\performance\spec\mock\SpyReporter;

describe(Benchmarker::class, function() {
  describe('->run()', function() {
    beforeEach(function() {
      $this->reporter = new SpyReporter();
      $this->benchmarker = new Benchmarker();
    });
    it('run the number of times you specify processing', function() {
      $result = $this->benchmarker->times(3)
        ->reporter($this->reporter)
        ->run(() ==> {
          usleep(2000);
        });

      list($stopCount, $finishCount) = $this->reporter->result();
      expect($stopCount)->toBe(3);
      expect($finishCount)->toBe(1);
    });
  });
});
