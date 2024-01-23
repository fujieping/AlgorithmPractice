#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "1220_LinkList.h"

enum STATUS_CODEH
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 链表的初始化*/
int ListInit(List **pList)
{
#if 1
    int ret = 0;
    List *list = (List *)malloc(sizeof(List) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(List) * 1);

    list->head = (Nodes *)malloc(sizeof(Nodes) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(Nodes) * 1);
    list->head->data = 0;
    list->head->next = NULL;
    list->tail = list->head;

    list->len = 0;

    *pList = list;

    return ret;
#else
    int ret = 0;
    List *list = (List *)malloc(sizeof(List) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(List) * 1);

    list->head = (Nodes *)malloc(sizeof(Nodes) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(Nodes) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    /* 尾指针初始化*/
    list->tail = list->head;

    /* 链表的长度为0*/
    list->len = 0;

    *pList = list;

    return ret;
#endif
}

/* 链表的头插*/
int ListHeadInsert(List *pList, ELEMENTTYPE val)
{
    ListLocationInsert(pList, 0, val);
}

/* 链表尾插*/
int ListTailInsert(List *pList, ELEMENTTYPE val)
{
    ListLocationInsert(pList, pList->len , val);
}

/* 链表按位置插*/
int ListLocationInsert(List *pList, int pos, ELEMENTTYPE val)
{
#if 0
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    Nodes *newNode = (Nodes *)malloc(sizeof(Nodes) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(Nodes));
    newNode->data = 0;
    newNode->next = NULL;

    newNode->data = val;

    Nodes *traveNode = pList->head;

    int flag = 0;
    if (pos == pList->len)
    {
        traveNode = pList->tail;
        flag = 1;
    }
    else
    {
        while (pos)
        {
            traveNode = traveNode->next;
            pos--;
        }
    }

    newNode->next = traveNode->next;
    traveNode->next = newNode;

    if (flag)
    {
        pList->tail = newNode;
    }

    pList->len++;
    return ON_SUCCESS;
#endif
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 封装结点*/
    Nodes *newNode = (Nodes *)malloc(sizeof(Nodes) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(Nodes) * 1);
    newNode->data = 0;
    newNode->next = NULL;

    /* 赋值*/
    newNode->data = val;
#if 1
    /* 从头节点开始遍历*/
    Nodes *travelNode = pList->head;
#else
    LinkNode *travelNode = pList->head->next;
#endif
    int flag = 0;
    /* 这种情况下需要标记尾指针*/
    if (pos == pList->len)
    {
        travelNode = pList->tail;
        flag = 1;
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }

    /* 修改结点指向*/
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if (flag)
    {
        /* 尾指针更新位置*/
        pList->tail = newNode;
    }

    /* 更新链表长度*/
    (pList->len)++;
    return ret;
}

/* 链表头删*/
int ListHeadDelete(List *pList)
{
    ListLocationDelete(pList, 1);
}

/* 链表尾删*/
int ListTailDelete(List *pList)
{
    ListLocationDelete(pList, pList->len);
}

/* 链表按位置删除*/
int ListLocationDelete(List *pList, int pos)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    Nodes *traveNode = pList->head;

    int flag = 0;
    if (pos == pList->len)
    {
        flag = 1;
    }

    while (--pos)
    {
        traveNode = traveNode->next;
    }

    Nodes *needNode = traveNode->next;
    traveNode->next = needNode->next;

    if (flag)
    {
        pList->tail = traveNode;
    }

    if (needNode != NULL)
    {
        free(needNode);
        needNode = NULL;
    }

    pList->len--;

    return ON_SUCCESS;
}

/* 链表按数据删除*/
int ListDataDelete(List *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    /* 用于标记位置*/
    int pos = 1;
    int ret = 0;
    Nodes *traveNode = pList->head->next;
    while (traveNode != NULL)
    {
        ret = compareFunc(val, traveNode->data);
        traveNode = traveNode->next;
        if (ret == 1)
        {
            ListLocationDelete(pList, pos);
            ret = 0;
            pos--;
        }
        pos++;
    }

    return ON_SUCCESS;
}

/* 获取链表的长度*/
int ListFetchLen(List *pList, int *size)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (size)
    {
        *size = pList->len;
    }
    return pList->len;
}

/* 链表的销毁*/
int ListDestroyed(List *pList)
{
    int size = 0;
    while (ListFetchLen(pList, &size))
    {
        ListHeadDelete(pList);
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
        pList->tail = NULL;
    }
}

/* 链表的遍历*/
int ListTraverse(List *pList, int (*printFunc)(ELEMENTTYPE val))
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    Nodes *traveNode = pList->head->next;
    while(traveNode != NULL)
    {
        printFunc(traveNode->data);
        traveNode = traveNode->next;  
    }

    return ON_SUCCESS;
}
