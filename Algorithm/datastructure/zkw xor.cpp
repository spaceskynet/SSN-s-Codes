//zkw % water problem 2017-03-28 spaceskynet
#include<cstdio>
const int maxn=1e5;
int a[maxn],m=1;
void build(int);
int query(int,int);
int main()
{
	int n,k,l,r;
	scanf("%d%d",&n,&k);
	build(n);
	while(k--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
void build(int n)
{
	for(;m<=n+1;m<<=1);
	scanf("%d",&a[m+1]);
	for(int i=m+2;i<n+m+1;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	for(int i=m-1;i;--i)
	{
		a[i]=a[i<<1]^a[i<<1|1];
	}
}
int query(int l,int r)
{
	int ans=0;
	for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans^=a[l^1];
		if(r&1) ans^=a[r^1];
	}
	return ans;
}
/*
��m������n��ѯ�ʣ�ÿ��ѯ����һ������[L,R]����һ��kֵ�����������ڵ�ÿ������ai��ki=a1 xor a2 xor...xor a(ai)��
Ҫ��������Ǹ����������k�����ֵ��
���ݷ�Χ��1<m<500000��1<=L<R<=m��1<n<100000��
����:
����:
7 2
3 2 5 6 1 5 3
1 5
2 3
���:
7
5
˵��:
k1=3,k2=3 xor 2=1,k3=3 xor 2 xor 5=4,k4=...
k1 xor k2 xor k3 xor k4 xor k5=5
k2 xor k3=5
*/
