<?hh //partial

use hhpack\stopwatch\StopWatch;

describe(StopWatch::class, function() {
  describe('->stop()', function() {
    beforeEach(function() {
      $this->stopWatch = new StopWatch();
      $this->stopWatch->start();
    });
    it('returns processing result', function() {
      $this->stopWatch->stop();
      $result = $this->stopWatch->getResult();
      expect($result->getProcessingTime())->toBeGreaterThan(0);
    });
  });
});
