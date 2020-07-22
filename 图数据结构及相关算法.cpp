#include<iostream>
#include<algorithm>
using namespace std;
#define MAXV 5


//����
typedef struct 
{
   int data[MAXV];
   int front,rear;
}SqQueue;


//��ʼ������

void InitQueue(SqQueue *&q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
}

//���ٶ���
void DestroyQueue(SqQueue *&q)
{
    free(q);
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *&q)
{
    return (q->front==q->rear);
}

//������

bool enQueue(SqQueue *&q,int e)
{
    if(q->rear==MAXV-1)
        return false;
    q->rear++;
    q->data[q->rear]=e;
    return true;
}

//������

bool deQueue(SqQueue *&q,int e)
{
    if(q->rear==q->front)
        return false;
    q->front++;
    e=q->data[q->front];
    return false;
}


//�ڽӾ���Ĵ洢������
typedef struct 
{
   int no;      //����ı�� 
}VertexType;    //���������


typedef struct 
{
    int edges[MAXV][MAXV];//�ڽӾ���
    int n,e;//������������
    VertexType vexs[MAXV];//��Ŷ������Ϣ
}MatGraph;//������ͼ�ڽӾ�������

//�ڽӾ���Ĵ洢������

typedef struct ANode
{
    int adjvex;//�õ�ı�ţ�
    struct ANode *nextarc;//ָ����һ���ߵ�ָ�룻
    int weight; //�ߵ�Ȩֵ
}ArcNode;//�߽ڵ������
typedef struct Vnode
{
    ArcNode *firstarc;
}VNode;//�ڽӱ�ͷ�ڵ�����
typedef struct
{
    VNode adjlist[MAXV];//ͷ�ڵ�ļ���
    int n,e;//ͼ�ж���ĸ����ͱߵĸ�����
}AdjGraph;//������ͼ���ڽӱ����ͣ�

//����һ��ͼ
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
{
    int i,j;ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for(i=0;i<n;i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0;i<n;i++)
        for(j=n-1;j>=0;j--)
            if(A[i][j]!=0&&A[i][j]!=INF)
            {
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=j;
                p->weight;
                p->nextarc=G->adjlist[i].firstarc;//����ͷ�巨���룻
                G->adjlist[i].firstarc=p;
            }
            G->n=n;
            G->e=e;
}




//����ڽӱ�
void DispAdj(AdjGraph *G)
{
    int i;ArcNode *p;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            cout<<p->adjvex;
            cout<<p->weight;
            p=p->nextarc;
        }
        cout<<endl;
    }
}





void DestroyAdj(AdjGraph *&G)//�����б�
{
    int i;ArcNode *p,*pre;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            pre=p->nextarc;
            free(p);
            p=pre;
        }
    }
    free(G);
}

//ͼ�ı���


//������ȱ���

int visited[MAXV]={0};
void DFS(AdjGraph *&G,int v)
{
    ArcNode *p;
    visited[v]=1;
    cout<<v;
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
        p=p->nextarc;
    }
}


//������ȱ���
void BFS(AdjGraph *G,int v)
{
    int w,i;ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];      //��һ����ǣ�
    for(int i=0;i<G->n;i++)visited[MAXV];//��ʼ��Ϊ�㣻
    cout<<v;
    enQueue(qu,v);
    while (!(QueueEmpty(qu)))
    {
       deQueue(qu,w);//��ջ��
       p=G->adjlist[w].firstarc;
       while (p!=NULL)
       {
           if(visited[p->adjvex]==0)
           {
                cout<<p->adjvex;
                enQueue(qu,p->adjvex);
                visited[p->adjvex]=1;
           }
           p=p->nextarc;
       }
    }
      cout<<endl;
}

//Dijkstra�㷨


void Dijkstra(MatGraph g,int v)//g���ڽӾ���q
{
    int dist[MAXV],path[MAXV];
    int S[MAXV];    //S[i]=1��ʾi����S�У�S[i]=0��ʾi����U��;
    int MINdis,i,j,u;
    for(i=0;i<g.n;i++)//��ʼ��;
    {
        dist[i]=g.edges[v][i]//�����ʼ����
        S[i]=0;     //S[]�ÿգ�
        if(g.edges[v][i]<INF)
            path[i]=v;
        else
            path[i]=-1;
    }
    S[v]=1;
    path[v]=0;


    for(i=0;i<g.n-1;i++)//ѭ����ֱ�����ж�������·���������
    {
        MINdis=INF;
        for(j=0;j<g.n;i++)
        {
            if(S[i]==0&&dist[j]<MINdis)
            {
                u=j;
                MINdis=dist[j];
            }
        }
        S[u]=1;
        for(j=0;j<g.n;j++)
        {
            if(S[j]==0)
                if(g.edges[u][j]<INF&&dist[u]+g.edges[u][j]<dist[j])
                {
                    dist[j]=dist[u]+g.edges[u][j];
                    path[j]=u;
                }
        }
    }
}





//�����ԭ���·��;

void Dispath(MatGraph g,int dist[],int path[],int S[],int v)
{
    //�����v��������������·��;
    int i,j,k;
    int apath[MAXV],d;//���һ�����·�������䶥��ĸ���;
    for(i=0;i<g.n;i++)//ѭ������Ӷ���v��i��·��;
        if(S[i]==1&&i!=v)
        {
            d=0;apath[d]=i;
            k=path[i];
            if(k==-1)
                cout<<"��·��"<<endl;
            else
            {
                while (k!=v)
                {
                    d++;apath[d]=k;
                    k=path[k];
                }
                d++;apath[d]=v;
                for(j=d-1;j>=0;j--)
                    cout<<apath[j];
                cout<<endl;
            }
        }
}


//prim�㷨
void prim(MatGraph g,int v)
{
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV],i,j,k;
    for(i=0;i<g.n;i++)
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for(i=1;i<g.n;i++)
    {
        MIN=INF;
        for(j=0;j<g.n;j++)
            if(lowcost[j]!=0&&lowcost[j]<MIN)
            {
                MIN=lowcost[j];
                k=j;
            }
        cout<<closest[k]<<","<<k<<endl;
        lowcost[k]=0;
        for(j=0;j<g.n;j++)
            if(lowcost[j]!=0&&g.edges[k][j]<lowcost[j])
            {
                lowcost[j]=g.edges[k][j];
                closest[j]=k;
            }
    }
}

typedef struct 
{
    int u;//�ߵ�ʼ��
    int v;//�ߵ��յ�
    int w;//�ߵ�Ȩֵ
}Edge;



//Kruskal
void Kruskal(MatGraph g)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[MAXV];
    Edge E[MAXV];//���ͼ�еı�
    k=0;
    for(i=0;i<g.n;i++)
        for(j=0;j<=i;j++)
            if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
            {
                E[k].u=i;
                E[k].v=j;
                E[k].w=g.edges[i][j];
                k++;
            }
    InserSort(E,g.e);//E�����ǰ�Ȩֵ������˳��
    for(i=0;i<g.n;i++)//��ʼ����������
        vset[i]=i;
    k=1;    //k��ʾ��ǰ�����������ĵڼ�����
    j=0;    //E�е��±�
    while(k<g.n)
    {
        u1=E[j].u;
        v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        if(sn1!=sn2)
        {
            cout<<"sc"<<endl;
            k++;
            for(i=0;i<g.n;i++)
                if(vset[i]==sn2)
                    vset[i]=sn1;
        }
        j++;
    }
}


//��������
void InserSort(Edge E,int n)
{

}

//�Ľ���Kruskal;

