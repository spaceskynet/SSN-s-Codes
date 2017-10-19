#include<iostream>
#include<cstdio>
#include<complex>
#include<queue>
using namespace std;
typedef long long ll;
int cnt=0;
ll x,y;
queue<ll> q;
int main()
{
	scanf("%lld%lld",&x,&y);
	complex<ll> n(x,y),p(-1,-1),l(0,0),m(1,0);
	while(n!=l)
	{
		if((n.real()+n.imag())%2)
		{
			q.push(cnt++);
			n-=m;
		}
		else cnt++;
		n/=p;
	}
	while(!q.empty())
	{
		printf("%d\n",q.front());
		q.pop();
	}
	return 0;
}

