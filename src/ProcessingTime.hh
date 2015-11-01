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
use hhpack\stopwatch\result\MicrotimeResult;

final class ProcessingTime
{

    public function __construct(
        private MicrotimeResult $microtimeRange = new MicrotimeResult(),
        private DateTimeResult $dateTimeRange = new DateTimeResult()
    )
    {
    }

    public function getStartedMicrotime() : float
    {
        return $this->microtimeRange->getStartedValue();
    }

    public function getStoppedMicrotime() : float
    {
        return $this->microtimeRange->getStoppedValue();
    }

    <<__Memoize>>
    public function getProcessingTime() : float
    {
        return $this->microtimeRange->diff();
    }

}
