#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1220_LinkList.h"

#define BUFFER_SIZE 3
#define DEFAULT_NUM 3

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

int printStruct(ELEMENTTYPE arg)
{
   stuInfo *info = (stuInfo*)arg;
   printf("arg:%d\tsex:%c\n",info->age, info->sex);
}

int printInt(ELEMENTTYPE arg)
{
    int data = *(int*)arg;
    printf("data:%d\n", data);
}

int compare(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    int num1 = *(int *)val1;
    int num2 = *(int *)val2;
    return num1 == num2 ? 1:0;
}

int main()
{
    List *list = NULL;
    /* 初始化链表*/
    ListInit(&list);
#if 0
    /* 插入数据*/
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListTailInsert(list, idx);
    }

    /* 获取链表长度*/
    int size = 0;
    LinkListDetLen(list, &size);
    printf("size:%d\n", size);

    /*  遍历指针*/
    LinkListForeach(list);

  
#endif
#if 1
stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';

    stuInfo buffer[DEFAULT_NUM] = {stu1, stu2, stu3};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        ListTailInsert(list, (void*)&buffer[idx]);
    }
    /* 获取链表长度*/
    int size = 0;
    ListFetchLen(list, &size);
    printf("size:%d\n", size);

    /*  遍历指针*/
    ListTraverse(list, printStruct);
#else
    int array[BUFFER_SIZE] = {4, 9, 3, 9, 6};

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        ListTailInsert(list, (void*)&array[idx]);
    }

    /* 链表按位置插入*/
    int a = 9;
    ListLocationInsert(list, 4, (void *)&a);

    /* 链表按位置删*/
    //ListLocationDelete(list, 6);

    /* 链表按元素删*/
    ListDataDelete(list, (void*)&a, compare);
    /* 获取链表长度*/
    int size = 0;
    ListFetchLen(list, &size);
    printf("size:%d\n", size);

    /*  遍历指针*/
    ListTraverse(list, printInt);
#endif
    return 0;
}