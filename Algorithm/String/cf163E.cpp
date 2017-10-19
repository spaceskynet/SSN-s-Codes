//ACautomaton+failTree+BIT Spaceskynet
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxa=1e6+10,maxn=1e6+10,cha=26;
int n,k,cnt=0,l[maxn],r[maxn];
bool del[maxn]={0};
char s[maxa];
struct BIT
{
	int sum[maxn],sz;
	void init(int sz)
	{
		this->sz=sz;
		memset(sum,0,sizeof(sum));
	}
	void updata(int pos,int val)
	{
		for(int i=pos;i<=sz;i+=lowbit(i)) sum[i]+=val;
	}
	int query(int pos)
	{
		int ans=0;
		for(int i=pos;i>=1;i-=lowbit(i)) ans+=sum[i];
		return ans;
	}
}bit;
struct failTree
{
	struct node
	{
		int to,next;
	}e[maxn];
	int pre[maxn];
	int tot;
	void init()
	{
		memset(pre,-1,sizeof(pre));
		tot=0;
	}
	void add(int from,int to)
	{
		e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
	}
	void dfs(int s)
	{
		l[s]=++cnt;
		for(int i=pre[s];~i;i=e[i].next) dfs(e[i].to);
		r[s]=cnt;
	}
}tree;
struct ACautomaton
{
	int next[maxa][cha],fail[maxa],end[maxa],pos[maxa];
	int root,L,d;
	int newnode()
	{
		for(int i=0;i<cha;i++) next[L][i]=-1;
		end[L++]=0;
		return L-1;
	}
	void insert(char *buf,int x)
	{
		int len=strlen(buf);
		int now=root;
		for(int i=0;i<len;i++)
		{
			int &nxt=next[now][buf[i]-'a'];
			if(nxt==-1) nxt=newnode();
			now=nxt;
		}
		end[now]++;
		pos[x]=now;
	}
	void init()
	{
		L=d=0;
		root=newnode();
	}
	void build()
	{
		queue<int> q;
		fail[root]=root;
		for(int i=0;i<cha;i++)
		{
			int &nxt=next[root][i];
			if(nxt==-1) nxt=root;
			else fail[nxt]=root,q.push(nxt);
		}
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=0;i<cha;i++) 
			{
				int &nxt=next[now][i],&fnxt=next[fail[now]][i];
				if(nxt==-1) nxt=fnxt;
				else fail[nxt]=fnxt,end[nxt]+=end[fnxt],q.push(nxt);//substrings can repeat --> end[nxt]+=end[fnxt]
			}
		}
	}
	int query(char *c)
	{
		int ans=0,k=0;
		for(int i=0;s[i];i++)
		{
			int t=s[i]-'a';
			k=next[k][t];
			if(end[k])
			{
				ans+=bit.query(l[k]);
			}
		}
		return ans;
	}
}ac;
int main()
{
	scanf("%d%d",&n,&k);
	ac.init();
	for(int i=1;i<=k;i++)
	{
		scanf("%s",s);
		ac.insert(s,i);
	}
	ac.build();
	tree.init();
	for(int i=1;i<ac.L;++i) tree.add(ac.fail[i],i);
	cnt=0;
	tree.dfs(0);
	bit.init(ac.L);
	for(int i=0;i<ac.L;++i)
	{
		bit.updata(l[i],ac.end[i]);
		bit.updata(l[i]+1,-ac.end[i]);
	}
	while(n--)
	{
		int x;
		char c=getchar();
		while(c!='+'&&c!='-'&&c!='?') c=getchar();
		if(c=='+') 
		{
			scanf("%d",&x);
			if(del[x])
			{
				del[x]=false;
				bit.updata(l[ac.pos[x]],1);
				bit.updata(r[ac.pos[x]]+1,-1);
			}
		}
		else if(c=='-') 
		{
			scanf("%d",&x);
			if(!del[x])
			{
				del[x]=true;
				bit.updata(l[ac.pos[x]],-1);
				bit.updata(r[ac.pos[x]]+1,1);
			}
		}
		else scanf("%s",s),printf("%d\n",ac.query(s));
	}
	return 0;
}
