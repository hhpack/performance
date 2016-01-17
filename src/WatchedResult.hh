<?hh //strict

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance;

interface WatchedResult<T>
{
    public function first() : T;
    public function last() : T;
    public function result() : T;
    public static function of(Pair<T, T> $range) : this;
}
