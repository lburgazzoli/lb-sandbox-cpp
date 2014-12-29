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

#ifndef INCLUDED_LB_CHRONICLE_AFFINITY_HPP__
#define INCLUDED_LB_CHRONICLE_AFFINITY_HPP__

#include <cstdint>

namespace lb {
namespace chronicle {

class Affinity
{
public:
    std::int64_t getAffinity();
    void setAffinity(std::int64_t affinity);

    std::int32_t getCpu();
    std::int32_t getProcessId();
    std::int32_t getThreadId();
};

} // namespace chronicle
} // namespace lb

#ifdef OS_LINUX
#include "lb/chronicle/affinity_linux.hpp"
#endif

#endif // INCLUDED_LB_CHRONICLE_AFFINITY_HPP__
