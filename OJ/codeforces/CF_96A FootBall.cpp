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
#include<queue>
#include<stack>
using namespace std;
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Global variables

//Definition Function
bool judge(string a);
//Main Function
int main()
{
//	double t1=(double)clock()/CLOCKS_PER_SEC;
	ios::sync_with_stdio(false);
	string a;
	cin>>a;
	if(judge(a)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
//	double t2=(double)clock()/CLOCKS_PER_SEC;
//	cout<<"Times:"<<(double)t2-t1<<endl;
	return 0;
}
//DIY Function
bool judge(string a)
{
	int la=a.size(),ans=0;
	bool now=a[0]-48;
	for(int i=0;i<la;i++)
	{
		if(a[i]==now+48)
		{
			ans++;
		}
		else
		{
			now=!now;
			ans=1;
		}
		if(ans==7)
		{
			return 1;
		}
	}
	return 0;
}

