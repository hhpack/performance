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

async function benchmark((function():Awaitable<void>) $callback) : Awaitable<void>
{
    $bechmarker = new BenchMarker(new TextReporter());
    $bechmarker->start();

    await $callback();

    $bechmarker->stop();
}
