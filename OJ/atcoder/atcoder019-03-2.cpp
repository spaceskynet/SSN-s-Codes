#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
const int maxn=2e5+10,INF=~0U>>1;
typedef double db;
const db PI=acos(-1);
struct point
{
	int x,y;
}p[maxn];
int X1,Y1,X2,Y2,n,stack[maxn],top=0,e[maxn],cnt=0,mix,maxx,may,miy;
db ans;
bool flag=0;
bool check(point);
bool cmp(const int&,const int&);
void binary_search(int,int,int*);
int main()
{
//	freopen("error_input.in","r",stdin);
	scanf("%d%d%d%d%d",&X1,&Y1,&X2,&Y2,&n);
	if(X1>X2) swap(X1,X2),swap(Y1,Y2);
	if(Y1>Y2) Y1=-Y1,Y2=-Y2,flag=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		if(flag) p[i].y=-p[i].y;
		if(check(p[i])) e[++cnt]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	stack[0]=-INF;
	for(int i=1;i<=cnt;i++) 
	{
//		printf("%d ",p[e[i]].y);
		if(!top||p[e[i]].y>p[stack[top]].y)
		{
			stack[++top]=e[i];
		}
		else binary_search(e[i],top,stack);
	}
//	putchar('\n');
//	if(stack[top+1]) top++;
	ans=(X2-X1+Y2-Y1)*100.0;
	if(X1==X2||Y1==Y2)
	{
		if(cnt) ans+=10.0*PI-20.0;
	}
	else
	{
		ans-=(20.0-5.0*PI)*top;
		if(top==min(X2-X1,Y2-Y1)+1) ans+=5*PI;
	}
	printf("%.20f",ans);
	return 0;
}
bool cmp(const int &a,const int &b)
{
	return p[a].x<p[b].x;
}
bool check(point a)
{
	return a.x>=X1&&a.x<=X2&&a.y>=Y1&&a.y<=Y2;
}
void binary_search(int x,int r,int* s)
{
	int l=1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(p[x].y>p[s[mid]].y) l=mid+1;
		else r=mid-1;
	}
	s[l]=x;
}
