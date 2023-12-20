#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_SIZE 7

void stockProfit(int *ptr)
{
    int tmp = 0;
    int num1 = 0;
    int num2 = 0;
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        for(int jdx = idx; jdx < BUFFER_SIZE; jdx++)
        {
            if(ptr[jdx] - ptr[idx] > tmp)
            {
                num1 = idx + 1;
                num2 = jdx + 1;
                tmp = ptr[jdx] - ptr[idx];
            }
        }
    }
    printf("周[%d]买入,周[%d]卖出,获利最大，获利[%d]\n", num1, num2, tmp);
}

int main()
{
    srand(time(NULL));
    int Array[BUFFER_SIZE] = {0};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        Array[idx] = rand() % BUFFER_SIZE + 1;
        printf("Array[%d] = %d\t", idx + 1, Array[idx]);
    }
    printf("\n");
    stockProfit(Array);
    return 0;
}