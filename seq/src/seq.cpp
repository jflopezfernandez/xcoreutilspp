
/**
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

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
} // namespace IO

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
        std::cout << Program::AuthorName << " <" << Program::AuthorEmail << ">" << IO::endl;
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
