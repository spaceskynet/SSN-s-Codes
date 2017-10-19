#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
//Definition Macro
#define ll long long
#define ull unsigned long long
#define Mod 1000000007
//Definition namespace
using namespace std;
//Definition Struct Or Class
//Definition Global variables
//Definition Function
ull array(ull,ull);
ull combination(ull,ull);
ull choice(ull,ull);
//Main Function
int main()
{
	ull n,m,ans;
	cin>>n>>m;
	if(m>=n)
	{
		ans=array(m,n);
	}
	else
	{
		if(m==2&&n%2==1||m==1) ans=0;
		else ans=choice(m,n);
	}
	ans%=Mod;
	cout<<ans<<endl;
	return 0;
}
//DIY Function
ull array(ull m,ull n)//m在下，n在上
{
	ll array1=1;
	for(ll i=0;i<=n-1;i++) array1*=(m-i);
	return array1;
}
ull combination(ull m,ull n)//m在下，n在上
{
	return array(m,n)/array(n,n);
}
ull choice(ull m,ull n)
{
	ull s=m;
	for(ull i=1;i<n;i++) s*=(m-1);
	return s;
}

