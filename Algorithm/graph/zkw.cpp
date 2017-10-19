#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5;
class zkw
{
public:
	zkw()
	{
		m=1;
	}
	void build(int n)//�����
	{
		for(;m<n;m<<=1);
		//m<<=1;//�����˵�ֵ����
		for(int i=m+1;i<n+m+1;i++) scanf("%d",&a[i]);//��m+1Ҷ�ӽڵ㿪ʼ�������ѯ[1,...]ʱ����
		for(int i=m-1;i;--i) a[i]=a[i<<1]+a[i<<1|1];
		/**��ֽ���
		for(int i=m-1;i;--i)
		{
			a[i]=min(a[i<<1],a[i<<1|1]);
			a[i<<1]-=a[i],a[i<<1|1]-=a[i];
		}
		**/
	}
	int query(int l,int r)
	{
		int ans=0;
		for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)
		{
			if(~l&1) ans+=a[l^1];
			if(r&1) ans+=a[r^1];
		}
		/************
		int mid=max(l,r);
		while(mid)
		{
			ans+=a[mid>>=1];//���ʱ��Ҫ��ס�ع飬��Ҫֻ����ֵmax���
		}
		*************/
		return ans;
	}
	void updata(int pos,int val)
	{
		a[pos+=m]+=val;
		while(pos)
		{
			a[pos>>=1]=a[pos<<1]+a[pos<<1|1];
		}
	}
	void intervalup(int l,int r,int val)
	{
		int tmp=0;
		for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)
		{
			if(~l&1) a[l^1]+=val;
			if(r&1) a[r^1]+=val;
			tmp=min(a[l],a[l^1]),a[l]-=tmp,a[l^1]-=tmp,a[l>>1]+=tmp;
			tmp=min(a[r],a[r^1]),a[r]-=tmp,a[r^1]-=tmp,a[r>>1]+=tmp;
		}
		while(l) tmp=min(a[l],a[l^1]),a[l]-=tmp,a[l^1]-=tmp,a[l>>=1]+=tmp;
	}
	int point(int x)//��ֵ����ѯ
	{
		int ans=0;
		while(x) 
		{
			ans+=a[x],x>>=1;
		}
		return ans;
	}
private:
	int a[2*maxn+2],m;
};
int f[maxn],n;
zkw tree;
int main()
{
	scanf("%d",&n);
	tree.build(n);
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%d\n",tree.query(l,r));
	tree.intervalup(l,r,1);
	printf("%d\n",tree.query(l,r));
	return 0;
}
