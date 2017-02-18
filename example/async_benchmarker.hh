<?hh //partial

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Example;

require_once __DIR__ . '/../vendor/autoload.php';

use HHPack\Performance as bench;

async function async_benchmarker_main() : Awaitable<void>
{
    await bench\async()->times(10)->run(async () ==> {
        await \HH\Asio\usleep(2000);
    });
}

\HH\Asio\join(async_benchmarker_main());
