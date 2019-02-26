
/** seq - Print sequence of numbers to standard output.
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
 *  Originally written by Ulrich Drepper. Rewritten in C++ by
 *  Jose Fernando Lopez Fernandez.
 * 
 */

#include "xcoreutils.h"

namespace Program
{
    const auto Name = "seq";
    const auto AuthorName = "Jose Fernando Lopez Fernandez";
    const auto AuthorEmail = "jflopezfernandez@gmail.com";
    const auto Version = "0.1.0";

    void PrintVersion()
    {
        std::cout << Program::Name << " (Version " << Program::Version << ")" << IO::endl;
        std::cout << "This program is a C++ rewrite of the original GNU coreutils" << IO::endl;
        std::cout << "seq program written by Ulrich Drepper, by " << IO::endl;
        std::cout << Program::AuthorName << " <" << Program::AuthorEmail << ">\n" << IO::endl;
        std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details " << IO::endl;
        std::cout << "type `show w'. This is free software, and you are welcome to " << IO::endl;
        std::cout << "redistribute it under certain conditions; type `show c' " << IO::endl;
        std::cout << "for details." << IO::endl;
    }
} // namespace Program

namespace Opts = boost::program_options;

int main(int argc, char *argv[])
{
    Opts::options_description OptionsDescription("Program Options");
    
    OptionsDescription.add_options()
        ( "first", Opts::value<int>()->default_value(1), "Start value" )
        ( "last", Opts::value<int>(), "End value" )
        ( "increment", Opts::value<int>()->default_value(1), "The value to increment by" )
        /* TODO: ( "format,f", "Use printf style floating-point FORMAT" )*/
        /* TODO: ( "separator,s", "Use STRING to separate numbers (default: \\n)" )*/
        /* TODO: ( "equal-width,w", "Equalize width by padding with leading zeroes" )*/
        ( "help", "Display this help message" )
        ( "version", "Display program version" )
    ;

    Opts::positional_options_description PositionalOptions;
    PositionalOptions.add("last", -1);
    
    Opts::variables_map InputMap;
    Opts::store(Opts::command_line_parser(argc, argv)
        .options(OptionsDescription)
        .positional(PositionalOptions)
        .run(), InputMap);
    Opts::notify(InputMap);

    if (InputMap.count("help"))
    {
        std::cout << OptionsDescription << IO::endl;

        return EXIT_SUCCESS;
    }

    if (InputMap.count("version"))
    {
        Program::PrintVersion();

        return EXIT_SUCCESS;
    }

    if (!InputMap.count("last"))
    {
        std::cerr << "You must specify the last value of the sequence." << IO::endl;

        return EXIT_FAILURE;
    }

    const auto start = InputMap["first"].as<int>();
    const auto stop  = InputMap["last"].as<int>();
    const auto step  = InputMap["increment"].as<int>();

    for (auto i = start; i <= stop; i = i + step)
    {
        std::cout << i << IO::endl;
    }

    return EXIT_SUCCESS;
}
