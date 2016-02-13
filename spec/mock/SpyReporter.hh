<?hh //strict

namespace hhpack\performance\spec\mock;

use hhpack\performance\ResultReporter;
use hhpack\performance\result\BenchmarkedResult;

final class SpyReporter implements ResultReporter
{

    private int $stopCount = 0;
    private int $finishCount = 0;

    public function onStop(BenchmarkedResult $result) : void
    {
        $this->stopCount++;
    }

    public function onFinish() : void
    {
        $this->finishCount++;
    }

    public function result() : (int, int)
    {
        return tuple($this->stopCount, $this->finishCount);
    }

}
