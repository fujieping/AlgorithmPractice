#include "1219_dynameicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 12

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 动态数组的初始化*/
int dynamicArrayInit(Array *pArray, int capacity)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    if (capacity < 0)
    {
        capacity = BUFFER_SIZE;
    }

    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}

/* 动态数组的扩容*/
static int dynamicArrayExpansion(Array *pArray)
{
    int newCapacity = pArray->capacity + pArray->capacity >> 1;
    ELEMENTTYPE *newData = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * newCapacity);
    if (pArray->data == NULL)
    {
        return NULL_PTR;
    }

    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = newData[idx];
    }

    if (newData != NULL)
    {
        free(newData);
        newData = NULL;
    }

    pArray->capacity = newCapacity;
    return ON_SUCCESS;
}

/* 动态数组的缩容*/
static int dynamicArrayShrink(Array *pArray)
{
    int newCapacity = pArray->capacity - pArray->capacity >> 1;
    ELEMENTTYPE *newData = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * newCapacity);
    if (pArray->data == NULL)
    {
        return NULL_PTR;
    }

    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = newData[idx];
    }

    if (newData != NULL)
    {
        free(newData);
        newData = NULL;
    }
    pArray->capacity = newCapacity;
    return ON_SUCCESS;
}

/* 动态数组插入数据（尾插）*/
int dynamicArrayInsertData(Array *pArray, ELEMENTTYPE val)
{
    dynamicArrayDesignateInsertData(pArray, pArray->len, val);
}

/* 动态数组指定位置插入数据*/
int dynamicArrayDesignateInsertData(Array *pArray, int pos, ELEMENTTYPE val)
{
    if (pArray == NULL)  
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS; 
    }

    if ((pArray->len + (pArray->len >> 1)) >= pArray->capacity)
    {
        dynamicArrayExpansion(pArray);
    }

    for (int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
    pArray->data[pos] = val;

    pArray->len++;
    return ON_SUCCESS;
}

/* 动态数组删除数据（尾删）*/
int dynamicArrayDeleteData(Array *pArray)
{
    dynamicArrayDeleteDesignateLocationData(pArray, pArray->len);
}

/* 动态数组删除指定位置的数据*/
int dynamicArrayDeleteDesignateLocationData(Array *pArray, int pos)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }

    if (pArray->len < pArray->capacity >> 1)
    {
        dynamicArrayShrink(pArray);
    }

    for (int idx = pos; idx < pArray->len - 1; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }

    pArray->len--;
    return ON_SUCCESS;
}

/* 动态数组删除指定元素数据*/
int dynamicArrayDeleteDesignateElementData(Array *pArray, ELEMENTTYPE val)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    for (int idx = pArray->len - 1; idx >= 0; idx--)
    {
        if (pArray->data[idx] == val)
            dynamicArrayDeleteDesignateLocationData(pArray, idx);
    }
    return ON_SUCCESS;
}

/* 动态数组修改指定位置的数据*/
int dynamicArrayReviseDesignateLocationData(Array *pArray, int pos, ELEMENTTYPE val)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    pArray->data[pos] = val;
    return ON_SUCCESS;
}

/* 获取动态数组的大小*/
int dynamicArrayFetchSize(Array *pArray, int *size)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (size != NULL)
    {
        *size = pArray->len;
    }

    return ON_SUCCESS;
}

/* 获取动态数组的容量*/
int dynamicArrayFetchCapacity(Array *pArray, int *capacity)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (capacity != NULL)
    {
        *capacity = pArray->capacity;
    }

    return ON_SUCCESS;
}

/* 获取动态数组指定位置的数据*/
int dynameicArrayFetchCDesignateData(Array * pArray, int pos, ELEMENTTYPE *val)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }
    if(val)
    {
        *val = pArray->data[pos];
    }
    return ON_SUCCESS;
}

/* 动态书数组的销毁*/
int dynameicArrayDestroyed(Array *pArray)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    
    if(pArray->data != NULL)
    {
        free(pArray->data);
        pArray->data = NULL;
    }

    return ON_SUCCESS;
}
