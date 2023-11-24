#include<stdio.h>
#include<stdlib.h>
#define  MAX_VERTEX_NUM 20 //图中顶点的最大数量
#define  InfoType int*     //表示弧额外信息的数据类型
#define  VertexType char    //图中顶点的数据类型
//表示链表中存储弧的结点
typedef struct ArcBox {
    int tailvex, headvex;          //弧尾、弧头对应顶点在顺序表中的位置下标
    struct ArcBox* hlik, * tlink;  //hlik指向下一个以当前顶点为弧头的弧结点；
                                   //tlink 指向下一个以当前顶点为弧尾的弧结点；
    //InfoType info;               //存储弧相关信息的指针
}ArcBox;

//表示顺序表中的各个顶点
typedef struct VexNode {
    VertexType data;              //顶点的数据域
    ArcBox* firstin, * firstout;  //指向以该顶点为弧头和弧尾的链表首个结点
}VexNode;

//表示十字链表存储结构
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];  //存储顶点的顺序表
    int vexnum, arcnum;             //记录图的顶点数和弧数
}OLGraph;

int LocateVex(OLGraph* G, VertexType v) {
    int i;
    //遍历一维数组，找到变量v
    for (i = 0; i < G->vexnum; i++) {
        if (G->xlist[i].data == v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回 -1
    if (i > G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

//构建十字链表存储结构
void CreateDG(OLGraph* G) {
    int i, j, k;
    VertexType v1, v2;
    ArcBox* p = NULL;
    //输入有向图的顶点数和弧数
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    getchar();
    //使用一维数组存储顶点数据，初始化指针域为NULL
    for (i = 0; i < G->vexnum; i++) {
        scanf("%c", &(G->xlist[i].data));
        getchar();
        G->xlist[i].firstin = NULL;
        G->xlist[i].firstout = NULL;
    }
    //存储图中的所有弧
    for (k = 0; k < G->arcnum; k++) {
        scanf("%c %c", &v1, &v2);
        getchar();
        //确定v1、v2在数组中的位置下标
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        //建立弧的结点
        p = (ArcBox*)malloc(sizeof(ArcBox));
        p->tailvex = i;
        p->headvex = j;
        //采用头插法插入新的p结点
        p->hlik = G->xlist[j].firstin;
        p->tlink = G->xlist[i].firstout;
        G->xlist[j].firstin = G->xlist[i].firstout = p;
    }
}

//计算某顶点的入度
int indegree(OLGraph* G, VertexType x) {
    int i;
    int num = 0;
    //遍历整个顺序表
    for (i = 0; i < G->vexnum; i++) {
        //找到目标顶点
        if (x == G->xlist[i].data) {
            //从该顶点的 firstin 指针所指的结点开始遍历
            ArcBox* p = G->xlist[i].firstin;
            while (p)
            {
                num++;
                //遍历 hlink 指针指向的下一个结点
                p = p->hlik;
            }
            break;
        }
    }
    if (i == G->vexnum) {
        printf("图中没有指定顶点\n");
        return -1;
    }
    return num;
}

//计算某顶点的出度
int outdegree(OLGraph* G, VertexType x) {
    int i;
    int num = 0;
    //遍历整个顺序表
    for (i = 0; i < G->vexnum; i++) {
        //找到目标顶点
        if (x == G->xlist[i].data) {
            //从该顶点的 firstout 指针所指的结点开始遍历
            ArcBox* p = G->xlist[i].firstout;
            while (p)
            {
                num++;
                //遍历 tlink 指针指向的下一个结点
                p = p->tlink;
            }
            break;
        }
    }
    if (i == G->vexnum) {
        printf("图中没有指定顶点\n");
        return -1;
    }
    return num;
}

//删除十字链表结构
//每个顶点配备两个链表，选定一个链表（比如 firstout 所指链表），删除每个顶点中 firstout 所指链表上的结点
void DeleteDG(OLGraph* G) {
    int i;
    ArcBox* p = NULL, * del = NULL;
    for (i = 0; i < G->vexnum; i++) {
        p = G->xlist[i].firstout;
        while (p) {
            del = p;
            p = p->tlink;
            free(del);
        }
        //将第 i 个位置的两个指针全部置为 NULL，能有效避免出现野指针
        G->xlist[i].firstout = NULL;
        G->xlist[i].firstin = NULL;
    }
}
int main() {
    OLGraph G;
    CreateDG(&G);
    printf("A 顶点的入度为 %d\n", indegree(&G, 'A'));
    printf("A 顶点的出度为 %d\n", outdegree(&G, 'A'));
    DeleteDG(&G);
    return 0;
}