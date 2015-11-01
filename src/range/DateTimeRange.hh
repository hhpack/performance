<?hh //strict

/**
 * This file is part of hhpack\stopwatch.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\stopwatch\range;

use hhpack\stopwatch\Range;
use DateInterval;
use DateTimeImmutable;

final class DateTimeRange implements Range<DateTimeImmutable, DateInterval>
{

    public function __construct(
        private DateTimeImmutable $startAt = new DateTimeImmutable(),
        private DateTimeImmutable $endAt = new DateTimeImmutable()
    )
    {
    }

    public function getStartedValue() : DateTimeImmutable
    {
        return $this->startAt;
    }

    public function getStoppedValue() : DateTimeImmutable
    {
        return $this->endAt;
    }

    public function diff() : DateInterval
    {
        return $this->endAt->diff($this->startAt);
    }

    public static function createFrom(Pair<DateTimeImmutable, DateTimeImmutable> $range) : this
    {
        return new static($range[0], $range[1]);
    }

}
