#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <cctype>
#include <algorithm>
#define lson o<<1, l, m
#define rson o<<1|1, m+1, r
using namespace std;
typedef long long LL;
const int maxn = 500500;
const int MAX = 0x3f3f3f3f;
int n, a, b, in[maxn], tt[maxn], fu[maxn], f[maxn];
LL num[maxn<<2];
int bs(int v, int x, int y)
{
	while(x < y)
	{
		int m = (x+y) >> 1;
		if(fu[m] >= v) y = m;
		else x = m+1;
	}
	return x;
}
void up(int o)
{
	num[o] = num[o<<1] + num[o<<1|1];
}
void build(int o, int l, int r)
{
	num[o] = 0;
	if(l == r) return ;
	int m = (l+r) >> 1;
	build(lson);
	build(rson);
}
void update(int o, int l, int r)
{
	if(l == r)
	{
		num[o]++;
		return ;
	}
	int m = (l+r) >> 1;
	if(a <= m) update(lson);
	else update(rson);
	up(o);
}
LL query(int o, int l, int r)
{
	if(a <= l && r <= b) return num[o];
	int m = (l+r) >> 1;
	LL ans = 0;
	if(a <= m) ans += query(lson);
	if(m < b ) ans += query(rson);
	return ans ;
}
int main()
{
	while(cin >> n, n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &in[i]);
			tt[i] = in[i];  //tt记录原序列
		}
		sort(in, in+n);
		int k = 0;
		fu[k++] = in[0];   //fu为辅助数组
		for(int i = 1; i < n; i++)
			if(in[i] != in[i-1]) fu[k++] = in[i];
		b = 0;
		for(int i = 0; i < n; i++)    //离散过程，二分
		{
			f[i] = bs(tt[i], 0, k-1);
			b = max(b, f[i]);
		}
		LL ans = 0;
		build(1, 0, b);
		for(int i = 0; i < n; i++)
		{
			a = f[i] + 1;    // 查询f[i]+1~n的个数，个数就是f[i]当前的逆序对总数
			ans += query(1, 0, b);
			a = f[i];  // 将f[i]添加到数组中
			update(1, 0, b);
		}
		cout << ans << endl;
	}
	return 0;
}
