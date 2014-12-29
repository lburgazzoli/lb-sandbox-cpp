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

#ifndef INCLUDED_LB_CHRONICLE_EXCEPTIONS_HPP__
#define INCLUDED_LB_CHRONICLE_EXCEPTIONS_HPP__

#include <string>
#include <stdexcept>

namespace lb {
namespace chronicle {

#   ifdef OS_UNIX
    #define CHRONICLE_SOURCEINFO __PRETTY_FUNCTION__, " : " __FILE__ " : " TOSTRING(__LINE__)
    #define CHRONICLE_NOEXCEPT   noexcept
#endif

// *****************************************************************************
//
// *****************************************************************************

class SourcedException 
    : public std::exception
{
private:
    std::string m_where;
    std::string m_what;

public:
    SourcedException(
        const std::string &what, 
        const std::string& function, 
        const std::string& where)
        : m_where(function + where)
        , m_what(what)
    {
    }

    virtual const char *what() const CHRONICLE_NOEXCEPT
    {
        return m_what.c_str();
    }

    const char *where() const CHRONICLE_NOEXCEPT
    {
        return m_where.c_str();
    }
};

// *****************************************************************************
//
// *****************************************************************************

#define DECLARE_SOURCED_EXCEPTION(exceptionName) \
    class exceptionName \
        : public SourcedException \
    { \
    public: \
        exceptionName ( \
            const std::string &what, \
            const std::string& function, \
            const std::string& where) \
            : SourcedException (what, function, where) \
            { \
            } \
    }

// *****************************************************************************
//
// *****************************************************************************

DECLARE_SOURCED_EXCEPTION (IOException);
DECLARE_SOURCED_EXCEPTION (FormatException);
DECLARE_SOURCED_EXCEPTION (OutOfBoundsException);
DECLARE_SOURCED_EXCEPTION (ParseException);
DECLARE_SOURCED_EXCEPTION (ElementNotFound);
DECLARE_SOURCED_EXCEPTION (IllegalArgumentException);
DECLARE_SOURCED_EXCEPTION (IllegalStateException);

} // namespace chronicle
} // namespace lb

#endif // INCLUDED_LB_CHRONICLE_EXCEPTIONS_HPP__
