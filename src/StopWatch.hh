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

use hhpack\stopwatch\range\DateTimeRange;
use hhpack\stopwatch\range\MicrotimeRange;
use DateTimeImmutable;

final class StopWatch implements Watcher<ProcessingTime>
{

//    private float $startAt = 0.0;
//    private DateTimeImmutable $startDateTime;

//    private float $startAt = 0.0;
    private DateTimeWatcher $dateTimeWatcher;
    private ProcessingTimeWatcher $processingTimeWatcher;
    private ProcessingTime $processingTime;

    public function __construct()
    {
        $this->dateTimeWatcher = new DateTimeWatcher();
        $this->processingTimeWatcher = new ProcessingTimeWatcher();
        $this->processingTime = new ProcessingTime();
    }

    public function start() : void
    {
        $watchers = [
            $this->dateTimeWatcher,
            $this->processingTimeWatcher
        ];

        foreach ($watchers as $watcher) {
            $watcher->start();
        }
    }

    public function stop() : void
    {
        $watchers = [
            $this->dateTimeWatcher,
            $this->processingTimeWatcher
        ];

        foreach ($watchers as $watcher) {
            $watcher->stop();
        }

        $this->processingTime = new ProcessingTime(
            $this->processingTimeWatcher->getResult(),
            $this->dateTimeWatcher->getResult()
        );
    }

    public function getResult() : ProcessingTime
    {
        return $this->processingTime;
    }

}
