#include <stdio.h>
#include <stdlib.h>

#define SQLMAXSIZE 100
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    LNode *next;

} LNode, *LinkList;

Status Initlist(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

void VisitList(LinkList L, int n)
{
    LinkList p;
    p = L->next;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void VisitList_C(LinkList L, int n)
{
    LinkList p;
    p = L->next->next;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void CreateList_H(LinkList L, int n)
{
    for (int i = 1; i <= n; i++)
    {
        //增加结点
        LinkList p = (LinkList)malloc(sizeof(LNode));

        //置空
        p->next = NULL;

        //输入数据
        scanf("%d", &(p->data));

        //连接上一个结点
        p->next = L->next;
        //头结点连接新结点
        L->next = p;
        (L->data)++;
    }
}

void CreateList_T(LinkList L, int n)
{
    LinkList a = L;
    for (int i = 0; i < n; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));

        //三位操作
        p->next = NULL;
        scanf("%d", &(p->data));
        a->next = p;

        a = a->next;
        (L->data)++;
    }
}

void CreateCircularList_T(LinkList *L, int n)
{
    LinkList a = *L;
    for (int i = 0; i < n; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));

        //三位操作
        p->next = *L;
        scanf("%d", &(p->data));
        a->next = p;

        a = a->next;
        ((*L)->data)++;
    }
    *L = a;
}

Status GetElem(LinkList L, int position, int *e)
{
    if (position < 1 || position > L->data)
    {
        return ERROR;
    }
    LinkList p = L->next;
    for (int i = 1; i < position; i++) //条件依赖于移动几次，(position-1)次，i=1是为了标记指针位置，创造规律便于思考
    {
        p = p->next;
    }
    *e = p->data; //赋值给变量e
    return OK;
}

Status LocateElem_data(LinkList L, ElemType e)
{
    LinkList p = L->next;
    for (int i = 1; i <= L->data; i++)
    {
        if (p->data == e)
        {
            return i;
        }
        p = p->next;
    }
    return NULL;
}

LNode *LocateElem_ip(LinkList L, ElemType e)
{
    LinkList p = L->next;
    for (int i = 1; i <= L->data; i++)
    {
        if (p->data == e)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Status ListInser_L(LinkList L, int position, ElemType e)
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    p->data = e;

    LinkList a = L->next;
    for (int i = 1; i < position - 1; i++)
    {
        a = a->next;
    }
    p->next = a->next;
    a->next = p;
    L->data++;
    return OK;
}

Status ListDelete(LinkList L, int position, ElemType *e)
{
    if (position < 1 || position > L->data)
    {
        return ERROR;
    }
    LinkList a = L->next;
    for (int i = 1; i < position - 1; i++)
    {
        a = a->next;
    }

    //创建指针保存当前位置指针
    LinkList Temporary = a;
    a = a->next;

    //开始算法
    Temporary->next = a->next;
    free(a);
    L->data--;

    return OK;
}

Status ListDestory(LinkList *L)
{
    LinkList p = (*L)->next;
    LinkList pa = (*L)->next;

    for (int i = 1; i <= (*L)->data; i++)
    {
        p = p->next;
        free(pa);
        pa = p;
    }
    (*L) = NULL;
    return OK;
}

Status ListClear(LinkList L)
{
    LinkList p = L->next;
    LinkList pa = L->next;

    for (int i = 1; i <= L->data; i++)
    {
        if (i >= 2)
        {
            free(pa);
            p = p->next;
            pa = p;
        }
    }
    L->next = NULL;
    return OK;
}

LinkList Connect(LinkList L1, LinkList L2)
{
    LinkList a = L2->next; //保存L2头结点位置

    L2->next = L1->next; //连接L2尾部和L1头结点
    L1->next = a->next;  //连接L1尾部和L2头元素

    L2->next->data = a->data + L2->next->data;
    free(a);
    return L2;
}

typedef int DouleElemtype;

typedef struct DouLnode
{
    DouleElemtype data;
    DouLnode *prior;
    DouLnode *next;
} DouLnode, *DoubleLinkList;

void InitDoubleLinkList(DoubleLinkList *L)
{
    (*L) = (DoubleLinkList)malloc(sizeof(DouLnode));
    (*L)->prior = NULL;
    (*L)->next = NULL;
}

void Create_DoubleLinklist_T(DoubleLinkList L, int n)
{
    DoubleLinkList a = L;
    for (int i = 0; i < n; i++)
    {
        DoubleLinkList p;
        p = (DoubleLinkList)malloc(sizeof(DouLnode)); //创造新结点

        scanf("%d", &(p->data));
        a->next = p; //连接
        p->next = NULL;
        p->prior = a;

        a = a->next; //移位
    }
}

void Create_DoubleLinklist_H(DoubleLinkList L, int n)
{
    for (int i = 0; i < n; i++)
    {
        DoubleLinkList p;
        p = (DoubleLinkList)malloc(sizeof(DouLnode)); //创造新结点

        scanf("%d", &(p->data));
        if (i == 0)
        {
            p->prior = L;
            p->next = L->next;
            L->next = p;
        }
        else
        {
            p->prior = L;
            p->next = L->next;
            L->next->prior = p;
            L->next = p;
        }
    }
}

int DLLength(DoubleLinkList L)
{  
    int i = 1;
    DoubleLinkList a = L->next; 
    while (a->next != NULL)
    {
        a = a->next;
        i++;
    }
    return i;
}
Status DLInsert(DoubleLinkList L, int position, DouleElemtype e)
{
    int length = DLLength(L);
    if(position > length)
    {
        return ERROR;
    }
    DoubleLinkList pnew = (DoubleLinkList)malloc(sizeof(DouLnode));
    DoubleLinkList a = L->next;

    for(int i = 1; i < position - 1; i++)
    {
        a = a->next;
    }

    pnew->data = e;

    pnew->prior = a;
    pnew->next = a->next;
    a->next->prior = pnew;
    a->next = pnew;
    return OK;
}

Status DLDelete(DoubleLinkList L, int position)
{
    int length = DLLength(L);
    if(position > length)
    {
        return ERROR;
    }

    DoubleLinkList a = L->next;
        for(int i = 1; i < position - 1; i++)
    {
        a = a->next;
    }

    a->next = a->next->next;
    a->next->next->prior = a;
    return OK;
}

