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

class Util 
{

public:
	Util();
	~Util();

private:

	char m_separator;

	void trim(std::string& str);
	bool isAlpha(const char ch);
	bool isCRLF(const char ch);
	bool isNumber(const char ch);
	bool isSpecial(const char ch);
	bool isTab(const char ch);
	bool isTerminator(const char ch);
	bool isSeparator(const char ch);
	bool isWhitespace(const char ch);
	std::string& toLower(std::string& str);

};
#endif // UTIL_HPP
