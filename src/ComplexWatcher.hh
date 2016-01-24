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

use hhpack\performance\result\ComplexResult;

interface ComplexWatcher<T> extends Watcher<ComplexResult>
{
    public static function fromItems(Traversable<Pair<string, Watcher<WatchedResult<T>>>> $watchers) : this;
}
