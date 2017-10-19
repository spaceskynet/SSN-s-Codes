//堆排序
#include<cstdio>
#include<ctime>
const int MAXN=1e4;
void in(int);
void heapSort(int);
void HeapAdjust(int,int,int);
void out(int);
int a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	in(n);
	double t1=(double)clock()/CLOCKS_PER_SEC;
	heapSort(n);
	double t2=(double)clock()/CLOCKS_PER_SEC;
	printf("Times: %.4lf s\n",(double)(t2-t1));
	return 0;
}
void in(int n)
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void HeapAdjust(int n,int parent, int length) 
{
    int temp=a[parent]; // temp保存当前父节点
    int child=(parent<<1)+1; // 先获得左孩子
    while(child<length) 
	{
        // 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
        if (child+1<length&&a[child]<a[child+1]) 
		{
            child++;
		}
        // 如果父结点的值已经大于孩子结点的值，则直接结束
        if (temp>=a[child])
            break;
        // 把孩子结点的值赋给父结点
        a[parent]=a[child];
        // 选取孩子结点的左孩子结点,继续向下筛选
        parent=child;
        child=2*child+1;
    }
    a[parent]=temp;
}
void heapSort(int n) 
{
    // 循环建立初始堆
    for (int i=(n>>1);i>=0;i--) 
	{
        HeapAdjust(n,i,n-1);
    }
    // 进行n-1次循环，完成排序
    for (int i=n-1;i>=0;i--) 
	{
        // 最后一个元素和第一元素进行交换
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        // 筛选 R[0] 结点，得到i-1个结点的堆
        HeapAdjust(n,0,i);
    }
	out(n);
}
inline void out(int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
