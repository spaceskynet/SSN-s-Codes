#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int n,a,sum=0,m1=0,m2=0,ans=0,res=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum+=a;
		res+=a;
		if(res>m1) m1=res;
		if(res<0) res=0;
		ans-=a;
		if(ans>m2) m2=ans;
		if(ans<0) ans=0;
	}
	printf("%d",max(m1,sum+m2));
	return 0;
}
