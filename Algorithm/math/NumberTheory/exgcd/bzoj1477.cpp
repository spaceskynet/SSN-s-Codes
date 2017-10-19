//exgcd (m-n)*x-L*y=y0-x0 -> 
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x0,y0,m,n,L;
void exgcd(ll,ll,ll&,ll&,ll&);
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x0,&y0,&m,&n,&L);
	ll A=((m-n)%L+L)%L,B=L,C=y0-x0,x,y,t;
	exgcd(A,B,t,x,y);
	if(C%t) {printf("Impossible\n");return 0;}
	A/=t,B/=t,C/=t,x=(x*C%B+B)%B;
	printf("%lld\n",x);
	return 0;
}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=x*(a/b);
}
