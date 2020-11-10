/**
 * @file main.cpp
 * @author Brian Donaldson <vuejs@johndoe.anonaddy.com>
 * @version 1.0.2020-10-01
 *
 * @section DESCRIPTION
 *
 * Implementation of the parser. For Details see header.
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License and a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <iostream>

#include "include/cxxopts.hpp"

cxxopts::ParseResult parse_options(cxxopts::Options& options, int& argc, char* argv[]) 
{
    options.add_options()
        ("-d, --debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
        ("-o, --output", "Output file", cxxopts::value<std::string>()->default_value("output.txt")->implicit_value("b.def"), "BIN")
        ("-p, --pinpad", "PINpad")
        ("-f, --file", "File", cxxopts::value<std::vector<std::string>>(), "FILE")
        ("-h, --help", "-?")
        ("-v, --version", "--show-version");

    options.custom_help("[-h] [-d] [-f FILE]");

    try 
    {
        cxxopts::ParseResult options_result = options.parse(argc, argv);

        if (options_result.count("help"))
        {
            std::cout << options.help() << std::endl;
            exit(0);
        }

        return options_result;
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    cxxopts::Options options(argv[0], "");
    cxxopts::ParseResult options_result = parse_options(options, argc, argv);

    return 0;
}