#include <bits/stdc++.h>
#define M 262144

using namespace std;

typedef long long ll;

const ll P = 23068673;

const ll g = 7;

inline ll powmod(ll X, ll y = P - 2, ll Z = P)
{
	ll ans = 1;
	while(y)
	{
		if(y & 1) ans = ans * X % Z;
		X = X * X % Z;
		y >>= 1;
	}
	return ans;
}

int n, m, S, tot, Rev[M];

ll A[M], B[M], T[M], Mut;

void NTT(ll *A)
{
	for(int b = 2, Mid = 1, s = S - 1; b <= tot; b <<= 1, Mid <<= 1, s--)
		for(int i = 0; i < tot; i += b)
			for(ll j = i, *X1 = A + i, *X2 = A + i + Mid; j < i + Mid; j++, *X1++, *X2++)
			{
				ll tmp = (*X2 * T[j - i << s]) % P;
				*X2 = *X1 - tmp, *X1 += tmp;
			}
	for(int i = 0; i < tot; i++) A[i] %= P;
}

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(; c>'9'||c<'0'; f=c=='-',c=getchar());
	for(; c>='0'&&c<='9'; c=getchar())
		x=(x<<1)+(x<<3)+c-'0';
	return f?-x:x;
}
int main()
{
	n=read();
	m=read();
	for(ll i = 0; i <= n; i++) A[i]=read();
	for(ll i = 0; i <= m; i++) B[i]=read();
	for(tot = 1, S = 0; tot < n + m + 2; tot <<= 1, S++);
	for(ll i = 1; i < tot; i++) Rev[i] = (Rev[i / 2] / 2) + (i & 1) * (tot / 2);
	for(ll i = 1; i < tot; i++) if(Rev[i] > i) swap(A[i], A[Rev[i]]), swap(B[i], B[Rev[i]]);
	T[0] = 1, T[1] = powmod(g, (P - 1) / tot);
	for(ll i = 2; i < tot; i++) T[i] = T[i - 1] * T[1] % P;
	NTT(A), NTT(B);
	for(ll i = 1, j = tot - 1; i < j; i++, j--) swap(T[i], T[j]);
	for(ll i = 0; i < tot; i++) A[i] = A[i] * B[i] % P;
	for(ll i = 1; i < tot; i++) if(Rev[i] > i) swap(A[i], A[Rev[i]]);
	NTT(A), Mut = powmod(tot);
	for(ll i = 0; i <= n + m; i++) printf("%d ",int((A[i] * Mut % P + P) % P));
	return 0;
}

