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

final class MicrotimeResult implements Range<float, float>
{

    public function __construct(
        private float $startedAt = 0.0,
        private float $stoppedAt = 0.0
    )
    {
    }

    public function getStartedValue() : float
    {
        return $this->startedAt;
    }

    public function getStoppedValue() : float
    {
        return $this->stoppedAt;
    }

    <<__Memoize>>
    public function diff() : float
    {
        return $this->stoppedAt - $this->startedAt;
    }

    public static function createFrom(Pair<float, float> $range) : this
    {
        return new static($range[0], $range[1]);
    }

}