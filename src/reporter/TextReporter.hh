<?hh //strict

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance\reporter;

use hhpack\performance\WatchedResult;
use hhpack\performance\ResultReporter;
use hhpack\performance\result\ComplexResult;

final class TextReporter implements ResultReporter
{

    private Vector<ImmMap<string, num>> $results;
    private Map<string, int> $paddingLength;

    public function __construct()
    {
        $this->results = Vector {};
        $this->paddingLength = Map {};
    }

    public function onStop(ComplexResult $result) : void
    {
        $watchedResult = $result->toImmMap();

        foreach ($watchedResult as $key => $value) {
            $length = strlen((string) $value);
            $paddingLength = $this->paddingLength->get($key);
            $paddingLength = ($paddingLength === null) ? 0 : $paddingLength;
            $this->paddingLength->set($key, ($length > $paddingLength) ? $length : $paddingLength);
        }

        $this->results->add($watchedResult);
    }

    public function onFinish() : void
    {
        foreach ($this->results as $result) {
            $columns = $result->mapWithKey(($key, $value) ==> {
                $max = $this->paddingLength->at($key);
                return str_pad((string) $value, $max, ' ', STR_PAD_LEFT);
            })->values()->toArray();
            fwrite(STDOUT, implode(', ', $columns) . PHP_EOL);
        }
    }

}
