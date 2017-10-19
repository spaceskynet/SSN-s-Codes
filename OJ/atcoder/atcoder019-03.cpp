#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
const int maxn=3e5+10;
typedef double db;
const db PI=acos(-1);
struct point
{
	int x,y;
}p[maxn];
int X1,Y1,X2,Y2,n,stack[maxn],top=0,e[maxn],cnt=0,mix,maxx,may,miy;
db ans,tmp;
bool flag=0;
//bool Find(int,bool);
//bool cp(int,int);
bool check(point);
bool cmp(const int&,const int&);
//void halfFind(int&,int&);
int main()
{
	scanf("%d%d%d%d%d",&X1,&Y1,&X2,&Y2,&n);
	if(X1>X2) swap(X1,X2),swap(Y1,Y2);
	if(Y1>Y2) Y1=-Y1,Y2=-Y2,flag=1;
//	mix=min(X1,X2),maxx=max(X1,X2);
//	miy=min(Y1,Y2),may=max(Y1,Y2);
//	flag=X1>X2?(Y1>Y2?0:1):(Y1>Y2?1:0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		if(flag) p[i].y=-p[i].y;
		if(check(p[i])) e[++cnt]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	int len=0;
	for(int i=1;i<=cnt;i++)
	{
		int l=1,r=len,t=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(p[e[i]].y>stack[mid]) l=(t=mid)+1;
			else r=mid-1;
		}
		if(t==len) stack[++len]=p[e[i]].y;
		else stack[t+1]=min(stack[t+1],p[e[i]].y);
	}
	ans=(X2-X1+Y2-Y1)*100.0;
	if(X1==X2||Y1==Y2)
	{
		if(cnt) ans+=10.0*PI-20.0;
	}
	else
	{
		ans-=(20.0-5.0*PI)*len;
		if(len==min(X2-X1,Y2-Y1)+1) ans+=5*PI;
	}
//	flag=X1>X2?(Y1>Y2?0:1):(Y1>Y2?1:0);
//	for(int i=1;i<=cnt;i++)
//	{
//		while(top&&cp(p[stack[top]].y,p[e[i]].y)) top--;
//		stack[++top]=e[i];
//	}
//	ans=(abs(X1-X2)+abs(Y1-Y2))*100.0;
//	tmp=(20-5*PI)*top;
//	if(top==min(maxx-mix,may-miy)+1) ans+=5*PI;
	printf("%.20f",ans);
	return 0;
}//(mix==p[stack[e[1]]].x&&maxx==p[stack[top]].x)||(miy==p[stack[e[1]]].y&&may==p[stack[top]].y)
bool cp(int x,int y)
{
	if(flag) return x>y;
	else return x<y;
}
bool cmp(const int &a,const int &b)
{
	return p[a].x<p[b].x;
}
bool check(point a)
{
	return a.x>=X1&&a.x<=X2&&a.y>=Y1&&a.y<=Y2;
}
