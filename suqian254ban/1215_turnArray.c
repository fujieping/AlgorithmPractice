#include <stdio.h>

#define ROW 3
#define COLUMN 3

void turnArray(int ptr[][COLUMN])
{
    int tmp = 0;
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int idy = idx; idy < COLUMN; idy++)
        {
            tmp = ptr[idx][idy];
            ptr[idx][idy] = ptr[idy][idx];
            ptr[idy][idx] = tmp;
        }
    }

}

int main()
{
    int Array[ROW][COLUMN] = { 0 };
    int coust = 0;
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int idy = 0; idy < COLUMN; idy++)
        {
            Array[idx][idy] = coust++;
            printf("Array[%d][%d] = %d    ", idx, idy, Array[idx][idy]);
            if(coust % 3 == 0)
            {
                printf("\n");
            }
        }
    }
    turnArray(Array);
    printf("---------------------------------------------------------------\n");
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int idy = 0; idy < COLUMN; idy++)
        {
            printf("Array[%d][%d] = %d    ", idx, idy, Array[idx][idy]);
            coust++;
            if(coust % 3 == 0)
            {
                printf("\n");
            }
        }
    }
}