//%spaceskynet
#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e6+10;
struct edge
{
	int to,next;
}e[maxn];
int pre[maxn],in[maxn]={0},stack[maxn],top=0,num=0,tot=0;
void add(int,int);
int main()
{
	int n,m,l,r,t;
	scanf("%d",&t);
	while(t--)
	{
		num=0;
		cls(pre,-1),cls(in,0),cls(stack,-1);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			add(l,r);
			in[r]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0) stack[++top]=i;
		}
		while(top!=0)
		{
			int cnt=stack[top--];//next--->printf point
			in[cnt]=-1;
			num++;
			for(int i=pre[cnt];~i;i=e[i].next)
			{
				int ito=e[i].to;
				--in[ito];
				if(in[ito]==0) stack[++top]=ito;
			}
		}
		if(num<n) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}
