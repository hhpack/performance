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

use HHPack\Performance\Reporter\TextReporter;
use HHPack\Performance\Generator\DefaultGenerator;

function async(): AsyncBenchmarker {
  return new AsyncBenchmarker(new DefaultGenerator(), new TextReporter());
}

function sync(): Benchmarker {
  return new Benchmarker(new DefaultGenerator(), new TextReporter());
}
