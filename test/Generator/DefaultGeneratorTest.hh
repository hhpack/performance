<?hh //strict

namespace HHPack\Performance\Test\Generator;

use HHPack\Performance\Generator\DefaultGenerator;
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class DefaultGeneratorTest extends HackTest {
  public function testGenerateWatchers(): void {
    $generator = new DefaultGenerator();

    $orderNumber = Set {};
    $watchers = $generator->generate(5);

    foreach ($watchers as $number => $watcher) {
      $orderNumber->add($number);
    }

    expect($orderNumber->count())->toBeSame(5);
    expect($orderNumber->contains(1))->toBeTrue();
    expect($orderNumber->contains(2))->toBeTrue();
  }
}
