//Header Files
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Global variables
int f[100]={0};
//Definition Function

//Main Function
int main()
{
	ios::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	int la=a.size(),lb=b.size();
	ll ans=1ll*la*lb;
	for(int i=1;i<la;i++) f[a[i]-'a']++;
	for(int i=0;i<lb-1;i++) ans-=f[b[i]-'a'];
	cout<<ans<<endl;
	return 0;
}
//DIY Function

