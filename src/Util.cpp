/**
 * @file Util.cpp
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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/Util.hpp"

/// <summary>
/// 
/// </summary>

Util::Util() 
{

}

/// <summary>
/// 
/// </summary>

Util::~Util() 
{

}

/// <summary>
/// 
/// </summary>
/// <param name="str"></param>

void Util::trim(std::string &str) 
{
 
    while (!str.empty() && str[0] == ' ') 
    {
        str.erase(0, 1);
    }

    while (!str.empty() && str[str.size() - 1] == ' ') 
    {
        str.erase(str.size() - 1, 1);
    }
}

/// <summary>
/// 
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>

bool Util::isWhitespace(char ch)
{
    return ch == ' ' || ch == '\t';
}

/// <summary>
/// 
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>

bool Util::isAlpha(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

/// <summary>
/// 
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>

bool  Util::isNumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

/// <summary>
/// 
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>

bool Util::isSpecial(const char ch)
{
    bool special = false;

    if ((ch > ' ' && ch < '0') || (ch > '9' && ch < 'A'))
    {
        special = true;
    }
    if ((ch > 'Z' && ch < 'a') || (ch > 'z' && ch <= '~'))
    {
        special = true;
    }
    return special;
}

/// <summary>
/// 
/// </summary>
/// <param name="c"></param>
/// <returns></returns>

bool  Util::isCRLF(const char ch)
{
    return (ch == '\n');
}

/// <summary>
/// 
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>

bool Util::isTab(const char ch)
{
    return (ch == '\t');
}

/// <summary>
/// 
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>

bool Util::isTerminator(const char ch)
{
    return (isSeparator(ch) || (ch == '\n') || (ch == '\r'));
}

bool Util::isSeparator(const char ch)
{
    return (ch == m_separator);
}

/// <summary>
/// 
/// </summary>
/// <param name="st"></param>
/// <returns></returns>

std::string& Util::toLower(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    return str;
}
