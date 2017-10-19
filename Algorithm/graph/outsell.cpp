#include<iostream>
#include<cstdio>
#include<cstring>

#include<queue>
using namespace std;
const int maxn=1e5+10,INF=(1<<30);
struct node
{
	int val,pos;
	node(int val,int pos):val(val),pos(pos){}
	bool operator > (const node &a)const
	{
		return val>a.val;
	}
	bool operator < (const node &a)const
	{
		return val<a.val;
	}
};
priority_queue<node,vector<node>,greater<node> >Q;
struct edge
{
	int to,next,val;
}ea[maxn],eb[maxn];
int n,x,prea[maxn],preb[maxn],tota=0,totb=0,disa[maxn],disb[maxn],in[maxn]={0};
bool visb[maxn],visa[maxn],flag=0;
void adda(int,int,int);
void addb(int,int,int);
void SPFA();
void SPFAa();
void SPFA(int);
void sortc(int,int,int);
int main()
{
	memset(prea,-1,sizeof(prea));
	memset(preb,-1,sizeof(preb));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i+x<1||i+x>n||x==0) continue;
		adda(i,i+x,1);
		in[i+x]++;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i+x<1||i+x>n||x==0) continue;
		addb(i+x,i,1);
	}
	SPFA(1);
	if(disa[n]==INF)
	{
		SPFA();
		int mi=INF,pos=0,ma=-1;
		for(int i=1;i<=n;i++) 
		{
			mi=min(mi,disb[i]);
			if(disb[i]!=INF) Q.push(node(disb[i],i));
		}
		if(mi==INF) 
		{
			printf("No solution!");
			return 0;
		}
		SPFAa();
		while(!Q.empty())
		{
			node cur=Q.top();
			Q.pop();
			sortc(cur.pos,cur.pos,0);
			if(flag)
			{
				printf("Infinity!");
				return 0;
			}
			if(~disa[cur.pos]) 
			{
				if(disa[cur.pos]>ma) pos=cur.pos;
			}
		}
		for(int i=1;i<=disa[pos];i++)
		{
			printf("a");
		}
		for(int i=1;i<=disb[pos];i++)
		{
			printf("b");
		}
	}
	else
	{
		for(int i=1;i<=disa[n];i++)
		{
			printf("a");
		}
	}
	return 0;
}
void adda(int from,int to,int val)
{
	ea[++tota].to=to;ea[tota].val=val;ea[tota].next=prea[from];prea[from]=tota;
}
void addb(int from,int to,int val)
{
	eb[++totb].to=to;eb[totb].val=val;eb[totb].next=preb[from];preb[from]=totb;
}
void sortc(int s,int x,int h)
{
	if(flag==1||h>n) return;
	for(int i=prea[s];~i;i=ea[i].next)
	{
		int ito=ea[i].to;
		if(ito==x)
		{
			flag=1;
			return;
		}
		if(h>n) return;
		sortc(ito,s,h+1);
	}
}
void SPFA(int s)
{
	for(int i=1;i<=n;i++) disa[i]=INF;
	memset(visa,0,sizeof(visa));
	visa[s]=1;
	disa[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		visa[cur]=0;
		for(int i=prea[cur];~i;i=ea[i].next)
		{
			int ito=ea[i].to;
			if(disa[ito]>disa[cur]+ea[i].val)
			{
				disa[ito]=disa[cur]+ea[i].val;
				if(!visa[ito])
				{
					q.push(ito);
					visa[ito]=1;
				}
			}
		}
	}
}
void SPFA()
{
	for(int i=1;i<=n;i++) disb[i]=INF;
	memset(visb,0,sizeof(visb));
	visb[n]=1;
	disb[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		visb[cur]=0;
		for(int i=preb[cur];~i;i=eb[i].next)
		{
			int ito=eb[i].to;
			if(disb[ito]>disb[cur]+eb[i].val)
			{
				disb[ito]=disb[cur]+eb[i].val;
				if(!visb[ito])
				{
					q.push(ito);
					visb[ito]=1;
				}
			}
		}
	}
}
void SPFAa()
{
	memset(disa,-1,sizeof(disa));
	memset(visa,0,sizeof(visa));
	visa[1]=1;
	disa[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		visa[cur]=0;
		for(int i=prea[cur];~i;i=ea[i].next)
		{
			int ito=ea[i].to;
			if(disa[ito]<disa[cur]+ea[i].val)
			{
				disa[ito]=disa[cur]+ea[i].val;
				if(disa[ito]>n*10) return;
				if(!visa[ito])
				{
					q.push(ito);
					visa[ito]=1;
				}
			}
		}
	}
}
/*
5
1 1 1 -1 1
0 0 0 1 0

18
3 13 3 4 1 2 5 5 3 1 5 2 1 2 4 -1 2 1
13 6 8 10 -15 -1 10 -2 -4 -9 -6 -17 0 -9 -11 -15 -11 -2
*/
