<?hh //partial

namespace HHPack\Performance\Spec;

use HHPack\Performance\TimeWatcher;

describe(TimeWatcher::class, function() {
  describe('->stop()', function() {
    beforeEach(function() {
      $this->watcher = new TimeWatcher();
      $this->watcher->start();
    });
    it('returns processing result', function() {
      $this->watcher->stop();
      $result = $this->watcher->result();
      expect($result->value())->toBeGreaterThan(0.0);
    });
  });
});
