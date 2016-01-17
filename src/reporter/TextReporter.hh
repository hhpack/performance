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

use hhpack\performance\Reporter;
use hhpack\performance\WatchedResult;

final class TextReporter implements Reporter
{

    public function onStop(ImmMap<string, WatchedResult<num>> $result) : void
    {
        $texts = $result->mapWithKey(($key, $result) ==> {
            return sprintf("%s: %s", $key, (string) $result->result());
        })->values()->toArray();

        fwrite(STDOUT, implode(' / ', $texts) . PHP_EOL);
    }

}
