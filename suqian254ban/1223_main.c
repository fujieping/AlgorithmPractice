#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1223_doubleLinkList.h"

#define BUFFER_SIZE 5
#define DEFAULT_NUM 3

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

int printStruct(void *arg)
{
   stuInfo *info = (stuInfo*)arg;
   printf("arg:%d\tsex:%c\n",info->age, info->sex);
}

int printInt(void *arg)
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
#if 1
    doubleLinkList *list = NULL;
    /* 初始化链表*/
    doubleLinkListInit(&list);
#if 0
    /* 插入数据*/
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        DoubleLinkListTailInsert(list, idx);
    }

    /* 获取链表长度*/
    int size = 0;
    DoubleLinkListDetLen(list, &size);
    printf("size:%d\n", size);

    /*  遍历指针*/
    DoubleLinkListForeach(list);

  
#endif
#if 0
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
#else
    int array[BUFFER_SIZE] = {9, 2, 1, 2, 5};

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListTailInsert(list, (void*)&array[idx]);
    }

    // /* 链表按位置插入*/
    int a = 9;
    doubleLinkListLocationInsert(list, 5, (void *)&a);

    /* 链表按位置删*/
    //doubleLinkListLocationDelete(list, 6);
    doubleLinkListTailDelete(list);

    /* 链表按元素删*/
    //doubleLinkListElementDelete(list, (void*)&a, compare);
    /* 获取链表长度*/
    int size = 0;
    doubleLinkListFetchLen(list, &size);
    printf("size:%d\n", size);

    /*  遍历指针*/
    doubleLinkListTraverse(list, printInt);
#endif
#endif

    return 0;
}