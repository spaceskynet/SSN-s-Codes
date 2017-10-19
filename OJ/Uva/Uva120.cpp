#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[32],b[32];
void swap(int,int);
int main()
{
	int n;
	while(scanf("%d",&a[0])!=EOF)
	{
		n=1;
		if(getchar()!='\n')
		{
			while(scanf("%d",&a[n++]))
			{
				if(getchar()=='\n') break;
			}
		}
		for(int i=0;i<n;i++)
		{
			b[i]=a[i];
			printf("%d ",a[i]);
		}
		printf("\n");
		sort(b+0,b+n);
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==b[i]) continue;
			for(int j=i-1;j>=0;j--)
			{
				if(b[i]==a[j])
				{
					if(j==0)
					{
						printf("%d ",n-i);
						swap(0,i);
					}
					else
					{
						printf("%d ",n-j);
						swap(0,j);
						printf("%d ",n-i);
						swap(0,i);
					}
				}
			}
		}
		printf("0\n");
	}
	return 0;
}
void swap(int x,int y)
{
	while(x<y) 
	{
		a[x]^=a[y];a[y]^=a[x];a[x]^=a[y];
		x++;
		y--;
	}
}