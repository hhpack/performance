<?hh //strict

/**
 * This file is part of hhpack\stopwatch.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\stopwatch;

use hhpack\stopwatch\result\MicrotimeResult;

final class ProcessingTimeWatcher implements Watcher<MicrotimeResult>
{

    private float $startedAt;
    private MicrotimeResult $processingTime;

    public function __construct()
    {
        $this->startedAt = (float) microtime(true);
        $this->processingTime = new MicrotimeResult();
    }

    public function start() : void
    {
        $this->startedAt = (float) microtime(true);
    }

    public function stop() : void
    {
        $stoppedAt = (float) microtime(true);

        $result = Pair { $this->startedAt, $stoppedAt };
        $this->processingTime = MicrotimeResult::createFrom($result);
    }

    public function result() : MicrotimeResult
    {
        return $this->processingTime;
    }

}
