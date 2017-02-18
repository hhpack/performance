<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance;

use HHPack\Performance\Result\ProcessingTime;

final class TimeWatcher implements Watcher<ProcessingTime>
{

    private float $startedAt;
    private ProcessingTime $processingTime;

    public function __construct()
    {
        $this->startedAt = (float) microtime(true);
        $this->processingTime = ProcessingTime::of(0.0);
    }

    public function start() : void
    {
        $this->startedAt = (float) microtime(true);
    }

    public function stop() : void
    {
        $stoppedAt = (float) microtime(true);

        $result = $stoppedAt - $this->startedAt;
        $this->processingTime = ProcessingTime::of($result);
    }

    public function result() : ProcessingTime
    {
        return $this->processingTime;
    }

}
