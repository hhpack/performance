<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance;

interface BenchmarkRunner<T> {
  public function times(int $times): this;
  public function reporter(ResultReporter $reporter): this;
  public function run((function(): T) $callback): T;
}
