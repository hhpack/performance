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
        private T $value
    )
    {
    }

    public function value() : T
    {
        return $this->value;
    }

    public static function of(T $value) : this
    {
        return new static($value);
    }

}
