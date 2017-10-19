#include<iostream>
#include<string>
#define MAX_VERTEX_NUM 20
using namespace std;
int vaxs[100];
template<class T>
struct MGraph
{
	string vexs[MAX_VERTEX_NUM];//��������
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ���
	int vexnum;//������Ŀ
	int arcnum;//����Ŀ
};
//����
struct ArcNode
{
	int adjvex; //����ָ�򶥵��λ��
	ArcNode *nextarc;// ָ����һ����
};

//ͷ���
typedef struct VNode
{
	string data;//������
	ArcNode *firstarc;//ָ���һ����������Ļ�
} AdjList[MAX_VERTEX_NUM];

struct ALGraph
{
	AdjList vertices;//ͷ�������
	int vexnum;
	int arcnum;
} A[100];
struct ArcBox
{
	int tailvex,headvex;//�����ͷβ���λ��
	ArcBox *hlink,*tlink;//��ͷ�ͻ�β��ͬ�Ļ�������
};

//������
struct VexNode
{
	string data;
	ArcBox *firstin,*firstout;//�����һ���뻡�ͳ���
};

struct OLGraph
{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
};
int Locate_Vex(T G,string x) //��λ����λ��
{
	int k=0;
	for(;G.vexs[k]!=x; k++);
	return k;
}

//�ڽӾ���洢ͼ


void CreateUDN_MG(MGraph &G)
{
	//�����ڽӾ����ʾ��������������
	cin>>G.vexnum>>G.arcnum;
	for(int i=0; i<G.vexnum; i++)
		cin>>vaxs[i];

	for(int i=0; i<G.vexnum; i++)
		for(int j=0; j<G.vexnum; j++)
			G.arcs[i][j]=-1;
	//�����ǳ�ʼ���ڽӾ���-1��ʾ�����ߵ�ȨֵΪ�����

	for(int k=0,i,j; k<G.arcnum; k++)
	{
		string v1,v2;
		int w;
		cin>>v1>>v2>>w;
		i=Locate_Vex(G,v1);
		j=Locate_Vex(G,v2);
		while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1)
		{
			cout<<"���λ���������,��������: ";
			cin>>v1>>v2>>w;
			i=Locate_Vex(G,v1);
			j=Locate_Vex(G,v2);
		}
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j]; //�öԳƱ�
	}
}

//�ڽӱ�洢ͼ


void CreateDG_ALG(ALGraph &G)
{
	//�����ڽӱ�洢��ʾ����������ͼG
	string v1,v2;
	int i,j,k;
	cin>>G.arcnum>>G.vexnum;

	//����ͷ�������
	for(i=0; i<G.vexnum; i++)
	{
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}

	//��������������ڽӱ�
	for(k=0; k<G.arcnum; k++)
	{
		cin>>v1>>v2;
		i=Locate_Vex(G,v1);
		j=Locate_Vex(G,v2);
		while(i<0|| i>G.vexnum-1 || j<0 || j>G.vexnum-1)
		{
			cout<<"���λ���������,��������: ";
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

//ʮ������ʽ�洢����ͼ
//�����

void CreateDG_OLG(OLGraph &G)
{
	//����ʮ������洢��ʾ����������ͼG
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
			cout<<"���λ���������,��������: ";
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

//�ڽӶ��ر�洢
//�߽��
struct EBox
{
	int mark;//��־��ָʾ�ñ��Ƿ񱻷��ʹ�(0:û�� 1:��)
	int ivex,jvex;//�ñ߹��������������λ��
	EBox *ilink,*jlink;//�ֱ�ָ������������������һ����
};

//������
struct VexBox
{
	string data;
	EBox *firstedge;//ָ���һ�������ý��ı�
};

struct AMLGraph
{
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
};

void CreateUDG_AML(AMLGraph &G)
{
	//���ڽӶ��ر�洢����������ͼG
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
			cout<<"���λ���������,��������: ";
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

