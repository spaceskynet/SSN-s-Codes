//spaceskynet ∂‡Œƒ±æ¥Æ∆•≈‰
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxa=1e6+10,cha=26;
struct ACautomaton
{
	int next[maxa][cha],fail[maxa],end[maxa][2];
	int root,L,d;
	int newnode()
	{
		for(int i=0;i<cha;i++)
		{
			next[L][i]=-1;
		}
		end[L++][0]=0;
		return L-1;
	}
	void insert(char *buf)
	{
		int len=strlen(buf);
		int now=root;
		for(int i=0;i<len;i++)
		{
			int &nxt=next[now][buf[i]-'a'];
			if(nxt==-1) nxt=newnode();
			now=nxt;
		}
		end[now][0]++;
	}
	void init()
	{
		L=0;
		d=0;
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
				else fail[nxt]=fnxt,q.push(nxt);
			}
		}
	}
	int solve(char *s)
	{
		int ans=0,k=0;
		for(int i=0;i<L;i++) end[i][d^1]=end[i][d];
		for(int i=0;s[i];i++)
		{
			int t=s[i]-'a';
			k=next[k][t];
			int j=k;
			while(j&&~end[j][d])
			{
				ans+=end[j][d];
				end[j][d]=-1;
				j=fail[j];
			}
		}
		d^=1;
		return ans;
	}
}ac;
char buf[maxa];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ac.init();
		for(int i=0;i<n;i++)
		{
			scanf("%s",buf);
			ac.insert(buf);
		}
		ac.build();
		for(int i=0;i<m;i++)
		{
			scanf("%s",buf);
			printf("%d\n",ac.solve(buf));
		}
	}
	return 0;
}
/*
1
5 5
abcdefg
bcdefg
cdef
de
e
ssaabcdefg
*/
