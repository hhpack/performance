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

use hhpack\stopwatch\result\DateTimeResult;
use DateTimeImmutable;

final class DateTimeWatcher implements Watcher<DateTimeResult>
{

    private DateTimeImmutable $startDateTime;
    private DateTimeResult $processingDateTime;

    public function __construct()
    {
        $this->startDateTime = new DateTimeImmutable();
        $this->processingDateTime = new DateTimeResult();
    }

    public function start() : void
    {
        $this->startDateTime = new DateTimeImmutable();
    }

    public function stop() : void
    {
        $stopDateTime = new DateTimeImmutable();
        $result = Pair { $this->startDateTime, $stopDateTime };
        $this->processingDateTime = DateTimeResult::createFrom($result);
    }

    public function getResult() : DateTimeResult
    {
        return $this->processingDateTime;
    }

}
