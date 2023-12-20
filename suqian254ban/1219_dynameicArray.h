#ifndef __DYNAMEIC_ARRAY_H_
#define __DYNAMEIC_ARRAY_H_

#define ELEMENTTYPE void*

typedef struct dynamicArray
{
    ELEMENTTYPE *data;
    int len;
    int capacity;
}Array;

/* API:application program interface.*/

/* 动态数组的初始化*/
int dynamicArrayInit(Array * pArray, int capacity);

/* 动态数组的扩容*/
static int dynamicArrayExpansion(Array * pArray);

/* 动态数组的缩容*/
static int dynamicArrayShrink(Array * pArray);

/* 动态数组插入数据（尾插）*/
int dynamicArrayInsertData(Array * pArray, ELEMENTTYPE val);

/* 动态数组指定位置插入数据*/
int dynamicArrayDesignateInsertData(Array * pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（尾删）*/
int dynamicArrayDeleteData(Array * pArray);

/* 动态数组删除指定位置的数据*/
int dynamicArrayDeleteDesignateLocationData(Array * pArray, int pos);

/* 动态数组删除指定元素数据*/
int dynamicArrayDeleteDesignateElementData(Array * pArray,ELEMENTTYPE val);

/* 动态数组修改指定位置的数据*/
int dynamicArrayReviseDesignateLocationData(Array * pArray, int pos, ELEMENTTYPE avl);

/* 获取动态数组的大小*/
int dynamicArrayFetchSize(Array * pArray, int *size);

/* 获取动态数组的容量*/
int dynamicArrayFetchCapacity(Array * pArray, int *capacity);

/* 获取动态数组指定位置的数据*/
int dynameicArrayFetchCDesignateData(Array * pArray, int pos, ELEMENTTYPE *val);

/* 动态数组的销毁*/
int dynameicArrayDestroyed(Array * pArray);

#endif