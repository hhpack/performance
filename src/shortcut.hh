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

use hhpack\performance\reporter\TextReporter;
use hhpack\performance\generator\DefaultGenerator;

function async() : AsyncBenchmarker
{
    return new AsyncBenchmarker(
        new DefaultGenerator(),
        new TextReporter()
    );
}

function sync() : Benchmarker
{
    return new Benchmarker(
        new DefaultGenerator(),
        new TextReporter()
    );
}
