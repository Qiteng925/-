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

typedef struct
{
    ElemType *elem;
    int length;
} Sqlist;

int InitSL(Sqlist *L, int nums)
{
    L->elem = (int *)malloc(sizeof(int) * SQLMAXSIZE);
    if (!L->elem)
    {
        return OVERFLOW;
    }
    L->length = 0;
    for (int i = 0; i < nums; i++)
    {
        scanf("%d", &L->elem[i]);
        L->length++;
    }
    return OK;
}

Status DestoryList(Sqlist *L)
{
    if (!L->elem)
    {
        return ERROR;
    }
    free(L->elem);
    return OK;
}

void ClearList(Sqlist *L)
{
    L->length = 0;
}

int Getlength(Sqlist *L)
{
    return L->length;
}

int IsEmpty(Sqlist *L)
{
    if (L->length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GetElem(Sqlist *L, ElemType *e, int position)
{
    if (position < 0 || position > L->length - 1)
    {
        return OVERFLOW;
    }
    *e = L->elem[position];
    return OK;
}

void resize(Sqlist *L1)
{
    static Sqlist L2;

    L2.elem = (int *)malloc(sizeof(int) * SQLMAXSIZE * 2);
    for (int i = 0; i < SQLMAXSIZE; i++)
    {
        L2.elem[i] = L1->elem[i];
    }

    free(L1->elem);
    L1->elem = NULL;

    L1->elem = (int *)malloc(sizeof(int) * SQLMAXSIZE * 2);
    if (L1->elem == NULL)
    {
        printf("NULL!");
    }
    for (int i = 0; i < SQLMAXSIZE; i++)
    {
        L1->elem[i] = L2.elem[i];
    }
}

void ListInsert(Sqlist *L, ElemType e, int position)
{
    int a = L->length - 1;
    if (L->length >= SQLMAXSIZE)
    {
        resize(L);
    }
    for (int i = a; i >= position; i--) //从选定位置向后移动，（a - 1）为最后元素在数组中位置，（position）为插入元素在数组中位置
    {
        L->elem[i + 1] = L->elem[i]; //逐个交换
        int b = L->elem[i + 1];      //监视变量
    }
    L->elem[position] = e; //赋值
    int c = L->elem[1];    //监视变量elem[1]

    //插入元素位置3种情况均可满足

    L->length++;
}

Status ListDelete(Sqlist *L, int position)
{
    if (position < 0 || position > L->length - 1)
    {
        return ERROR;
    }
    for (int i = position; i <= L->length - 1; i++)
    {
        L->elem[i] = L->elem[i + 1];
    }
    L->length--;
    return OK;
}

Status ChangeElem(Sqlist *L, int e, int position)
{
    if (position < 0 || position > L->length - 1)
    {
        return ERROR;
    }
    L->elem[position] = e;
    return OK;
}

int LocateElem(Sqlist *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i] == e)
        {
            return i;
        }
    }
    return -1;
}
