// Word Count.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
#include<string.h>

int main()
{
    char s;
    int i;
    char input[100];
    char txt[100];
    gets_s(input);
    s = input[1];
    int lenth = strlen(input);
    for (i = 3;i < lenth;i++)
    {
        txt[i - 3] = input[i];
    }
    txt[i - 3] = '\0';
    errno_t errnot;
    FILE* fp;
    char buffer[256] = { 0 };
    errnot = fopen_s(&fp, txt, "r");
    if (errnot != 0)
    {
        printf("文件打开失败");
    }
    else {
        fread(buffer, sizeof(buffer), 1, fp);
        int bd = 0, zf = 0, hc = 0;
        for (i = 0;i < strlen(buffer);i++)
        {
            char ch = buffer[i];
            if (ch == '\n')
                hc++;
            if (ch == ' ' || ch == '\n' || ch == '\t')
                zf++;
            if (ch == ' ' || ch == ',' || ch == '.')
                bd++;
        }
        int dc = zf - hc;
        if (s == 'c')
            printf("字符数为: %d\n", zf);
        if (s == 'w')
            printf("单词数为：%d\n", dc);
        fclose(fp);
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
