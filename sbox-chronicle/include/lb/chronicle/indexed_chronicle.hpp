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

#ifndef __LB_INDEXED_CHRONICLE_HPP__
#define __LB_INDEXED_CHRONICLE_HPP__

#include "lb/chronicle/chronicle.hpp"

namespace lb {
namespace chronicle {

class IndexedChronicle
    : public Chronicle
{
public:
    IndexedChronicle();
    virtual ~IndexedChronicle();

    virtual void close();
};

} // namespace chronicle
} // namespace lb

#endif