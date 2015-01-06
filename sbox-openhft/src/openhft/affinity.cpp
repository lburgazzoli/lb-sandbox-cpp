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

#include "openhft/affinity.hpp"

namespace openhft {

// *****************************************************************************
// LINUX
// *****************************************************************************

#ifdef OS_LINUX

#include <sched.h>
#include <unistd.h>
#include <signal.h>
#include <sys/syscall.h>
#include <sys/types.h>

std::int32_t Affinity::getCpu()
{
    return sched_getcpu();
}

std::int32_t Affinity::getProcessId()
{
    return getpid();
}

std::int32_t Affinity::getThreadId()
{
    return syscall(SYS_gettid);
}

std::int64_t Affinity::getAffinity()
{
    cpu_set_t mask;
    CPU_ZERO(&mask);

    return sched_getaffinity(0, sizeof(cpu_set_t), &mask);
}

void Affinity::setAffinity(std::int64_t affinity)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(affinity, &mask);

    sched_setaffinity(0, sizeof(cpu_set_t), &mask);
}

#endif // OS_LINUX

} // namespace openhft
