#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class
//Definition Global variables
ll n,i,ans,maxn,minn,x,a[6010],b[6010],c[6010];
bool p[1001],pd;
//Definition Function
void check();
void src(ll,ll);
//Main Function
int main()
{
	cin>>n;
	memset(a,0,sizeof(a));
	minn=2000000000;
	maxn=-1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if (a[i]<minn) minn=a[i];
		if (a[i]>maxn) maxn=a[i];
	}
	sort(a+1,a+n+1);
	memset(c,0,sizeof(c));
	src(1,maxn-minn);
	ans=abs(c[n]-c[1]);
	for(int i=1; i<n; i++)
		if(ans<abs(c[i+1]-c[i])) ans=abs(c[i+1]-c[i]);
	cout<<ans<<endl<<c[1];
	for(int i=2; i<=n; i++)
	{
		cout<<','<<c[i];
	}
	return 0;
}
//DIY Function
void check()
{
	ll head,tail,ct,ch,i,ii,q;
	bool pt;
	memset(p,1,sizeof(p));
	memset(b,0,sizeof(b));
	pd=0;
	b[1]=a[1];
	p[1]=0;
	head=2;
	tail=n;
	ct=1;
	ch=1;
	pt=1;
	while(pt)
	{
		if(head>tail)
		{
			if(abs(b[head]-b[tail])<=x)
			{
				pd=1;
			}
			return;
		}
		else if(head==tail)
		{
			for(int i=1; i<=n; i++)
			{
				if(p[i])
				{
					ii=i;
					break;
				}
			}
			if((abs(a[ii]-b[head-1])<=x)&&(abs(a[ii]-b[tail+1])<=x))
			{
				b[head]=a[ii];
				pd=1;
				break;
			}
		}
		if(p[n])
		{
			q=1;
			for(int i=n; i>=1; i--)
			{
				if(p[i])
				{
					if(abs(a[i]-b[ct])<=x)
					{
						q=i;
						break;
					}

				}
			}
			if(q==1)
			{
				return;
			}
			p[q]=0;
			b[tail]=a[q];
			ct=tail;
			tail--;

		}
		q=1;
		for(int i=1; i<=n; i++)
		{
			if(p[i])
			{
				if(abs(a[i]-b[ch])<=x)
				{
					q=i;
					break;
				}
			}
		}
		if(q==1) return;
		p[q]=0;
		b[head]=a[q];
		ch=head;
		head++;
	}
}
void src(ll l,ll r)
{
	x=(l+(r-l)/2);
	check();
	if(pd)
	{
		ans=x;
		memcpy(c,b,sizeof(b));
		if((l!=r)&&(x-1>=l))
		{
			src(l,x-1);
		}
	}
	else
	{
		if ((l!=r)&&(r>=x+1)) src(x+1,r);
	}
}

