performance
========================================

[![Latest Stable Version](https://poser.pugx.org/hhpack/performance/v/stable)](https://packagist.org/packages/hhpack/performance)
[![Build Status](https://travis-ci.org/hhpack/performance.svg?branch=master)](https://travis-ci.org/hhpack/performance)
[![Dependency Status](https://www.versioneye.com/user/projects/569b4a0fed08610040000043/badge.svg?style=flat)](https://www.versioneye.com/user/projects/569b4a0fed08610040000043)
[![License](https://poser.pugx.org/hhpack/performance/license)](https://packagist.org/packages/hhpack/performance)

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
