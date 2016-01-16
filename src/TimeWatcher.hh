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

use hhpack\stopwatch\result\WatchedResult;

final class TimeWatcher implements NamedWatcher<WatchedResult<float>>
{

    private float $startedAt;
    private WatchedResult<float> $processingTime;

    public function __construct(
        private string $name
    )
    {
        $this->startedAt = (float) microtime(true);
        $this->processingTime = new WatchedResult(0.0, 0.0);
    }

    public function name() : string
    {
        return $this->name;
    }

    public function start() : void
    {
        $this->startedAt = (float) microtime(true);
    }

    public function stop() : void
    {
        $stoppedAt = (float) microtime(true);

        $result = Pair { $this->startedAt, $stoppedAt };
        $this->processingTime = WatchedResult::of($result);
    }

    public function result() : WatchedResult<float>
    {
        return $this->processingTime;
    }

}
