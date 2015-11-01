stopwatch
========================================

[![Latest Stable Version](https://poser.pugx.org/hhpack/stopwatch/v/stable)](https://packagist.org/packages/hhpack/stopwatch)
[![Build Status](https://travis-ci.org/hhpack/stopwatch.svg?branch=master)](https://travis-ci.org/hhpack/stopwatch)
[![Dependency Status](https://www.versioneye.com/user/projects/5635c29f36d0ab0019001d2a/badge.svg?style=flat)](https://www.versioneye.com/user/projects/5635c29f36d0ab0019001d2a)
[![License](https://poser.pugx.org/hhpack/stopwatch/license)](https://packagist.org/packages/hhpack/stopwatch)

Basic usage
------------------------------------------------

You can measure the time of easy processing.

```hack
use hhpack\stopwatch\StopWatch;

$stopWatch = new StopWatch();
$stopWatch->start();
$stopWatch->stop();

$result = $stopWatch->getResult();

echo $result;
```

Run the test
------------------------------------------------

You can run the test with the following command.

	composer install
	composer test
