#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
using namespace std;
//change data
int chioce[4]={0,1,1,1};//0->f1,1->f2
char page[110];
int n=0,tmp,maxn=0,cuth[40]={0};
string str;
//name Function
int int2str(int int_temp);
int f2(int start);
int f3(int start);
int f4(int start);
int wowo();
int cut();
//Main Function
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		if(tmp>maxn) maxn=tmp;
		page[tmp]='1';
		if(page[i+1]!='1') page[i+1]='0';
	}
	str=page;
	cout<<wowo()<<endl;
	return 0;
}
//DIY Function
int int2str(int int_temp)
{
    char s[12];
	string string_temp;
    itoa(int_temp,s,10);
    string_temp=s;
    return string_temp.size();
}
int f2(int start)
{
	for(int i=start;;i++)
	{
		if(str[i]!='1') return i;
		if(i==maxn) return i;
	}
}
int f3(int start)
{
	for(int i=start;;i+=2)
	{
		if(str[i]!='1') return i;
		if(i==maxn||i==maxn-1) return i;
	}
}
int f4(int start)
{
	for(int i=start;;i+=2)
	{
		if(str[i]!='1') return i;
		if(i==maxn||i==maxn-1) return i;
	}
}
int wowo()
{
	int cutn=cut(),ans=0;
	for(int i=1;i<=cutn;i++)
	{
		for(int j=cuth[i];j<=cuth[i+1];j++)
		{
			if(j%2)
			{
				ans+=f2(j);
				ans+=f3(j);
			}
			else
			{
				ans+=f2(j);
				ans+=f4(j);
			}
			ans+=int2str(j);
		}
	}
	return ans;
}
int cut()
{
	int cutn=0;
	cuth[0]=1;
	for(int i=1;i<maxn;i++)
	{
		if(str[i+1]==str[i+2]=='0'&&str[i]=='1')
		{
			cutn++;
			cuth[cutn]=i;
		}
	}
	return cutn;
}
