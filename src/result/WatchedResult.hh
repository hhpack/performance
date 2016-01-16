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

final class WatchedResult<T as num> implements Range<T>
{

    public function __construct(
        private T $first,
        private T $last
    )
    {
    }

    public function first() : T
    {
        return $this->first;
    }

    public function last() : T
    {
        return $this->last;
    }

    <<__Memoize>>
    public function diff() : T
    {
        return $this->last - $this->first;
    }

    public static function from(Pair<T, T> $range) : this
    {
        list($first, $last) = $range;
        return new static($first, $last);
    }

}
