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

#include <cerrno>
#include <cstring>

#include "openhft/affinity.hpp"
#include "openhft/exceptions.hpp"

namespace openhft {

// *****************************************************************************
//
// *****************************************************************************

Affinity& Affinity::get()
{
    static Affinity instance;
    return instance;
}

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
    std::int32_t rv = sched_getcpu();
    if(rv == -1)
    {
        throw IllegalStateException(std::strerror(errno));        
    }

    return rv;
}

std::int32_t Affinity::getProcessId()
{
    return getpid();
}

std::int32_t Affinity::getThreadId()
{
    std::int32_t rv = syscall(SYS_gettid);
    if(rv == -1)
    {
        throw IllegalStateException(std::strerror(errno));        
    }

    return rv;
}

std::int64_t Affinity::getAffinity()
{
    cpu_set_t mask;
    CPU_ZERO(&mask);

    std::int32_t rv = sched_getaffinity(0, sizeof(cpu_set_t), &mask);
    if(rv == -1)
    {
        throw IllegalStateException(std::strerror(errno));        
    }

    return rv;
}

void Affinity::setAffinity(std::int64_t affinity)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(affinity, &mask);

    std::int32_t rv = sched_setaffinity(0, sizeof(cpu_set_t), &mask);
    if(rv == -1)
    {
        throw IllegalStateException(std::strerror(errno));        
    }
}

#endif // OS_LINUX

} // namespace openhft
