//spaceskynet
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=1e6+10;
int n,rad[maxn*2];
char s[maxn],str[maxn*2]={0};
set<string> st;
void manacher(char*,int);
void print(int);
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		memset(rad,0,sizeof(rad));
		memset(str,0,sizeof(str));
		n=strlen(s);
	//	if(n%2==0)
	//	{
		int len=0;
		str[len]='@';
		str[++len]='#';
		for(int i=0;i<n;i++)
		{
			str[++len]=s[i];
			str[++len]='#';
		}
		str[++len]='$';
		manacher(str,len);
	//	}
	//	else manacher(s,n);
		int ans=0,id=0;
		for(int i=0;i<=len+2;i++)
		{
			if(ans<rad[i])
			{
				ans=rad[i];
				id=i;
			}
		}
	//	if(n%2) ans++;
		printf("%d\n",ans);
		for(int i=0;i<=len+2;i++)
		{
			if(rad[i]==ans) print(i);
		}
		set<string>::iterator set_iter=st.begin();
		for(;set_iter!=st.end();set_iter++) 
		{
			cout<<*set_iter<<endl;
		}
		st.clear();
		memset(s,0,sizeof(s));
	}
	return 0;
}
void manacher(char *s,int l)
{
	for(int i=1,j=0,k;i<l;)
	{
		for(;s[i-j-1]==s[i+j+1];j++);
		rad[i]=j;
		for(k=1;k<=j&&rad[i]-k!=rad[i-k];k++)
		{
			rad[i+k]=min(rad[i]-k,rad[i-k]);
		}
		i+=k;
		j=max(j-k,0);
	}
}
void print(int id)
{
	string s;
	for(int i=id-rad[id];i<=id+rad[id];i++)
	{
		if(str[i]=='#') continue;
		s+=str[i];
	}
	st.insert(s);
}
