<?hh //partial

namespace hhpack\performance\spec\generator;

use hhpack\performance\generator\DefaultGenerator;

describe(DefaultGenerator::class, function() {
  describe('->generate()', function() {
    beforeEach(function() {
      $this->generator = new DefaultGenerator();
    });
    it('returns result with order number', function() {
      $orderNumber = Set {};
      $watchers = $this->generator->generate(5);

      foreach ($watchers as $number => $watcher) {
        $orderNumber->add($number);
      }
      expect($orderNumber->count())->toBe(5);
      expect($orderNumber->contains(1))->toBeTrue();
      expect($orderNumber->contains(2))->toBeTrue();
    });
  });
});
