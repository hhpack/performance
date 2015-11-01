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

interface Range<Ti, To>
{
    public function getStartedValue() : Ti;
    public function getStoppedValue() : Ti;
    public function diff() : To;
    public static function createFrom(Pair<Ti, Ti> $range) : this;
}
