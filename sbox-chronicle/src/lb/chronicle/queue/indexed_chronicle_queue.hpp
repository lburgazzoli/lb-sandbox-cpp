/*
 * Copyright 2014 lb
 *
 * https://lburgazzoli.github.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef INCLUDED_LB_INDEXED_CHRONICLE_QUEUE_HPP__
#define INCLUDED_LB_INDEXED_CHRONICLE_QUEUE_HPP__

#include "lb/chronicle/queue/chronicle_queue.hpp"

namespace lb {
namespace chronicle {
namespace queue {

class IndexedChronicleQueue
    : public ChronicleQueue
{
public:
    IndexedChronicleQueue();
    virtual ~IndexedChronicleQueue();

    virtual void close();
};

} // namespace queue
} // namespace chronicle
} // namespace lb

#endif // INCLUDED_LB_INDEXED_CHRONICLE_QUEUE_HPP__