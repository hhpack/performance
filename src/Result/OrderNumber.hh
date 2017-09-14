<?hh //strict

/**
 * This file is part of hhpack/performance.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Performance\Result;

use HHPack\Performance\WatchedResult;

final class OrderNumber extends NumberResult<int>
  implements WatchedResult<int> {

  public function __toString(): string {
    return (string) $this->value();
  }

}
