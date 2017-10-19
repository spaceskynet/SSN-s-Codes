#include<iostream>
#include<cstdio>
using namespace std;
char ch[300];
int d=0,a=0;
char *p=&ch[0];
char *p1=&ch[0];
int work()
{
	if(*p=='@') return 0;
	while(*p!='@')
	{
		p++;
	}
	if(*(p+1)=='.'||*(p+1)=='\0') return 0;
	else
	{
		while(*p!='.'){p++;}
		if(*(p+1)=='\0') return 0;
		for(;*p1!='\0';p1++)
		{
			if(*p1=='.') d++;
			if(*p1=='@') a++;
			if(!((*p1>='0'&&*p1<='9')||(*p1>='a'&&*p1<='z')||(*p1>='A'&&*p1<='Z')||*p1=='@'||*p1=='.')) return 0;
		}
		if(d<2&&a<2) return 1;	 
		else return 0;
	}
}
int main()
{
	scanf("%s",ch);
	if(work()==0) cout<<"no";
	else cout<<"yes";
	return 0;
}
