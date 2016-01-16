<?hh //partial

namespace hhpack\stopwatch\spec;

use hhpack\stopwatch\TimeWatcher;
use hhpack\stopwatch\PerformanceWatcher;

describe(PerformanceWatcher::class, function() {
  describe('->stop()', function() {
    beforeEach(function() {
      $this->watcher = new PerformanceWatcher([
        'time' => new TimeWatcher()
      ]);
      $this->watcher->start();
    });
    it('returns processing result', function() {
      $this->watcher->stop();
      $result = $this->watcher->result();
      expect($result->at('time')->diff())->toBeGreaterThan(0.0);
    });
  });
});
