#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#define ELEMENTTYPE void*

typedef struct doubleLinkNode
{
    ELEMENTTYPE data;
    struct doubleLinkNode *priv;
    struct doubleLinkNode *next;
}doubleLinkNode;

typedef struct doubleLinkList
{
    doubleLinkNode *head;
    doubleLinkNode *tail;
    int len;
}doubleLinkList;

/* 初始化*/
int doubleLinkListInit(doubleLinkList **pList);

/* 头插*/
int doubleLinkListHeadInsert(doubleLinkList *pList, ELEMENTTYPE val);

/* 尾插*/
int doubleLinkListTailInsert(doubleLinkList *pList, ELEMENTTYPE val);

/* 按位置插*/
int doubleLinkListLocationInsert(doubleLinkList *pList, int pos, ELEMENTTYPE val);

/* 头删*/
int doubleLinkListHeadDelete(doubleLinkList *pList);

/* 尾删*/
int doubleLinkListTailDelete(doubleLinkList *pList);

/* 按位置删*/
int doubleLinkListLocationDelete(doubleLinkList *pList, int pos);

/* 按值删除*/
int doubleLinkListElementDelete(doubleLinkList *pList, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表长度*/
int doubleLinkListFetchLen(doubleLinkList *pList, int *size);

/* 销毁链表*/
int doubleLinkListDestroyed(doubleLinkList *pList);

/* 链表遍历*/
int doubleLinkListTraverse(doubleLinkList *pList, int(*printFunc)(ELEMENTTYPE val));


#endif