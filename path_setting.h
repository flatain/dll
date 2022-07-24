#ifndef _PATH_SETTING_H_
#define _PATH_SETTING_H_

#include <string.h>

#define PATH_SIZE 256

#define DATADIR_PATH "./data/"

char genDataDirectory(void);
void createFilePath(char *file_path, char *filename);
void printFileData(char *filename);

#endif
