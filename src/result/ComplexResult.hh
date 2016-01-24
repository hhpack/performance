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
use ConstMapAccess;

final class ComplexResult implements WatchedResult<ImmMap<string, num>>, ConstMapAccess<string, num>
{

    private ImmMap<string, num> $result;
    private ImmMap<string, WatchedResult<num>> $watchedResult;

    public function __construct(
        KeyedTraversable<string, WatchedResult<num>> $results = []
    )
    {
        $result = Map {};
        $watchedResult = Map {};

        foreach ($results as $key => $value) {
            $result->set($key, $value->result());
            $watchedResult->set($key, $value);
        }
        $this->result = $result->toImmMap();
        $this->watchedResult = $watchedResult->toImmMap();
    }

    <<__Memoize>>
    public function first() : ImmMap<string, num>
    {
        return $this->watchedResult->map(($result) ==> $result->first());
    }

    <<__Memoize>>
    public function last() : ImmMap<string, num>
    {
        return $this->watchedResult->map(($result) ==> $result->last());
    }

    <<__Memoize>>
    public function result() : ImmMap<string, num>
    {
        return $this->toImmMap();
    }

    public function mapWithKey<Tu>((function(string,num):Tu) $mapper) : ImmMap<string, Tu>
    {
        return $this->result->mapWithKey($mapper);
    }

    public function contains<Tu super string>(Tu $m) : bool
    {
        return $this->result->contains($m);
    }

    public function at(string $k) : num
    {
        return $this->result->at($k);
    }

    public function get(string $k) : ?num
    {
        return $this->result->get($k);
    }

    public function containsKey<Tu super string>(Tu $k): bool 
    {
        return $this->result->containsKey($k);
    }

    public function toImmMap() : ImmMap<string, num>
    {
        return $this->result->toImmMap();
    }

}
