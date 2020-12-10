/**
 * @file Parser.cpp
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

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/Parser.hpp"

/// <summary>
///
/// </summary>
///

Parser::Parser() : 
    m_isFileLoaded(false)
{
}

/// <summary>
///
/// </summary>
///

Parser::~Parser()
{
}

/// <summary>
///
/// </summary>
///

bool Parser::isFileLoaded()
{
    return m_isFileLoaded;
}

/// <summary>
///
/// </summary>
/// 

bool Parser::parseFile()
{
    return false;
}

/// <summary>
///
/// </summary>
///

bool Parser::reparse()
{
    return false;
}


/// <summary>
///
/// </summary>
///

void Parser::openDb(const std::string& filename)
{//open log file and set up new DB if needed
    file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "[-]ERROR: Can't open the file";
        exit(-1);
    }

    //set position to 1 because first line in the log file is always empty
    file->seek(1);

    //return from function if dbase already exists
    if (dbase.isOpen())
        return;

    //create new database
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open())
    {
        qDebug() << "[-]ERROR: Can't open the database";
        exit(-1);
    }

    //create new table in dbase
    QSqlQuery a_query;
    QString str = "CREATE TABLE my_table ("
        "logID VARCHAR(255), "
        "tag VARCHAR(255), "
        "value VARCHAR(255)"
        ");";
    bool b = a_query.exec(str);
    if (!b)
        qDebug() << "Can't create table/table has already been created";

    return;
}

/// <summary>
///
/// </summary>
///

void Parser::parsFile()
{//separate each log in a file and parse them in PasrMsg()
    QVector<QString>data(0);
    QString line;
    QTextStream in(file);

    //Read until the end of file
    while (!in.atEnd())
    {//if we have empty line, means we reached end of the log
        line = in.readLine();
        if (line != "\0")
        {
            data.push_back(line);
        }
        else
        {
            data.back().append(";");
            parsMsg(data);
            data.clear();
        }
    }
    data.back().append(";");
    parsMsg(data);

    return;
}
