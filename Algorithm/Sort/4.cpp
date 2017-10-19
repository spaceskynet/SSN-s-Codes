//希尔排序
#include<cstdio>
#include<ctime>
const int MAXN=1e4;
void in(int);
void xier(int);
void out(int);
int a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	in(n);
	double t1=(double)clock()/CLOCKS_PER_SEC;
	xier(n);
	double t2=(double)clock()/CLOCKS_PER_SEC;
	printf("Times: %.4lf s\n",(double)(t2-t1));
	return 0;
}
void in(int n)
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void xier(int n)
{
	int gap=n>>1;
	while(1<=gap)
	{
		for(int i=gap;i<=n;i++)
		{
			int j=0,tmp=a[i];
			for(j=i-gap;j>=0&&tmp<a[j];j-=gap)
			{
				a[j+gap]=a[j];
			}
			a[j+gap]=tmp;
		}
		gap>>=1;
	}
	out(n);
}
inline void out(int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
