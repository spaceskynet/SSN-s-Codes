//直接插入排序
#include<cstdio>
#include<ctime>
const int MAXN=1e4;
void in(int);
void incut(int);
void out(int);
int a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	in(n);
	double t1=(double)clock()/CLOCKS_PER_SEC;
	incut(n);
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
void incut(int n)
{
	for(int i=1;i<=n;i++)
	{
		int j=0,tmp=a[i];
		for(j=i-1;j>=0&&tmp<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=tmp;
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
