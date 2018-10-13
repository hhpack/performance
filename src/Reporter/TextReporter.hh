<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Reporter;

use HHPack\Performance\{Writer, WatchedResult};
use HHPack\Performance\{ResultReporter};
use HHPack\Performance\Result\{BenchmarkedResult};
use HHPack\Performance\Writer\{StdoutWriter};

final class TextReporter implements ResultReporter {

  private Vector<ImmMap<string, string>> $results;
  private Map<string, int> $paddingLength;

  public function __construct(
    private Writer<void> $writer = new StdoutWriter(),
  ) {
    $this->results = Vector {};
    $this->paddingLength = Map {};
  }

  public function onStop(BenchmarkedResult $result): void {
    $watchedResult = $result->mapToString();

    foreach ($watchedResult as $key => $value) {
      $length = \strlen((string)$value);
      $paddingLength = $this->paddingLength->get($key);
      $paddingLength = ($paddingLength === null) ? 0 : $paddingLength;
      $this->paddingLength
        ->set($key, ($length > $paddingLength) ? $length : $paddingLength);
    }

    $this->results->add($watchedResult);
  }

  public function onFinish(): void {
    $this->writeHeader();
    $this->writeBody();
    $this->writeFooter();
  }

  <<__Memoize>>
  private function header(): string {
    $this->paddingLength = $this->paddingLength
      ->mapWithKey(
        ($key, $value) ==> {
          return \strlen($key) <= $value ? $value : \strlen($key);
        },
      );

    $columns = $this->paddingLength
      ->mapWithKey(
        ($key, $value) ==> {
          return \str_pad($key, $value, ' ', \STR_PAD_RIGHT);
        },
      )
      ->values()
      ->toArray();

    return '| '.\implode(' | ', $columns).' |';
  }

  private function writeHeader(): void {
    $headerLength = \strlen($this->header());
    $headerSeparator = \str_pad('', $headerLength, '-');

    $this->writer->writeln($headerSeparator);
    $this->writer->writeln($this->header());
    $this->writer->writeln($headerSeparator);
  }

  private function writeBody(): void {
    foreach ($this->results as $result) {
      $columns = $result->mapWithKey(
        ($key, $value) ==> {
          $max = $this->paddingLength->at($key);
          return \str_pad($value, $max, ' ', \STR_PAD_LEFT);
        },
      )
        ->values()
        ->toArray();
      $this->writer->writeln('| '.\implode(' | ', $columns).' |');
    }
  }

  private function writeFooter(): void {
    $headerLength = \strlen($this->header());
    $headerSeparator = \str_pad('', $headerLength, '-');
    $this->writer->writeln(\str_pad('', $headerLength, '-'));
  }

}
