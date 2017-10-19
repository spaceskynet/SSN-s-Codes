#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 2100;

int ans[Maxn][Maxn], n[Maxn * 10], m[Maxn * 10], lim, t, k, lim2;
int C[Maxn][Maxn];

int main()
{
	scanf("%d%d", &t, &k);
	for(int i = 1; i <= t; ++i)
	{
		scanf("%d%d", &n[i], &m[i]);
		lim = max(lim, n[i]);
		lim2 = max(lim2, m[i]);
	}
	int temp = 0;
	for(int i = 0; i <= lim; ++i)
	{
		int temp = 0;
		for(int j = 0; j <= i; ++j)
		{
			if(j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
			temp += (C[i][j] == 0);
			ans[i][j] = ans[i - 1][j] + temp;
		}
		for(int j = i + 1; j <= lim2; ++j) ans[i][j] = ans[i - 1][j] + temp;
	}
	for(int i = 1; i <= t; ++i)
	{
		printf("%d\n", ans[n[i]][m[i]]);
	}
	// for(;;);
	return 0;
}

