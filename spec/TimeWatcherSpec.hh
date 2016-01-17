<?hh //partial

namespace hhpack\performance\spec;

use hhpack\performance\TimeWatcher;

describe(TimeWatcher::class, function() {
  describe('->stop()', function() {
    beforeEach(function() {
      $this->watcher = new TimeWatcher();
      $this->watcher->start();
    });
    it('returns processing result', function() {
      $this->watcher->stop();
      $result = $this->watcher->result();
      expect($result->diff())->toBeGreaterThan(0.0);
    });
  });
});
