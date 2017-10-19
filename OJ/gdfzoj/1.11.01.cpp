#include<iostream>
#include<cmath>
using namespace std;
int a[100001]={0},b[10001]={0};
void work(int,int,int);
void readn(int i)
{
	int j=0;
	while(i)
	{
		i--;
		cin>>a[j];
		j++;
	}
}
void readm(int i,int k)
{
	int j=0,tmpp=0;
	while(i)
	{
		i--;
		cin>>tmpp;
		work(tmpp,k,j);
		j++;		
	}
}
void work(int i,int k,int x)
{
	int tmp=0;
	if(i>a[k/2])
	{ 
		tmp=i-a[k/2];
		for(int y=k/2+1;;y++)
		{
			if(tmp>abs(i-a[y]))
			{
				tmp=abs(i-a[y]);
				b[x]=a[y];
			}
			if(tmp<=abs(i-a[y]))
			{
				break;
			}
		}
	}
	else if(i<a[k/2])
	{
		tmp=a[k/2]-i;
		for(int y=k/2-1;;y--)
		{
			if(tmp>abs(i-a[y]))
			{
				tmp=abs(i-a[y]);
				b[x]=a[y];
			}
			if(tmp<=abs(i-a[y]))
			{
				b[x]=a[y-1];
				break;
			}
		}	
	}
	else
	{
		b[x]=i;
	}
}
void out(int m)
{
	for(int i=0;i<m;i++)
	{
		cout<<b[i]<<endl;
	}
}
int main()
{
	int n=0,m=0;
	cin>>n;
	readn(n);
	cin>>m;
	readm(m,n);
	out(m);
	return 0;
}
