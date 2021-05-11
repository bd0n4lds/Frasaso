/**
 * @file Parser.hpp
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

#pragma once

#ifndef PARSER_H_
#define PARSER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Parser 
{

public:
  Parser();
  ~Parser();
  bool isFileLoaded();
  bool reparse();
  void openDb(const std::string &filename);
  void parsFile();

private:
  bool m_isFileLoaded;
  bool parseFile();
};
#endif // PARSER_H_