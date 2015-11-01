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

final class ProcessingTime
{

    public function __construct(
        private float $startAt = 0.0,
        private float $stopAt = 0.0
    )
    {
    }

    public function getStartAt() : float
    {
        return $this->startAt;
    }

    public function getStopAt() : float
    {
        return $this->stopAt;
    }

    <<__Memoize>>
    public function getProcessingTime() : float
    {
        return $this->stopAt - $this->startAt;
    }

}
