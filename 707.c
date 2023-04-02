#define NULL 0

typedef struct tMyLinkedList {
    int val;
    struct tMyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* ptr = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    ptr->val = 0;
    ptr->next = NULL;
    return ptr;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int nRes = -1;
    int nCount = 0;
    MyLinkedList* ptmp = obj;

    while (ptmp->next)
    {
        if (nCount == index)
        {
            nRes = ptmp->val;
            break;
        }
        ptmp = ptmp->next;
        nCount++;
    }

    return nRes;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* ptNode = myLinkedListCreate();

    ptNode->val = val;
    ptNode->next = obj->next;
    obj->next = ptNode;

    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* ptNode = myLinkedListCreate();
    MyLinkedList* ptmp = obj;

    ptNode->val = val;
    while (ptmp->next)
    {
        if (NULL == ptmp->next)
        {
            ptmp->next = ptNode;
            break;
        }
    }

    return;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* ptmp = obj;
    MyLinkedList* ptmpB = obj;
    MyLinkedList* ptNode = NULL;
    int nCount = 0;

    while (ptmp->next)
    {
        if (nCount == index)
        {
            ptNode = myLinkedListCreate();
            ptNode->val = val;
            ptmp->next = ptNode;
        }
        else if (nCount < index)
        {
            ptNode = myLinkedListCreate();
            ptNode->val = val;
            ptNode->next = ptmp;
            ptmpB->next = ptNode;
        }
        ptmpB = ptmp;
        ptmp = ptmp->next;
        nCount++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* ptmp = obj;
    MyLinkedList* ptmpB = obj;
    int nCount = 0;

    while (ptmp->next)
    {
        if (index == nCount)
        {
            ptmpB->next = ptmp->next;
            free(ptmp);
            ptmp = NULL;
            break;
        }
        ptmpB = ptmp;
        ptmp = ptmp->next;
        nCount++;
    }

    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* ptmp = obj;
    MyLinkedList* ptmpB = obj;

    while (ptmp->next)
    {
        ptmpB = ptmp;
        free(ptmpB);
        ptmpB = NULL;
        ptmp = ptmp->next;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/