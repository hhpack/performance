<?hh //partial

namespace hhpack\performance\spec;

use hhpack\performance\AsyncBenchmarker;
use hhpack\performance\spec\mock\SpyReporter;

describe(AsyncBenchmarker::class, function() {
  describe('->run()', function() {
    beforeEach(function() {
      $this->reporter = new SpyReporter();
      $this->benchmarker = new AsyncBenchmarker();
    });
    it('run the number of times you specify processing', function() {
      $result = $this->benchmarker->times(3)
        ->reporter($this->reporter)
        ->run(async () ==> {
          await \HH\Asio\usleep(2000);
        });

      \HH\Asio\join($result);

      list($stopCount, $finishCount) = $this->reporter->result();
      expect($stopCount)->toBe(3);
      expect($finishCount)->toBe(1);
    });
  });
});
