#include<iostream>
#include<cstdio>
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
typedef long long ll;
ll a,b;
int main()
{
	scanf("%lld%lld",&a,&b);
	if(abs(a-b)%4) printf("%lld",a+b);
	else printf("shijienihao");
	return 0;
}
