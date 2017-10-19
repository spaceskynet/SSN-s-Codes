//��APIO2014��Palindromes By:spaceskynet ģ�����ԣ�poursoul
#include<iostream>
#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxa=1e6+10,cha=26;//maxa �ַ�������ȣ�cha �ַ�����С 
typedef long long ll;
struct PalindromicTree
{
	int next[maxa][cha],fail[maxa],cnt[maxa],len[maxa],num[maxa]; 
	int tot,s[maxa],p,last;
	int newnode(int l)
	{
		for(int i=0;i<cha;i++) next[p][i]=0;
		len[p]=l;
		cnt[p]=num[p]=0;
		return p++;
	}
	void init()
	{
		tot=p=last=0;
		s[0]=-1,fail[0]=1;//0Ϊ�洢 ż�����Ĵ� �����ڵ㣬1Ϊ�洢 �������Ĵ� �����ڵ㣬0��failָ��ָ��1 
		newnode(0)/*p==0,ż�����Ĵ������ڵ���Ϊ0,lenֵΪ0*/,newnode(-1);/*p==1,�������Ĵ������ڵ���Ϊ1,lenֵΪ-1*/
	}
	int getfail(int x)
	{
		while(s[tot-len[x]-1]!=s[tot]) x=fail[x];
		return x;
	}
	void insert(char c)
	{
		c-='a';
		s[++tot]=c;
		int cur=getfail(last);
		if(!next[cur][c])
		{
			int now=newnode(len[cur]+2);
			fail[now]=next[getfail(fail[cur])][c];
			next[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last=next[cur][c];
		cnt[last]++;
	}
	void makecnt()
	{
		for(int i=p-1;i>=2;i--) cnt[fail[i]]+=cnt[i];//���ڵ�cnt�����壬i>=2���� 
	}
}pt;
char str[maxa];
ll ans=0;
int main() 
{
	scanf("%s",str);
	int len=strlen(str);
	pt.init();
	for(int i=0;i<len;i++) pt.insert(str[i]);
	pt.makecnt();
	for(int i=2;i<pt.p;i++) ans=max((ll)pt.len[i]*pt.cnt[i],ans);//ͬmakecnt 
	printf("%lld\n",ans);
	return 0;
}
