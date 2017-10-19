#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
//Definition namespace
using namespace std;
//Definition Struct Or Class
struct each
{
	int every,thing;
}milker[5001];
//Definition Global variables
//Definition Function
int cmp(struct each a,struct each b);
//Main Function
int main()
{
	ios::sync_with_stdio(false);
	int n,m,ans=0,remind=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>milker[i].every>>milker[i].thing;
	}
	sort(milker+0,milker+m,cmp);
	for(int i=0;;)
	{
		if(milker[i].thing>(n-remind))
		{
			ans+=(n-remind)*milker[i].every;
			break;
		}
		else
		{
			ans+=milker[i].every*milker[i].thing;
			remind+=milker[i].thing;
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
int cmp(struct each a,struct each b)
{
	return a.every<b.every;
}

