#include<cstdio>
#include<ctime>
const int MAXN=1e4;
void in(int);
void maopao(int);
void out(int);
int a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	in(n);
	double t1=(double)clock()/CLOCKS_PER_SEC;
	maopao(n);
	double t2=(double)clock()/CLOCKS_PER_SEC;
	printf("Times: %.4lf s\n",(double)(t2-t1));
	return 0;
}
void in(int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void maopao(int n)
{
	int tmp;
	for(int i=0;i<n-1;i++)
	{
		bool flag=0;
		for(int j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
				flag=1;
			}	
		}
		if(!flag) break;
		printf("%d:",i+1);
		out(n);
	}
}
inline void out(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
