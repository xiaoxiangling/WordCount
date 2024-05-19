#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE* file;
    char filename[100];
    char ch;
    int charCount = 0;
    int wordCount = 0;
    bool inWord = false; // 标记是否在一个单词内

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found or unable to open the input file.\n");
        exit(1);
    }

    // 逐个读取文件中的字符并统计字符数和单词数
    while ((ch = fgetc(file)) != EOF) {
        charCount++; // 统计字符数

        // 判断是否为分隔符（空格或逗号）
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            if (inWord) {
                inWord = false; // 标记当前不在单词中
            }
        }
        else {
            if (!inWord) {
                wordCount++; // 增加单词数目
                inWord = true; // 标记当前在单词中
            }
        }
    }

    fclose(file); // 关闭文件

    // 输出统计结果
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);

    return 0;
}