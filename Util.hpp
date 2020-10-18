/**
 * @file Util.hpp
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

#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <map>

#include "Util.cpp"

class Util 
{

public:
	Util();
	~Util();

	void trim(std::string &str);
	bool isWhitespace(char ch);
	bool isAlpha(char ch);
	bool isNumber(char ch);
	bool isSpecial(char ch);
	std::string& toLower(std::string& st);

private:

};
#endif // UTIL_HPP
