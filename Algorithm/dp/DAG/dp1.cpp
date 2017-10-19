//2017-03-28 spaceskynet ����Ƕ�� dp���� DAG 
#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e3+10;
struct marix
{
	int x,y;
	bool operator > (const marix a) const
	{
		return (this->x>a.x)&&(this->y>a.y);
	}
	void swap()
	{
		if(this->x>this->y) this->x^=this->y,this->y^=this->x,this->x^=this->y;	
	}
}f[maxn];
int a[maxn],t,n;
int dp(int);
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&f[i].x,&f[i].y);
			f[i].swap();
		}
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=dp(i),ans=max(ans,a[i]);
		printf("%d",ans);
	}
	return 0;
}
int dp(int i)
{
	int &ans=a[i];
	if(ans>0) return ans;
	ans=1;
	for(int j=1;j<=n;j++)
	{
		if(f[i]>f[j]) ans=max(ans,dp(j)+1);
	}
	return ans;
}
/*
����Ƕ��
ʱ�����ƣ�3000 ms  |           �ڴ����ƣ�65535 KB
�Ѷȣ�4

����
    ��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ���ھ���Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ������磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С����������ѡ�������ܶ�ľ����ų�һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ�

    ����
        ��һ����һ������N(0<N<10)����ʾ��������������
        ÿ��������ݵĵ�һ����һ��������n����ʾ������������к��о��εĸ���(n<=1000)
        ����n�У�ÿ����������a,b(0<a,b<100)����ʾ���εĳ��Ϳ�
    ���
        ÿ��������ݶ����һ��������ʾ�����������ľ�����Ŀ��ÿ�����ռһ��
    ��������

        1
        10
        1 2
        2 4
        5 8
        6 10
        7 9
        3 1
        5 8
        12 10
        9 7
        2 2

    �������

        5

*/
