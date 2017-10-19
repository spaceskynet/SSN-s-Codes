//简单选择排序
#include<cstdio>
#include<ctime>
const int MAXN=1e4;
void in(int);
void spchoose(int);
void out(int);
int a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	in(n);
	double t1=(double)clock()/CLOCKS_PER_SEC;
	spchoose(n);
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
void spchoose(int n)
{
	for(int i=1;i<n;i++)
	{
		int tmp=0;
		int pos=i;
		for(int j=i+1;j<=n;j++)
		{
			if(a[pos]>a[j])
			{
				pos=j;
			}
		}
		tmp=a[pos];
		a[pos]=a[i];
		a[i]=tmp;
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
