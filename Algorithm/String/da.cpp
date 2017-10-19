#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5e4+10;
int xa[maxn],xb[maxn],xv[maxn],xs[maxn],n,sa[maxn],r[maxn],rank[maxn],h[maxn];
char str[maxn];
void da(int*,int*,int,int);
bool cmp(int*,int,int,int);
void calheight(int*,int*,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		n=strlen(str);
		for(int i=0;i<n;i++) r[i]=str[i];
		r[n]=0;
		da(r,sa,n+1,128);
		calheight(r,sa,n);
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=n+1-(sa[i]+1)-h[i];
		printf("%lld\n",ans);
	}
	return 0;
}
void da(int *r,int *sa,int n,int m)
{
	int i,j,p,*x=xa,*y=xb,*t;
	for(i=0;i<m;i++) xs[i]=0;
	for(i=0;i<n;i++) xs[x[i]=r[i]]++;
	for(i=1;i<m;i++) xs[i]+=xs[i-1];
	for(i=n-1;i>=0;i--) sa[--xs[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p)
	{
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) xv[i]=x[y[i]];
		for(i=0;i<m;i++) xs[i]=0;
		for(i=0;i<n;i++) xs[xv[i]]++;
		for(i=0;i<m;i++) xs[i]+=xs[i-1];
		for(i=n-1;i>=0;i--) sa[--xs[xv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void calheight(int *r,int *sa,int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	for(i=0;i<n;h[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
