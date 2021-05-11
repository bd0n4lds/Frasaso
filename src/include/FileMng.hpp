/**
 * @file FileMng.hpp
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

#ifndef FILEMNG_H_
#define FILEMNG_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileMng {

public:
  FileMng();
  ~FileMng();
  int32_t getFileSize() const;
  int32_t readFile(const std::string &filename, std::string *contents);
  int32_t writeFile(const std::string &filename, const std::string &contents);
  int isFileExists(char *FileName);
  int addSufixToFileName(char *FileName, char *sufix);
  int renameFile(char *oldName, char *newName);
  int moveToPosFromBegin(FILE *hf, long lMove);
  char *makeFileName(char *FullFileName, char *DirName, char *FileName,
                     char *ext);
  char *getExtension(char *fileName, char *ext);
  FILE *openFile(char *FileName, int mode);
  int closeFile(FILE* hf);
  int GetWorkDir(char* WorkDir);

private:

};
#endif // FILEMNG_H_
