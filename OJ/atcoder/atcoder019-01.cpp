#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct glass
{
	ll times,val;
	bool operator < (glass &a)const{
		return this->val*this->times<a.val*a.times;
	}
}cup[4];
int n;
ll ans=0;
int main()
{
	scanf("%lld%lld%lld%lld%d",&cup[0].val,&cup[1].val,&cup[2].val,&cup[3].val,&n);
	cup[0].times=8,cup[1].times=4,cup[2].times=2,cup[3].times=1;
	sort(cup,cup+4);
	if(cup[0].times!=1) ans=cup[0].times*cup[0].val*n/2;
	else
	{
		ans+=(n/2)*cup[0].val;
		if(n%2)
		{
			ans+=cup[1].times/2*cup[1].val;
		}
	}
	printf("%lld\n",ans);
	return 0; 
}
