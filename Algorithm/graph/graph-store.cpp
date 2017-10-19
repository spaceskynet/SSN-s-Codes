#include<iostream>
#include<string>
#define MAX_VERTEX_NUM 20
using namespace std;
int vaxs[100];
template<class T>
struct MGraph
{
	string vexs[MAX_VERTEX_NUM];//顶点数组
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
	int vexnum;//顶点数目
	int arcnum;//边数目
};
//表结点
struct ArcNode
{
	int adjvex; //弧所指向顶点的位置
	ArcNode *nextarc;// 指向下一条弧
};

//头结点
typedef struct VNode
{
	string data;//顶点名
	ArcNode *firstarc;//指向第一条关联顶点的弧
} AdjList[MAX_VERTEX_NUM];

struct ALGraph
{
	AdjList vertices;//头结点数组
	int vexnum;
	int arcnum;
} A[100];
struct ArcBox
{
	int tailvex,headvex;//弧结点头尾结点位置
	ArcBox *hlink,*tlink;//弧头和弧尾相同的弧的链域
};

//顶点结点
struct VexNode
{
	string data;
	ArcBox *firstin,*firstout;//顶点第一条入弧和出弧
};

struct OLGraph
{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
};
int Locate_Vex(T G,string x) //定位顶点位置
{
	int k=0;
	for(;G.vexs[k]!=x; k++);
	return k;
}

//邻接矩阵存储图


void CreateUDN_MG(MGraph &G)
{
	//采用邻接矩阵表示法，构造无向网
	cin>>G.vexnum>>G.arcnum;
	for(int i=0; i<G.vexnum; i++)
		cin>>vaxs[i];

	for(int i=0; i<G.vexnum; i++)
		for(int j=0; j<G.vexnum; j++)
			G.arcs[i][j]=-1;
	//上面是初始化邻接矩阵，-1表示两点间边的权值为无穷大

	for(int k=0,i,j; k<G.arcnum; k++)
	{
		string v1,v2;
		int w;
		cin>>v1>>v2>>w;
		i=Locate_Vex(G,v1);
		j=Locate_Vex(G,v2);
		while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1)
		{
			cout<<"结点位置输入错误,重新输入: ";
			cin>>v1>>v2>>w;
			i=Locate_Vex(G,v1);
			j=Locate_Vex(G,v2);
		}
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j]; //置对称边
	}
}

//邻接表存储图


void CreateDG_ALG(ALGraph &G)
{
	//采用邻接表存储表示，构造有向图G
	string v1,v2;
	int i,j,k;
	cin>>G.arcnum>>G.vexnum;

	//构造头结点数组
	for(i=0; i<G.vexnum; i++)
	{
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}

	//输入各弧并构造邻接表
	for(k=0; k<G.arcnum; k++)
	{
		cin>>v1>>v2;
		i=Locate_Vex(G,v1);
		j=Locate_Vex(G,v2);
		while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1)
		{
			cout<<"结点位置输入错误,重新输入: ";
			cin>>v1>>v2;
			i=Locate_Vex(G,v1);
			j=Locate_Vex(G,v2);
		}

		ArcNode *p=new ArcNode;
		p->adjvex=j;
		p->nextarc=NULL;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
	}
}

//十字链表方式存储有向图
//弧结点

void CreateDG_OLG(OLGraph &G)
{
	//采用十字链表存储表示，构造有向图G
	string v1,v2;
	int i,j,k;
	cin>>G.vexnum>>G.arcnum;
	for(i=0; i<G.vexnum; i++)
	{
		cin>>G.xlist[i].data;
		G.xlist[i].firstin=NULL;
		G.xlist[i].firstout=NULL;
	}
	for(k=0; k<G.arcnum; k++)
	{
		cin>>v1>>v2;
		i=Locate_Vex(G,v1);
		j=Locate_Vex(G,v2);

		while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1)
		{
			cout<<"结点位置输入错误,重新输入: ";
			cin>>v1>>v2;
			i=Locate_Vex(G,v1);
			j=Locate_Vex(G,v2);
		}

		ArcBox *p=new ArcBox;
		p->tailvex=i;
		p->headvex=j;
		p->hlink=G.xlist[j].firstin;
		p->tlink=G.xlist[i].firstout;
		G.xlist[i].firstout=G.xlist[j].firstin=p;
	}
}

//邻接多重表存储
//边结点
struct EBox
{
	int mark;//标志域，指示该边是否被访问过(0:没有 1:有)
	int ivex,jvex;//该边关联的两个顶点的位置
	EBox *ilink,*jlink;//分别指向关联这两个顶点的下一条边
};

//顶点结点
struct VexBox
{
	string data;
	EBox *firstedge;//指向第一条关联该结点的边
};

struct AMLGraph
{
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
};

void CreateUDG_AML(AMLGraph &G)
{
	//用邻接多重表存储，构造无向图G
	string v1,v2;
	int i,j,k;
	cin>>G.vexnum>>G.arcnum;
	for(i=0; i<G.vexnum; i++)
	{
		cin>>G.adjmulist[i].data;
		G.adjmulist[i].firstedge=NULL;
	}

	for(k=0; k<G.arcnum; k++)
	{
		cin>>v1>>v2;
		i=Locate_Vex(G,v1);
		j=Locate_Vex(G,v2);

		while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1)
		{
			cout<<"结点位置输入错误,重新输入: ";
			cin>>v1>>v2;
			i=Locate_Vex(G,v1);
			j=Locate_Vex(G,v2);
		}

		EBox *p=new EBox;
		p->ivex=i;
		p->jvex=j;
		p->ilink=G.adjmulist[i].firstedge;
		p->jlink=G.adjmulist[j].firstedge;
		p->mark=0;
		G.adjmulist[i].firstedge=G.adjmulist[j].firstedge=p;
	}
}
int main()
{

	CreateDG_ALG(ALGraph &A[0])
	return 0;
}

