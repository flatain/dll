
#include <stdio.h>
#include "path_setting.h"

// サンプル用プログラムだからマクロはテスト用ソースファイルに記述
#define BUF_WRITE_SIZE 5
#define BUF_READ_SIZE  10
#define BYTE_UNIT    1

int main(void){
    //使いたいファイル名の定義
    char *filename  = "sample_bin.txt";

    //exeファイルから出力するファイルまでの相対パスを格納する文字配列の定義
    char filepath[PATH_SIZE] = "";

    //出力するデータ
    char buf_write[BUF_WRITE_SIZE] = {'a', 'b', 'c', 'x', 'y'};
    char buf_read[BUF_READ_SIZE];

    FILE *fp_write  = NULL;
    FILE *fp_read   = NULL;

    int num_read    = 0;

    // dataディレクトリ作成
    genDataDirectory();

    // filenameに基づいて相対パスを作成し、filepathに格納
    createFilePath(filepath, filename);

    // filepathを利用してファイルに書き込む
    fp_write = fopen(filepath, "wb");

    if(fp_write == NULL){
        return 1;
    }else{
        //処理なし
    }

    fwrite(buf_write, BYTE_UNIT, BUF_WRITE_SIZE, fp_write);
    fclose(fp_write);

    // filepathを利用してファイルを読み込む
    fp_read = fopen(filepath, "rb");

    if(fp_read == NULL){
        return 1;
    }else{
        //処理なし
    }

    // 書き込んだデータの読み込み
    num_read  = fread(buf_read, BYTE_UNIT, BUF_READ_SIZE, fp_read);
    for(int i = 0; i < num_read; i++){
        printf("buf_read[%d] = %c\n", i, buf_read[i]);
    }
    fclose(fp_read);

}
