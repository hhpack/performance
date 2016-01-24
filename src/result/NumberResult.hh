<?hh //strict

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance\result;

use hhpack\performance\WatchedResult;

<<__ConsistentConstruct>>
abstract class NumberResult<T as num> implements WatchedResult<T>
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
    public function value() : T
    {
        return $this->last - $this->first;
    }

    public static function of(Pair<T, T> $range) : this
    {
        list($first, $last) = $range;
        return new static($first, $last);
    }

}
