
/** xcoreutils - io.h
 *
 *  Copyright (C) 1988-2019 Free Software Foundation, Inc.
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *  Originally written by Jose Fernando Lopez Fernandez <jflopezfernandez@gmail.com>.
 * 
 */

#ifndef XCOREUTILS_INCLUDES_IO_H_
#define XCOREUTILS_INCLUDES_IO_H_

#include <iostream>

namespace IO
{
    /** @fn IO::endl
     *
     *  @brief The standard library's std::endl does two things: it outputs a
     *  new line and then it calls std::fflush(), flushing the output buffer.
     *  This is not always ideal, so this function replaces the std::endl
     *  function with IO::endl, which is similar in every way, except it does
     *  not call std::fflush().
     *
     *  Credit for this function goes to Dietmar Kuhl, who wrote about the
     *  common misuse of std::endl on his website, linked below.
     *
     *  @author Dietmar Kuhl
     *  @date January 14, 2012
     *  @link https://kuhllib.com/2012/01/14/stop-excessive-use-of-stdendl/
     *
     */
    template <typename CharT, typename T = std::char_traits<CharT>>
    std::basic_ostream<CharT, T>&
    endl(std::basic_ostream<CharT, T>& outputStream)
    {
        return outputStream << outputStream.widen('\n');
    }
} // namespace

#endif // XCOREUTILS_INCLUDES_IO_H_
