#include<cstdio>
const int maxn=1e5;
int heap[maxn],hs=0;
void build();
void sink(int);
void swim(int);
int delmin();
void insert(int);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&heap[i]);
	}
	hs=n;
	build();
	for(int i=1;i<=n;i++)
	{
		printf("%d ",delmin());
	}
	return 0;
}
void build()
{
	for(int i=(hs>>1);i>0;i--)
	{
		sink(i);
	}
}
void sink(int p)
{
	int q=p<<1,a=heap[p];
	while(q<=hs)
	{
		while(q<hs&&heap[q]>heap[q+1]) q++;
		if(heap[q]>a) break;
		heap[p]=heap[q];
		p=q;
		q=p<<1;
	}
	heap[p]=a;
}
int delmin()
{
	int r=heap[1];
	heap[1]=heap[hs--];
	sink(1);
	return r;
}
void swim(int p)
{
	int q=p>>1,a=heap[p];
	while(q&&heap[q]>a)
	{
		heap[p]=heap[q];
		p=q;
		q=p>>1;
	}
	heap[p]=a;
}
void insert(int val)
{
	heap[++hs]=val;
	swim(hs);
}


