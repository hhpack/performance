<?hh //strict

/**
 * This file is part of hhpack\stopwatch.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\stopwatch;

interface NamedWatcher<T> extends Watcher<T>
{
    public function name() : string;
}
