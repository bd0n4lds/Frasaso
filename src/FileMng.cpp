/**
 * @file FileMng.cpp
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

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <direct.h> 
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "include/FileMng.hpp"

/// <summary>
///
/// </summary>
///

FileMng::FileMng() {}

/// <summary>
///
/// </summary>
///

FileMng::~FileMng() {}

/// <summary>
///
/// </summary>
///

int FileMng::getFileSize() const { return 0; }

/// <summary>
///
/// </summary>
///

int32_t FileMng::readFile(const std::string &filename, std::string *contents) {
  FILE *fp;
  ssize_t read = 0;
  char *line = NULL;
  size_t len = 0;

  fp = fopen(filename.c_str(), "r");
  if (fp != NULL) {
    if ((read = getline(&line, &len, fp)) != -1) {
      char *pos;
      if ((pos = strchr(line, '\n')) != NULL)
        *pos = '\0';
      *contents = line;
    }
    free(line);
    fclose(fp);
    return 0;
  } else {
    ALOGE("fopen failed");
  }

  return -1;
}

/// <summary>
///
/// </summary>
///

int32_t FileMng::writeFile(const std::string &filename,
                           const std::string &contents) {
  FILE *fp;
  std::string written;

  fp = fopen(filename.c_str(), "w");
  if (fp != NULL) {
    // FAILURE RETRY
    int ret = fputs(contents.c_str(), fp);
    fclose(fp);
    if ((ret != EOF) && !readFile(filename, &written) && written == contents)
      return 0;
  }
  return -1;
}

/// <summary>
///
/// </summary>
///

int FileMng::isFileExists(char *FileName) {
  FILE *hf;

  hf = fopen(FileName, "rb");
  if (hf) {
    closeFile(hf);
    return 1;
  }
  return 0;
}

/// <summary>
///
/// </summary>
///

int FileMng::addSufixToFileName(char* FileName, char* sufix)
{
    return 0;
}

/// <summary>
///
/// </summary>
///

int FileMng::renameFile(char* oldName, char* newName)
{
    return 0;
}

/// <summary>
///
/// </summary>
///

int FileMng::moveToPosFromBegin(FILE* hf, long lMove)
{
    return 0;
}

/// <summary>
///
/// </summary>
/// 

char* FileMng::makeFileName(char* FullFileName, char* DirName, char* FileName, char* ext)
{
    return nullptr;
}

/// <summary>
///
/// </summary>
/// 

char* FileMng::getExtension(char* fileName, char* ext)
{
    return nullptr;
}

/// <summary>
///
/// </summary>
/// 

FILE* FileMng::openFile(char* FileName, int mode)
{
    return nullptr;
}

/// <summary>
///
/// </summary>
/// 

int FileMng::closeFile(FILE *hf) { return fclose(hf); }

/// <summary>
///
/// </summary>
/// 

int FileMng::GetWorkDir(char* WorkDir)
{
    _getcwd(WorkDir, 256);
#ifndef WINUX_DEV
    if (WorkDir[strlen(WorkDir) - 1] != '/')
        strcat(WorkDir, "/");
#else  //#ifndef WINUX_DEV
    if (WorkDir[strlen(WorkDir) - 1] != '\\')
        strcat(WorkDir, "\\");
#endif //#ifndef WINUX_DEV
    return 1;
}
