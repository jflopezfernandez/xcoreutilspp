
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


int main(int argc, char *argv[])
{
    std::cout << "[cat executed...]" << std::endl;

    return 0;
}
