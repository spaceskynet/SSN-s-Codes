#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
//#include<iomanip>
#include<algorithm>
//#include<ctime>
#include<map>
//#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class

//Definition Global variables
priority_queue<int,vector<int>,greater<int> >Q;
int ans[10001],llel[10001];
//Definition Function
bool cpr(string str1,string str2);
void find(int,int,int);
bool isallsame(string a);
bool isup(string);
bool isdown(string);
int compare(const void *p, const void *q);
//Main Function
int main()
{
	ios::sync_with_stdio(false);
	int t=0,l,r;
	cin>>t;
	for(int z=0;z<t;z++)
	{
		cin>>l>>r;
		if(r<10)
		{
			ans[z]=0;
			}
		if(l<10)
		{
			l=10;
		}
  		find(l,r,z);
	}
	for(int i=0;i<t;i++)
	{
		cout<<ans[i]/llel[i]<<endl;
	}
	return 0;
}
//DIY Function
void find(int l,int r,int z)
{
	char tmp1[10],tmp2[10];
	string le,ri;
	itoa(l,tmp1,10);
	itoa(r,tmp2,10);
	le=tmp1,ri=tmp2;
	int lle=le.size(),lri=ri.size();
	for(int i=l;i<=r;i++)
	{
		string tmp;
		char tmpc[10];
		itoa(i,tmpc,10);
		tmp=tmpc;
		if(isallsame(tmp)) continue;
		int lt=tmp.size();
		for(int j=1;j<lt;j++)
		{
			if(tmp[j]!='0')
			{
				string changed,tp;
				changed=tmp;
				tp=tmp.substr(0,j);
				changed.erase(0,j);
				changed+=tp;
				int ch=atoi(changed.c_str());
				if(ch<=r)
				{
					Q.push(ch);
				}
				else
				{
					continue;
				}
			}
		}
	}
	ans[z]=Q.size();
	if(lle==2)
	{
		llel[z]=2;
	}
	else
	{
		llel[z]=lle-1;
	}
}
bool cpr(string str1,string str2)
{
	int len1=str1.size(),len2=str2.size();
	if(len1>len2) return true;
	else if(len1<len2) return false;
	else
	{
		for(int i=0;i<len1;i++)
		{
			if(str1[i]>str2[i]) return true;
			if(str1[i]<str2[i]) return false;
		}
	}
}
bool isallsame(string a)
{
	for(int i=0;i<a.size()-1;i++)
	{
		if(a[i]!=a[i+1]) return 0;
	}
	return 1;
}
bool isup(string a)
{
	for(int i=0;i<a.size()-1;i++)
	{
		if(a[i]>a[i+1]) return 0;
	}
	return 1;
}
bool isdown(string a)
{
	for(int i=0;i<a.size()-1;i++)
	{
		if(a[i]<a[i+1]) return 0;
	}
	return 1;
}
int compare(const void *p, const void *q)
{
    return (*(int*)p-*(int*)q);
}
