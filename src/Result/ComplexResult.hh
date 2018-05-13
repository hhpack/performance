<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Result;

use HHPack\Performance\WatchedResult;

// Do not use because the error occurs at runtime.
//
// see https://github.com/hhvm/user-documentation/issues/261
//     https://github.com/facebook/hhvm/issues/6758
// use ConstMapAccess;

final class ComplexResult
  implements
    WatchedResult<ImmMap<string, WatchedResult<num>>> //, ConstMapAccess<string, WatchedResult<num>>
 {

  private ImmMap<string, WatchedResult<num>> $watchedResult;

  public function __construct(
    Traversable<Pair<string, WatchedResult<num>>> $results = [],
  ) {
    $this->watchedResult = ImmMap::fromItems($results);
  }

  <<__Memoize>>
  public function value(): ImmMap<string, WatchedResult<num>> {
    return $this->toImmMap();
  }

  public function mapWithKey<Tu>(
    (function(string, WatchedResult<num>): Tu) $mapper,
  ): ImmMap<string, Tu> {
    return $this->watchedResult->mapWithKey($mapper);
  }

  public function map<Tu>(
    (function(WatchedResult<num>): Tu) $mapper,
  ): ImmMap<string, Tu> {
    return $this->watchedResult->map($mapper);
  }

  public function merge(this $target): this {
    $result = Vector {};
    $result->addAll($this->items());
    $result->addAll($target->items());

    return new static($result->values());
  }

  public function contains<Tu super string>(Tu $m): bool {
    return $this->watchedResult->contains($m);
  }

  public function at(string $k): WatchedResult<num> {
    return $this->watchedResult->at($k);
  }

  public function get(string $k): ?WatchedResult<num> {
    return $this->watchedResult->get($k);
  }

  public function containsKey<Tu super string>(Tu $k): bool {
    return $this->watchedResult->containsKey($k);
  }

  public function items(): Iterable<Pair<string, WatchedResult<num>>> {
    return $this->watchedResult->items();
  }

  public function toImmMap(): ImmMap<string, WatchedResult<num>> {
    return $this->watchedResult;
  }

  public function __toString(): string {
    $values = $this->map(($value) ==> (string) $value)->toValuesArray();
    return \implode(', ', $values);
  }

  public static function fromItems(
    Traversable<Pair<string, WatchedResult<num>>> $results = [],
  ): this {
    return new static($results);
  }

}
