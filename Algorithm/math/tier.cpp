#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long ll;
int x,n,len,l=2,xlen;
ll r=2;
char xc[10],ans[50];
int next[50];
int fpwr(int,int);
int main()
{
//	freopen("tier.in","r",stdin);
//	freopen("tier.out","w",stdout);
	scanf("%s%d",xc+1,&n);
	if(n==1) printf("%s",xc);
	x=atoi(xc);
	len=strlen(xc+1);
	xlen=len;
	ll tmp=0;
	while(r+tmp<n)
	{
		xlen++;
		tmp=(xlen-len)*19*fpwr(10,xlen-len-1)*1ll;
		l=r;
	}
	tmp=0;
	for(int i=1,x=0;i<xlen;i++)
	{
		int c=-1;
		while(r+tmp<n)
		{
			c++;
			tmp=(xlen-i-1o)*fpwr(10,xlen-i-len)*1ll;
			if(xc[i-x]==c+'0') tmp+=fpwr(10,len-xlen)*1ll;
			l=r;
		}
//		r=l;
		ans[i]=c+'0';
		if(ans[i]!=xc[i-x])
		{
			while(ans[i]!=xc[1]||x<=i) x++;
		}
		if(i-x==len)
		{
			int y=n-l-1,ylen=0;
			char yc[10];
			int tp=y;
			while(tp) yc[ylen++]=(tp%10),tp/=10;
			for(int j=i+1;j<=len-ylen;j++)
			{
				ans[j]='0';
			}
			for(int j=0;j<ylen;j++)
			{
				ans[len-ylen+1]=yc[ylen-1];
			}
		}
	}
	printf("%s",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
int fpwr(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1) ret=ret*x;
		x=x*x;
		y>>=1;
	}
	return ret;
}
