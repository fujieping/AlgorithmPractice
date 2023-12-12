#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SiZE 10
// 数组快排
void fastSost(int *date, int start, int len)
{
    if (start >= len)
    {
        return;
    }
    int left = start;
    int right = len;
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

// 数组去重
void Deduplication(int *Random, int end)
{
    int count=0;
    for(int indx=0;indx<end;indx++)
    {
        if(Random[indx]==Random[indx+1])
        count+=1;
        Random[indx+1-count]=Random[indx+1];
    }
    end -=count;
    for (int idx = 0; idx < end+1; idx++)
    {
        printf("%d ", Random[idx]);
    }
    printf("\n");
    printf("len:%d\n", end+1);
}


int main()
{
    srand(time(NULL));
    int Random[ARRAY_SiZE] = {0};
    // memset(Random, 0, sizeof(int) * ARRAY_SiZE);

    for (int idx = 0; idx < ARRAY_SiZE; idx++)
    {
        Random[idx] = rand() % ARRAY_SiZE;
        printf("%d ", Random[idx]);
    }
    printf("\n");

    int len = sizeof(Random) / 4 - 1;
    printf("len:%d\n", len);
    fastSost(Random, 0, len);
    for (int idx = 0; idx < ARRAY_SiZE; idx++)
    {
        printf("%d ", Random[idx]);
    }
    printf("\n");

    Deduplication(Random, len);
    

    return 0;
}