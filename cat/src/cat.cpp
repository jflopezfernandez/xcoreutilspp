
/** cat - Concatenate files and print on the standard output.
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
 *  Originally written by Torbjorn Granlund, advised by Dr. Richard Stallman.
 *  Rewritten in C++ by Jose Fernando Lopez Fernandez.
 * 
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

#include <boost/program_options.hpp>

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

namespace Opts = boost::program_options;

template <typename T, size_t N>
struct Array
{
    size_t size = N;
    T data[N];
};

int main(int argc, char *argv[])
{
    Array<int, 5> arr = { 1, 2, 3, 4, 5 };

    for (auto i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i] << IO::endl;
    }

    return EXIT_SUCCESS;
}
