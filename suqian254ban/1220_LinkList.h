#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE void*

typedef struct LinkNodes
{
    ELEMENTTYPE data;
    struct LinkNodes *next;
}Nodes;

typedef struct LinkList
{
    Nodes *head;
    Nodes *tail;
    int len;
}List;

/* 链表的初始化*/
int ListInit(List **pList);

/* 链表的头插*/
int ListHeadInsert(List *pList, ELEMENTTYPE val);

/* 链表尾插*/
int ListTailInsert(List *pList, ELEMENTTYPE val);

/* 链表按位置插*/
int ListLocationInsert(List *pList, int pos, ELEMENTTYPE val);

/* 链表头删*/
int ListHeadDelete(List *pList);

/* 链表尾删*/
int ListTailDelete(List *pList);

/* 链表按位置删除*/
int ListLocationDelete(List *pList, int pos);

/* 链表按数据删除*/
int ListDataDelete(List *pList, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 获取链表的长度*/
int ListFetchLen(List *pList, int *size);

/* 链表的销毁*/
int ListDestroyed(List *pList);

/* 链表的遍历*/
int ListTraverse(List *pList, int(*printFunc)(ELEMENTTYPE val));

#endif