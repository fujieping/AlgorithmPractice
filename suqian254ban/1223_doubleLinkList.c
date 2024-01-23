#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1223_doubleLinkList.h"

/* 状态码*/
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 初始化*/
int doubleLinkListInit(doubleLinkList **pList)
{
    doubleLinkList *list = (doubleLinkList *)malloc(sizeof(doubleLinkList)* 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(doubleLinkList) * 1);

    list->head = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(doubleLinkNode) * 1);

    list->head->data = 0;
    list->head->next = NULL;
    list->head->priv = NULL;

    list->tail = list->head;
    list->len = 0;

    *pList = list;
    return ON_SUCCESS;
}

/* 头插*/
int doubleLinkListHeadInsert(doubleLinkList *pList, ELEMENTTYPE val)
{
    return doubleLinkListLocationInsert(pList, 0, val);
}

/* 尾插*/
int doubleLinkListTailInsert(doubleLinkList *pList, ELEMENTTYPE val)
{
    return doubleLinkListLocationInsert(pList, pList->len, val);
}

static doubleLinkNode *createDoubleLinkNode(ELEMENTTYPE val)
{
    /* 封装结点*/
    doubleLinkNode *newNode = (doubleLinkNode *)malloc(sizeof(doubleLinkNode) * 1);
    if (newNode == NULL)
    {
        return NULL;
    }
    memset(newNode, 0, sizeof(doubleLinkNode) * 1);
    newNode->data = 0;
    newNode->next = NULL;
    newNode->priv = NULL;

    /* 赋值*/
    newNode->data = val;

    /* 返回新建结点*/
    return newNode;
}

/* 按位置插*/
int doubleLinkListLocationInsert(doubleLinkList *pList, int pos, ELEMENTTYPE val)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 && pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    doubleLinkNode * newNode = createDoubleLinkNode(val);
    doubleLinkNode * traveNode = pList->head;

    int flag = 0;
    if (pos == pList->len)
    {
        traveNode = pList->tail;
        flag = 1;
    }
    else
    {
        while(pos)
        {
            traveNode = traveNode->next;
            pos--;
        }
        traveNode->next->priv = newNode;
    }
    newNode->next = traveNode->next;
    newNode->priv = traveNode;
    traveNode->next = newNode;

    if (flag == 1)
    {
        pList->tail = newNode;
    }

    pList->len++;

    return ON_SUCCESS;
}
    

/* 头删*/
int doubleLinkListHeadDelete(doubleLinkList *pList)
{
    return doubleLinkListLocationDelete(pList, 1);
}

/* 尾删*/
int doubleLinkListTailDelete(doubleLinkList *pList)
{
    return doubleLinkListLocationDelete(pList, pList->len);
}

/* 按位置删*/
int doubleLinkListLocationDelete(doubleLinkList *pList, int pos)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    doubleLinkNode *traveNode = pList->head->next;
    doubleLinkNode *needNode = NULL;
    if (pos == pList->len)
    {
        needNode = pList->tail;
        pList->tail = pList->tail->priv;
    }
    else
    {
        while (--pos)
        {
            traveNode = traveNode->next;
        }
        traveNode->next->priv = traveNode->priv;
        traveNode->priv->next = traveNode->next;
        needNode = traveNode;
    }

    if (needNode != NULL)
    {
        free(needNode);
        needNode = NULL;
    }

    pList->len--;
    return ON_SUCCESS;

}

/* 按值删除*/
int doubleLinkListElementDelete(doubleLinkList *pList, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    int num = 0;
    int pos = 1;
    doubleLinkNode * traveNode = pList->head->next;
    while (traveNode != NULL)
    {
        num = compareFunc(traveNode->data, val);
        traveNode = traveNode->next;
        if (num)
        {
            doubleLinkListLocationDelete(pList, pos);
            pos--;
        }    
        traveNode = traveNode->next;
        pos++;                    
    }
}

/* 获取链表长度*/
int doubleLinkListFetchLen(doubleLinkList *pList, int *size)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (size != NULL)
    {
        *size = pList->len;
    }
    return pList->len;
}

/* 销毁链表*/
int doubleLinkListDestroyed(doubleLinkList *pList)
{
    int size = 0;
    while (doubleLinkListFetchLen(pList, &size))
    {
        doubleLinkListHeadDelete(pList);
    }
    
    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ON_SUCCESS;
}

/* 链表遍历*/
int doubleLinkListTraverse(doubleLinkList *pList, int(*printFunc)(ELEMENTTYPE val))
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    doubleLinkNode * traveNode = pList->head->next;
    
    while (traveNode != NULL)
    {
        printFunc(traveNode->data);
        traveNode = traveNode->next;
    }

    return ON_SUCCESS;
}
