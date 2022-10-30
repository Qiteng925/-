#include"001_ListFun.cpp"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Sqlist L1;
    InitSL(&L1, 4);

    int length = Getlength(&L1);                     //使用struct中的变量
    printf("Length is : %d.\n", length);             

    int IsEmptynum = IsEmpty(&L1);
    printf("IsEmptynum is : %d.\n", IsEmptynum);

    int elem;
    GetElem(&L1, &elem, 2); 
    printf("Elem whom was gotte just now is : %d.\n", elem);              //初始化又使用变量地址

    ListInsert(&L1, 5, 1);
    int c = L1.elem[1];
    //输出插入元素和超出数组长度位置的元素
    printf("Number 2 and Number 5 is : %d and %d.\n", L1.elem[1], L1.elem[4]);

    int status = ListDelete(&L1, 1);
    //判断是否删除成功
    printf("Status is :%d.\n", status);

    status = ChangeElem(&L1, 6, 1);
    //判断成功与否并输出该位置元素
    printf("Yes Or Not : %d.The Elem is : %d.\n", status, L1.elem[1]);

    int position;
    position = LocateElem(&L1, 6);
    //输出元素位置
    printf("The Position Is : %d.\n", position);

    free(L1.elem);
    
    return 0;
}