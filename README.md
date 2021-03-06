# performance

[![Latest Stable Version](https://poser.pugx.org/hhpack/performance/v/stable)](https://packagist.org/packages/hhpack/performance)
[![Build Status](https://travis-ci.org/hhpack/performance.svg?branch=master)](https://travis-ci.org/hhpack/performance)
[![Dependency Status](https://www.versioneye.com/user/projects/569b4a0fed08610040000043/badge.svg?style=flat)](https://www.versioneye.com/user/projects/569b4a0fed08610040000043)
[![License](https://poser.pugx.org/hhpack/performance/license)](https://packagist.org/packages/hhpack/performance)

![Screen Shot](https://raw.githubusercontent.com/hhpack/performance/master/screen-shot.png)

## Basic usage

You can measure the time of easy processing.

```hack
use HHPack\Performance\PerformanceWatcher;
use HHPack\Performance\TimeWatcher;
use HHPack\Performance\MemoryWatcher;
use HHPack\Performance\Result\WatchedResult;

$watcher = PerformanceWatcher::fromItems([
    Pair { 'time', new TimeWatcher() },
    Pair { 'memory', new MemoryWatcher() }
]);

$watcher->start();
$watcher->stop();

$texts = $watcher->result()->mapWithKey(($key, $result) ==> {
    return sprintf("%s: %s", $key, (string) $result->value());
})->values();

foreach ($texts as $text) {
    echo $text, PHP_EOL;
}
```

## Benchmark

```hack
use HHPack\Performance as bench;

function sync_benchmarker() : void
{
    bench\sync()->times(10)->run(() ==> {
        usleep(2000);
    });
}
sync_benchmarker();
```

or

```hack
use HHPack\Performance as bench;

async function async_benchmarker_main() : Awaitable<void>
{
    await bench\async()->times(10)->run(async () ==> {
        await \HH\Asio\usleep(2000);
    });
}

\HH\Asio\join(async_benchmarker_main());
```

## Run the test

You can run the test with the following command.

	composer install
	composer test
