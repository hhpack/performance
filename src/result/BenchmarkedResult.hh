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

// Do not use because the error occurs at runtime.
//
// see https://github.com/hhvm/user-documentation/issues/261
//     https://github.com/facebook/hhvm/issues/6758
// use ConstMapAccess;

final class BenchmarkedResult implements WatchedResult<ImmMap<string, num>> //, ConstMapAccess<string, WatchedResult<num>>
{

    public function __construct(
        private int $number,
        private ComplexResult $result
    )
    {
    }

    public function orderNumber() : int
    {
        return $this->number;
    }

    public function first() : ImmMap<string, num>
    {
        return $this->result->first();
    }

    public function last() : ImmMap<string, num>
    {
        return $this->result->last();
    }

    public function value() : ImmMap<string, num>
    {
        return $this->result->value();
    }

    public function mapWithKey<Tu>((function(string,WatchedResult<num>):Tu) $mapper) : ImmMap<string, Tu>
    {
        return $this->result->mapWithKey($mapper);
    }

    public function map<Tu>((function(WatchedResult<num>):Tu) $mapper) : ImmMap<string, Tu>
    {
        return $this->result->map($mapper);
    }

    public function contains<Tu super string>(Tu $m) : bool
    {
        return $this->result->contains($m);
    }

    public function at(string $k) : WatchedResult<num>
    {
        return $this->result->at($k);
    }

    public function get(string $k) : ?WatchedResult<num>
    {
        return $this->result->get($k);
    }

    public function containsKey<Tu super string>(Tu $k): bool 
    {
        return $this->result->containsKey($k);
    }

    public function mapToString() : ImmMap<string, string>
    {
        $orderedResult = Map { 'order' => $this->number };
        $orderedResult->addAll( $this->result->items() );

        return $orderedResult->toImmMap()->map($value ==> (string) $value);
    }

    public function toImmMap() : ImmMap<string, num>
    {
        return $this->result->toImmMap();
    }

    public function __toString() : string
    {
        return $this->result->__toString();
    }

}
