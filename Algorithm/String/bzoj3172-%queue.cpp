// ÷%queue∞Ê 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e6+10,cha=26;
struct ACautomaton
{
	int next[maxn][cha],fail[maxn],end[maxn],pos[maxn],head,tail,q[maxn];
	int L,root;
	int newnode()
	{
		for(int i=0;i<cha;i++) next[L][i]=-1;
		end[L]=0;
		return L++;
	}
	ACautomaton()
	{
		L=0;
		root=newnode();
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
			end[now]++;
		}
		pos[x]=now;
	}
	void build()
	{
		head=0,tail=0;
		fail[root]=root;
		for(int i=0;i<cha;i++)
		{
			int &nxt=next[root][i];
			if(nxt==-1) nxt=root;
			else fail[nxt]=root,q[++tail]=nxt;
		}
		while(head!=tail)
		{
			int now=q[++head];
			for(int i=0;i<cha;i++)
			{
				int &nxt=next[now][i],&fnxt=next[fail[now]][i];
				if(nxt==-1) nxt=fnxt;
				else fail[nxt]=fnxt,q[++tail]=nxt;
			}
		}
		for(int i=tail;i;i--) end[q[fail[i]]]+=end[q[i]];
	}
}ac;
int n;
char s[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		ac.insert(s,i);
	}
	ac.build();
	for(int i=1;i<=n;i++) printf("%d\n",ac.end[ac.pos[i]]);
	return 0;
}
