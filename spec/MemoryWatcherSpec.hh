<?hh //partial

namespace HHPack\Performance\Spec;

use HHPack\Performance\MemoryWatcher;

describe(MemoryWatcher::class, function() {
  describe('->stop()', function() {
    beforeEach(function() {
      $this->watcher = new MemoryWatcher();
      $this->watcher->start();
    });
    it('returns processing result', function() {
      $this->watcher->stop();
      $result = $this->watcher->result();
      expect($result->value())->toBeGreaterThan(0);
    });
  });
});
