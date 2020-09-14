#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int Position;
#define NOtFound -1
void BulidMatch(char *pattern, int *match)
{

    Position i, j;
    int m = strlen(pattern);
    macth[0] = -1;
    for (j = 1; j < m; j++)
    {
        i = match[j - 1];
        while (i >= 0 && pattern[i + 1] != pattern[j])
            i = macth[i];
        if (pattern[i + 1] == pattern[j])
            match[j] = i + 1;
        else
            match[j] = -1;
    }
}
Position Kmp(char *string, char *pattern)
{

    int n = strlen(string);  //文本长度
    int m = strlen(pattern); //目标长度
    Position s, p, *match;
    if (n < m)
        return NOtFound;
    match = (Position *)malloc(sizeof(Position) * m);
    BulidMatch(pattern, match); //建立match函数
    s = p = 0;
    while (s < n && p < m)
    {
        if (string[s] == pattern[p])
        {
            s++;
            p++;
        }
        else if (p > 0)
            p = match[p - 1] + 1;
        else
            s++;
    }
    return (p == m) ? (s - m) : NOtFound;
}
int main()
{
    char string[] = "This is a simple example.";
    char pattern[] = "simple";
    Position p = KMP(string, pattern);
    if (p == NotFound)
        printf("Not Found.\n");
    else
        printf("%s\n", string + p);
    return 0;
}