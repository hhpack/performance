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

use HHPack\Performance\Result\BenchmarkedResult;

interface ResultReporter {
  public function onStop(BenchmarkedResult $result): void;
  public function onFinish(): void;
}
