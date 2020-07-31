#include <stdio.h>
int main()
{
    int i, index, k, n, temp;
    int a[10];
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (k = 0; k < 10 - 1; k++)
    {
        index = k;
        for (i = k + 1; i < 10; i++)
        {
            if (a[i] < a[index])
            {
                index = i;
            }
        }
        if (k != index)
        {
            temp = a[index];
            a[index] = a[k];
            a[k] = temp;
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
}