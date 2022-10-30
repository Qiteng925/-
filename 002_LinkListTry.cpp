#include"002_Fun.cpp"

int main()
{
/*   int e;

    LinkList L1;
    Initlist(&L1);

    CreateList_T(L1, 4);

    VisitList(L1, 4);

    LinkList position_ip;

    int position_data;

    position_data = LocateElem_data(L1, 3);
    position_ip = LocateElem_ip(L1, 3);
    printf("%d\n", position_data);
    printf("%d, %d\n", position_ip->data, position_ip);
    

    ListInser_L(L1, 3, 6);

    GetElem(L1, 3, &e);
    printf("%d\n", e);

    ListDelete(L1, 3, &e);
    printf("%d\n", e);

    GetElem(L1, 3, &e);
    printf("%d\n", e);

    ListClear(L1);
    printf("%d\n", L1->next); 

    LinkList L2, L3;
    Initlist(&L2);
    Initlist(&L3);

    CreateCircularList_T(&L2, 4);
    CreateCircularList_T(&L3, 4);

    LinkList T;
    T = Connect(L2, L3);
    VisitList_C(T, 8); */

    DoubleLinkList L4;
    InitDoubleLinkList(&L4);

    Create_DoubleLinklist_H(L4, 4);
    
    DLInsert(L4, 2, 6);
    printf("%d\n", L4->next->next->data);

    DLDelete(L4, 2);
}

