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

interface Range<T>
{
    public function first() : T;
    public function last() : T;
    public function diff() : T;
    public static function from(Pair<T, T> $range) : this;
}
