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
    bool inWord = false; // ����Ƿ���һ��������

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found or unable to open the input file.\n");
        exit(1);
    }

    // �����ȡ�ļ��е��ַ���ͳ���ַ����͵�����
    while ((ch = fgetc(file)) != EOF) {
        charCount++; // ͳ���ַ���

        // �ж��Ƿ�Ϊ�ָ������ո�򶺺ţ�
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            if (inWord) {
                inWord = false; // ��ǵ�ǰ���ڵ�����
            }
        }
        else {
            if (!inWord) {
                wordCount++; // ���ӵ�����Ŀ
                inWord = true; // ��ǵ�ǰ�ڵ�����
            }
        }
    }

    fclose(file); // �ر��ļ�

    // ���ͳ�ƽ��
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);

    return 0;
}