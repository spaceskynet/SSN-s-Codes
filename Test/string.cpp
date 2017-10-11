#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=1e5+10,cha=26;
struct Block
{
	int begin,len;
	char c;
	Block(){}
	Block(int begin,int len,char c):begin(begin),len(len),c(c){}
}b[maxn];
int sum[cha];
char str[maxn];
int n,m,cnt=0;
void Halfmid(int,int,int&,int&);
int read();
int main()
{
	fr(string);
	n=read(),m=read();
	scanf("%s",str+1);
	for(int i=1,j;i<=n;i++)
	{
		for(j=i+1;j<=n&&str[j]==str[j-1];j++);
		b[++cnt]=Block(i,j-i,str[i]);
		i=j-1;
	}
	b[0].len=1;//if BL=1 when update, b[1].begin must be 1,and b[1].begin=b[0].begin+b[0].len,so make b[0].len or b[0].begin = 1
	while(m--)
	{
		int l,r,op;
		l=read(),r=read(),op=read();
		int L,R;
		Halfmid(l,r,L,R);//Find Which Two Edge Block
		if(L==R) continue;
		mem(sum,0);
		int BL=L+1,BR=R;
		if(l==b[L].begin) BL=L;//Cut The Leftist Block
		else
		{
			sum[b[L].c-'a']+=b[L].len-(l-b[L].begin);
			b[L].len=l-b[L].begin;//don't need +1
		}
		if(r==b[R].begin+b[R].len-1) BR=R+1;//Cut The Rightist Block
		else
		{
			sum[b[R].c-'a']+=r-b[R].begin+1;
			b[R].len=b[R].len-(r-b[R].begin+1);
			b[R].begin=r+1;
		}
		for(int i=BL;i<BR;i++) sum[b[i].c-'a']+=b[i].len;
		int ret=0;
		for(int i=0;i<cha;i++) if(sum[i]) ret++;
		if(BL+ret-BR)//If Has the Same Char don't in 1 block (Expansion or Compression)
		{
			if(BL+ret>BR)//Should ->-> Right Move Block
			{
				for(int i=cnt;i>=BR;i--)
				{
					b[BL+ret+i-BR]=b[i];
				}
			}
			else//should <-<- Left Move Block
			{
				for(int i=BR;i<=cnt;i++)
				{
					b[BL+ret+i-BR]=b[i];
				}
			}
		}
		cnt+=BL+ret-BR;//New End Block Num
		//Update ch,newstartpos & len
		if(op)//up
		{
			for(int i=0;i<cha;i++) if(sum[i]) b[BL]=Block(b[BL-1].begin+b[BL-1].len,sum[i],i+'a'),BL++;
		}
		else//down
		{
			for(int i=cha-1;i>=0;i--) if(sum[i]) b[BL]=Block(b[BL-1].begin+b[BL-1].len,sum[i],i+'a'),BL++;
		}
		//for(int i=1;i<=cnt;i++) for(int j=1;j<=b[i].len;j++) putchar(b[i].c);
		//putchar('\n');
	}
	for(int i=1;i<=cnt;i++) for(int j=1;j<=b[i].len;j++) putchar(b[i].c);
//	fprintf(stderr,"%.3lf s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void Halfmid(int L,int R,int &BL,int &BR)
{
	int mid,l=1,r=cnt;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(b[mid].begin<=L&&L<=b[mid].begin+b[mid].len-1) {BL=mid;break;}
		else if(L<b[mid].begin) r=mid-1;
		else l=mid+1;
	}
	l=1,r=cnt;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(b[mid].begin<=R&&R<=b[mid].begin+b[mid].len-1) {BR=mid;break;}
		else if(R<b[mid].begin) r=mid-1;//is R Not L
		else l=mid+1;
	}
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
