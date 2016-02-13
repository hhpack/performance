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

final class BenchmarkedResult implements WatchedResult<ComplexResult> //, ConstMapAccess<string, WatchedResult<num>>
{

    private ComplexResult $result;

    public function __construct(
        int $number,
        ComplexResult $result
    )
    {
        $base = ComplexResult::fromItems( [ Pair { 'order', OrderNumber::of($number) }  ]);
        $this->result = $base->merge($result);
    }

    public function orderNumber() : int
    {
        return (int) $this->result->at('order')->value();
    }

    public function value() : ComplexResult
    {
        return $this->result;
    }

    public function map<Tu>((function(this):Tu) $mapper) : Tu
    {
        return $mapper($this);
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
        return $this->result->map(($value) ==> (string) $value);
    }

    public function toImmMap() : ImmMap<string, WatchedResult<num>>
    {
        return $this->result->toImmMap();
    }

    public function __toString() : string
    {
        return $this->result->__toString();
    }

}
