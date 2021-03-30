#include <stdio.h>
#include <algorithm>
int a[3000];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	std::sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1, k = j + 1; j < n; j++)
		{
			while (k < n && a[k] < a[i] + a[j])
				k++;
			ans += k - j - 1;
		}
	}
	printf("%lld", ans);
}