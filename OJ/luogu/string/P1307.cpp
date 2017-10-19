#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string a;
	cin>>a;
	if(a[0]=='-')
	{
		reverse(a.begin()+1,a.end());
		if(a[1]=='0')
		{
			while(1)
			{
				a.erase(1,1);
				if(a[1]!='0') break;
			}
		}
		cout<<a<<endl;
	}
	else
	{
		reverse(a.begin(),a.end());
		if(a[0]=='0')
		{
			while(1)
			{
				a.erase(0,1);
				if(a[0]!='0') break;
			}
		}
		cout<<a<<endl;
	}
	return 0;
}


