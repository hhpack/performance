<?hh //strict

/**
 * This file is part of hhpack\stopwatch.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\stopwatch\result;

use hhpack\stopwatch\Range;
use DateInterval;
use DateTimeImmutable;

final class DateTimeResult implements Range<DateTimeImmutable, DateInterval>
{

    public function __construct(
        private DateTimeImmutable $startedAt = new DateTimeImmutable(),
        private DateTimeImmutable $stoppedAt = new DateTimeImmutable()
    )
    {
    }

    public function getStartedValue() : DateTimeImmutable
    {
        return $this->startedAt;
    }

    public function getStoppedValue() : DateTimeImmutable
    {
        return $this->stoppedAt;
    }

    public function diff() : DateInterval
    {
        return $this->stoppedAt->diff($this->startedAt);
    }

    public static function createFrom(Pair<DateTimeImmutable, DateTimeImmutable> $range) : this
    {
        return new static($range[0], $range[1]);
    }

}
