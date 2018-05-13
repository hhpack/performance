<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Writer;

use HHPack\Performance\Writer;

final class BufferedWriter implements Writer<void> {

  private string $content = '';

  public function write(string $value): void {
    $this->content .= $value;
  }

  public function writeln(string $value): void {
    $this->content .= $value.\PHP_EOL;
  }

  public function __toString(): string {
    return $this->content;
  }

}
