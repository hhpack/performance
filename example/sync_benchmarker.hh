<?hh //partial

/**
 * This file is part of hhpack\performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\performance\example;

require_once __DIR__ . '/../vendor/hh_autoload.php';

use hhpack\performance as bench;

function sync_benchmarker() : void
{
    bench\sync()->times(10)->run(() ==> {
        usleep(2000);
    });
}
sync_benchmarker();
