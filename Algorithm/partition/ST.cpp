#include<cstdio>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
const int MAXN=1e6;
int Log[MAXN],a[MAXN],qmax[MAXN][20],qmin[MAXN][20];
int fmax(int,int);
int fmin(int,int);
int main()
{
	int n;
	printf("Input data: ");
	scanf("%d",&n);
	Log[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		Log[i]=Log[i>>1]+1;
		qmax[i][0]=qmin[i][0]=a[i];
	}
	for(int j=1;j<=Log[n];j++)
	{
		for(int i=1;i<=(n-(1<<j)+1);i++)
		{
			qmax[i][j]=max(qmax[i][j-1],qmax[i+(1<<(j-1))][j-1]);
			qmin[i][j]=min(qmin[i][j-1],qmin[i+(1<<(j-1))][j-1]);
		}
	}
	printf("Input l,r:");
	int l,r;
	scanf("%d%d",&l,&r);
	printf("Choose max or min:");
	char str[10];
	scanf("%s",str);
	switch(str[1])
	{
		case'a':
			printf("%d",fmax(l,r));break;
		case'i':
			printf("%d",fmin(l,r));break;
	}
	return 0;
}
int fmax(int l,int r)
{
	int k=Log[r-l+1];
	return max(qmax[l][k],qmax[r-(1<<k)+1][k]);
}
int fmin(int l,int r)
{
	int k=Log[r-l+1];
	return min(qmin[l][k],qmin[r-(1<<k)+1][k]);
}