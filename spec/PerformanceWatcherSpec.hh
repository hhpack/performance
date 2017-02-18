<?hh //partial

namespace HHPack\Performance\Spec;

use HHPack\Performance\TimeWatcher;
use HHPack\Performance\PerformanceWatcher;

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
      expect($result->at('time')->value())->toBeGreaterThan(0.0);
    });
  });
});
