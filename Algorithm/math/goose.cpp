#include<iostream>
#include<cstdio>
#include<queue>
#define MASK 01
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
typedef long long ll;
ll x,y;
queue<ll> q;
ll get_bit_high_pos(ll);
int main()
{
	scanf("%lld%lld",&x,&y);
	for(int i=0;i<=get_bit_high_pos(x);i++)
	{
		if(x>>i&1)
		{
			if((1<<i+1)%4) q.push(1<<i+1);
			else
			{
				q.push(i<<1);
				q.push((i<<1)+1);
			}
		}
//		printf("%d",(x>>i&1));
	}
	while(!q.empty())
	{
		printf("%d\n",q.front());
		q.pop();
	}
	return 0;
}
ll get_bit_high_pos(ll n)
{
	ll num = abs(n);
	int i=0,pos=0;
	for(i=0;i<=8*sizeof(ll);i++,num>>=1)
	{
		if((num&MASK)==MASK)
		{
			pos=i+1;
		}
	}
	return pos;
}
