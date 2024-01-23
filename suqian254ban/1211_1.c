#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SiZE 5
#if 1 // 作业1， 数组快排
void fastSost(int *date, int start, int len)
{
    if (start >= len)
    {
        return;
    }
    int left = start;
    int right = (len);
    int temp = date[left];
    while (left < right)
    {
        while (left < right && date[right] > temp)
        {
            right--;
        }
        if (left < right)
        {
            date[left] = date[right];
            left++;
        }
        while (left < right && date[left] < temp)
        {
            left++;
        }
        if (left < right)
        {
            date[right] = date[left];
            right--;
        }
    }
    date[left] = temp;
    fastSost(date, 0, left - 1);
    fastSost(date, right + 1, len);
}
#endif

#if 1 // 作业2，有序数组去重
void Deduplication(int *RandArray, int end)
{
    int count = 0;
    for (int indx = 0; indx < end; indx++)
    {
        if (RandArray[indx] == RandArray[indx + 1])
            count += 1;
        RandArray[indx + 1 - count] = RandArray[indx + 1];
    }
    end -= count;
    for (int idx = 0; idx < end; idx++)
    {
        printf("%d ", RandArray[idx]);
    }
    printf("\n");
    printf("len:%d\n", end + 1);
}
#endif

#if 1// 作业3，删除数组指定元素
void DeleteElement(int *ptr, int end, int element)
{
    int count = 0;
    for (int idx = 0; idx < end; idx++)
    {
        if (ptr[idx] == element)
            count += 1;
        ptr[idx + 1 - count] = ptr[idx + 1];
    }
    end -= count;

    for (int idx = 0; idx < end; idx++)
    {
        printf("%d ", ptr[idx]);
    }
    printf("\n");
    printf("len:%d\n", end);
}
#endif

#if 1 // 作业4，合并两有序数组
int *mergeOrderNums(int *nums1, int num1Size, int *nums2, int num2Size, int *newNumSize)
{
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < num1Size || idx2 < num2Size)
    {
        if (idx1 == num1Size)
        {
            newNumSize[idx1 + idx2] = nums2[idx2];
            idx2++;
        }
        else if (idx2 == num2Size)
        {
            newNumSize[idx1 + idx2] = nums1[idx1];
            idx1++;
        }
        else if (nums1[idx1] < nums2[idx2])
        {
            newNumSize[idx1 + idx2] = nums1[idx1];
            idx1++;
        }
        else
        {
            newNumSize[idx1 + idx2] = nums2[idx2];
            idx2++;
        }
    }
    return newNumSize;
}
#endif

#if 1
void PrintArray(int *date, int end)
{
    for (int idx = 0; idx < end; idx++)
    {
        printf("%d  ", date[idx]);
    }
    printf("\n");
}
#endif

int main()
{
    srand(time(NULL));
    int RandArray[ARRAY_SiZE] = {0};
    int RandArray2[ARRAY_SiZE] = {0};
    int *RandArray3 = (int *)malloc(sizeof(int) * ARRAY_SiZE * 2);
    if (RandArray3 == NULL)
    {
        printf("申请失败!");
    }
    int target = 0;
    // memset(RandArray, 0, sizeof(int) * ARRAY_SiZE);
    // 生成随机数组并输出
    for (int idx = 0; idx < ARRAY_SiZE; idx++)
    {
        RandArray[idx] = rand() % ARRAY_SiZE * 2;
        RandArray2[idx] = rand() % ARRAY_SiZE * 2;
    }
    // int len = sizeof(RandArray) / 4;
    // printf("len:%d\n", len);

    fastSost(RandArray, 0, ARRAY_SiZE - 1);
    fastSost(RandArray2, 0, ARRAY_SiZE - 1);
    printf("RandArray: ");
    PrintArray(RandArray, ARRAY_SiZE);
    printf("RandArray2: ");
    PrintArray(RandArray2, ARRAY_SiZE);

    int *newArray = mergeOrderNums(RandArray, ARRAY_SiZE, RandArray2, ARRAY_SiZE, RandArray3);

    PrintArray(newArray, ARRAY_SiZE * 2);

    // Deduplication(RandArray, len);
    // printf("\n请输入需要删除的数!\n");
    // scanf("%d", &target);
    // DeleteElement(RandArray, ARRAY_SiZE, target);
    free(RandArray3);
    return 0;
}