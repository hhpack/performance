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

final class ComplexResult implements WatchedResult<ImmMap<string, num>>
{

    private ImmMap<string, WatchedResult<num>> $results;

    public function __construct(
        KeyedTraversable<string, WatchedResult<num>> $results = []
    )
    {
        $namedResult = Map {};

        foreach ($results as $key => $value) {
            $namedResult->set($key, $value);
        }
        $this->results = $namedResult->toImmMap();
    }

    public function first() : ImmMap<string, num>
    {
        return $this->results->map(($result) ==> $result->first());
    }

    public function last() : ImmMap<string, num>
    {
        return $this->results->map(($result) ==> $result->last());
    }

    <<__Memoize>>
    public function result() : ImmMap<string, num>
    {
        return $this->results->map(($result) ==> $result->result());
    }

}
