#include<iostream>
#include<cstdio>
using namespace std;
typedef double db;
const int maxn=1e5,INF=~0U>>1;
struct Node
{
	db weight;
	int parent,lson,rson;
};
struct Tree
{
	Node ht[maxn];
	int root;
};
typedef Tree* pTree;
typedef Node* pNode;
db a[maxn];
pTree Huffman(int);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
	}
	pTree p=Huffman(n);
	
	delete p;
	return 0;
}
pTree Huffman(int n)
{
	pTree pht;
	int i,j,p1,p2;
	db min1,min2;
	if(n<=1) return NULL;
	pht=new Tree;
	//pht->ht=new Node;
	for(i=0;i<2*n-1;i++)
	{
		pht->ht[i].parent=0;
		if(i<n) pht->ht[i].weight=a[i];
		else pht->ht[i].weight=-1;
	}
	for(i=0;i<n;i++)
	{
		p1=p2=0;
		min1=min2=INF;
		for(j=0;j<n+i;j++)
		{
			if(pht->ht[j].parent==0)
			{
				if(pht->ht[j].weight<min1)
				{
					min2=min1;
					min1=pht->ht[j].weight;
					p2=p1;
					p1=j;
				}
				else if(pht->ht[j].weight<min2)
				{
					min2=pht->ht[j].weight;
					p2=j;
				}
			}
		}
		pht->ht[p1].parent=pht->ht[p2].parent=n+i;
		pht->ht[n+i].weight=min1+min2;
		pht->ht[n+i].lson=p1;
		pht->ht[n+i].rson=p2;
	}
	return pht;
}