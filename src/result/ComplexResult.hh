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

final class ComplexResult implements WatchedResult<ImmMap<string, num>> //, ConstMapAccess<string, WatchedResult<num>>
{

    private ImmMap<string, WatchedResult<num>> $watchedResult;

    public function __construct(
        KeyedTraversable<string, WatchedResult<num>> $results = []
    )
    {
        $watchedResult = Map {};

        foreach ($results as $key => $value) {
            $watchedResult->set($key, $value);
        }
        $this->watchedResult = $watchedResult->toImmMap();
    }

    <<__Memoize>>
    public function value() : ImmMap<string, num>
    {
        return $this->toImmMap();
    }

    public function mapWithKey<Tu>((function(string,WatchedResult<num>):Tu) $mapper) : ImmMap<string, Tu>
    {
        return $this->watchedResult->mapWithKey($mapper);
    }

    public function map<Tu>((function(WatchedResult<num>):Tu) $mapper) : ImmMap<string, Tu>
    {
        return $this->watchedResult->map($mapper);
    }

    public function contains<Tu super string>(Tu $m) : bool
    {
        return $this->watchedResult->contains($m);
    }

    public function at(string $k) : WatchedResult<num>
    {
        return $this->watchedResult->at($k);
    }

    public function get(string $k) : ?WatchedResult<num>
    {
        return $this->watchedResult->get($k);
    }

    public function containsKey<Tu super string>(Tu $k): bool 
    {
        return $this->watchedResult->containsKey($k);
    }

    public function items(): Iterable<Pair<string, WatchedResult<num>>>
    {
        return $this->watchedResult->items();
    }

    public function toImmMap() : ImmMap<string, num>
    {
        return $this->watchedResult->map(($result) ==> $result->value());
    }

    public function __toString() : string
    {
        $values = $this->map(($value) ==> (string) $value)->toValuesArray();
        return implode(', ', $values);
    }

}
