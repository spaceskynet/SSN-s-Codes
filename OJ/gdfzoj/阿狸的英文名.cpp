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
int x[27]={0},y[27]={0},z[27]={0};
string str[100001];
//name Function
bool searchchar(string a,string b,int l1,int l2);
//int howmany(string a,string b,int l1,int l2);
//Main Function
int main()
{
	ios::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	int l1=a.size(),l2=b.size(),s=l1*l2;
//	cout<<howmany(a,b,l1,l2)<<endl;
	if(!searchchar(a,b,l1,l2))
	{
		cout<<s<<endl;
	}
	else
	{
		for(int i=1;i<=26;i++)
		{
			s-=z[i];
		}
		cout<<s<<endl;
	}
	return 0;
}
//DIY Function
bool searchchar(string a,string b,int l1,int l2)
{
	bool is=0;
	for(int i=0;i<l1;i++)
	{
		x[a[i]-96]++;
	}
	for(int j=0;j<l2;j++)
	{
		y[b[j]-96]++;
	}
	for(int i=1;i<=26;i++)
	{
		z[i]=x[i]*y[i];
		if(z[i]) is=1;
	}
	return is;
}
/*int howmany(string a,string b,int l1,int l2)
{
	int k=0;
	string tmp,x=a,y=b;
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			tmp==x.erase(l1-i,i)+y.erase(0,j);
			for(int m=0;m<=k;m++)
			{
				if(tmp==str[m]) break;
				else if(tmp!=str[m]&&str[m].empty())
				{
					str[m]==tmp;
					k++;
				}
			}
		}
	}
	return k;
}*/

