#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int nmax=100,cmax=100000;
char str[3][10]={"QUERY","CHANGE","DONE"};
int make(int mx);
int main()
{
	srand(time(NULL));
	int t=20;
	printf("%d\n",t);
	while(t--)
	{
		int n=100;
		printf("%d\n",n);
		for(int i=2;i<=n;i++)
		{
			int b=rand()%(i-1)+1,c=rand()%cmax;
			int mi=(cmax*9)/10;
			while(b<=0) b=rand()%(i-1)+1;
			while(c<=mi) c=(rand()*rand())%cmax;
        	printf("%d %d %d\n",i,b,c);
        }
        int x=make(nmax);
        while(x--)
        {
        	int a=rand()%2,b=rand()%n,c=rand()%n;
			while(b<=0) b=rand()%n;
			while(c<=0||c==b) c=rand()%n;
			while(a<0) a=rand()%2;
        	printf("%s %d %d\n",str[a],b,c);
		}
		printf("%s\n",str[2]);
	}
	return 0;
}
inline int make(int mx)
{
	srand(time(NULL));
	int mi=(mx*9)/10,ans=rand()%mx;
	while(ans<=mi)
	{
		ans=(rand()*rand())%mx;
	}
	return ans;
}
