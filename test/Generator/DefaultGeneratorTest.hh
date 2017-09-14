<?hh //strict

namespace HHPack\Performance\Test\Generator;

use HHPack\Performance\Generator\DefaultGenerator;
use HackPack\HackUnit\Contract\Assert;

final class DefaultGeneratorTest {
  <<Test>>
  public function generateWatchers(Assert $assert): void {
    $generator = new DefaultGenerator();

    $orderNumber = Set {};
    $watchers = $generator->generate(5);

    foreach ($watchers as $number => $watcher) {
      $orderNumber->add($number);
    }

    $assert->int($orderNumber->count())->eq(5);
    $assert->bool($orderNumber->contains(1))->is(true);
    $assert->bool($orderNumber->contains(2))->is(true);
  }
}
