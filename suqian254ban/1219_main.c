#include <stdio.h>
#include "1219_dynameicArray.h"
#include <string.h>

#define BUFFER_SIZE 20
#define DEFAULT_NUM 3

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;

int main()
{
    Array array;
    /* 初始化*/
    dynamicArrayInit(&array, BUFFER_SIZE);
    
        /* 插入数据*/
        int tmp = 3;
        dynamicArrayInsertData(&array, (void *)&tmp);
        for(int idx = 0; idx <= DEFAULT_NUM; idx++)
        {
            dynamicArrayInsertData(&array, (void *)&idx);
        }

        /* 修改数据*/
        //dynamicArrayReviseDesignateLocationData(&array, 4, 5);

        /* 删除指定位置数据 */
        //dynamicArrayDeleteDesignateLocationData(&array, 4);

        // /* 删除指定元素数据*/
        //dynamicArrayDeleteDesignateElementData(&array, 3);

    {
        // int size = 0;
        // /* 获取动态数组大小*/
        // dynameicArrayGetSize(&array, &size);
        
    }

    {
        int size = 0;
        /* 获取动态数组大小*/
        dynamicArrayFetchSize(&array, &size);
        printf("size:%d\n", size);

        int val = 0;
        for(int idx = 0; idx < size; idx++)
        {
            dynameicArrayFetchCDesignateData(&array, idx, (void*)&val);
            printf("array[%d]  val:%d\n", idx, val);
        }
    }
    return 0;
}
    
    