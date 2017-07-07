<?hh //strict

namespace HHPack\Performance\Test;

use HHPack\Performance\Benchmarker;
use HHPack\Performance\Test\Mock\SpyReporter;
use HackPack\HackUnit\Contract\Assert;

final class BenchmarkerTest
{
    <<Test>>
    public function benchmark(Assert $assert) : void
    {
        $reporter = new SpyReporter();
        $benchmarker = new Benchmarker();

        $benchmarker->times(3)
            ->reporter($reporter)
            ->run(() ==> { usleep(2000); });

        list($stopCount, $finishCount) = $reporter->result();
        $assert->int($stopCount)->eq(3);
        $assert->int($finishCount)->eq(1);
    }
}
