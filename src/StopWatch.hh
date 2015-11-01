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

    private float $startAt = 0.0;
    private DateTimeImmutable $startDateTime;
    private ProcessingTime $processingTime;

    public function __construct()
    {
        $this->processingTime = new ProcessingTime();
        $this->startDateTime = new DateTimeImmutable();
    }

    public function start() : void
    {
        $this->startAt = (float) microtime(true);
        $this->startDateTime = new DateTimeImmutable();
    }

    public function stop() : void
    {
        $stopAt = (float) microtime(true);
        $stopDateTime = new DateTimeImmutable();

        $dateTimeRange = DateTimeRange::createFrom( Pair { $this->startDateTime, $stopDateTime } );
        $microtimeRange = MicrotimeRange::createFrom( Pair { $this->startAt, $stopAt } );

        $this->processingTime = new ProcessingTime($microtimeRange, $dateTimeRange);
    }

    public function getResult() : ProcessingTime
    {
        return $this->processingTime;
    }

}
