#include <stdio.h>
#include <direct.h>
#include "path_setting.h"

/**
 * ファイルを保存するdataディレクトリを作成
 * dataディレクトリがなければ新規作成
 * すでにdataディレクトリが存在していれば何もしない
**/
char genDataDirectory(void){
    if (mkdir(DATADIR_PATH) == 0){
        printf("新たにディレクトリを作成しました\n");
        return 1;
    }else{
        printf("すでにディレクトリが存在します\n");
        return 0;
    }
}


/**
 * filenameに基づいて、ファイルの相対パスを格納する文字列をfile_pathに格納する
**/
void createFilePath(char *file_path, char *filename){
    strcpy(file_path, DATADIR_PATH);
    strcat(file_path, filename);
}
