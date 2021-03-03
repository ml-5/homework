#include <iostream>
using namespace std;
const int MAX = 2e3 + 10;
int N;
char S[MAX + 1];
void solve()
{
    int a = 0, b = N - 1;
    while (a <= b)
    {
        bool left = false;
        for (int i = 0; a + i <= b; i++)
        {
            if (S[a + i] < S[b - i])
            {
                left = true;
                break;
            }
            else if (S[a + i] > S[b - i])
            {
                left = false;
                break;
            }
        }
        if (left)
            putchar(S[a++]);
        else
            putchar(S[b--]);
    }
    putchar("\n");
}