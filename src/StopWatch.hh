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

final class StopWatch implements Watcher<Result>
{

    private DateTimeWatcher $dateTimeWatcher;
    private ProcessingTimeWatcher $processingTimeWatcher;
    private Result $result;

    public function __construct()
    {
        $this->dateTimeWatcher = new DateTimeWatcher();
        $this->processingTimeWatcher = new ProcessingTimeWatcher();
        $this->result = new Result();
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

        $this->result = new Result(
            $this->processingTimeWatcher->getResult(),
            $this->dateTimeWatcher->getResult()
        );
    }

    public function getResult() : Result
    {
        return $this->result;
    }

}
