#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SiZE 20

int main()
{
    srand(time(NULL));
    int Random[ARRAY_SiZE];
    memset(Random,0,sizeof(int) * ARRAY_SiZE);

    int target = 0;

    for (int idx = 0; idx < ARRAY_SiZE; idx++)
    {
        Random[idx] = rand() % ARRAY_SiZE;
        printf("%d ", Random[idx]);
    }
    printf("\n请输入需要找的数!\n");
    scanf("%d", &target);

    int fleg = 0; // 标志位，判断有没有找到
    for (int idx = 0; idx < ARRAY_SiZE; idx++)
    {
        for (int idx1 = idx + 1; idx1 < ARRAY_SiZE; idx1++)
        {
            if (Random[idx] + Random[idx1] == target)
            {
                fleg = 1;
                printf("%d %d\n", idx, idx1);
            }
        }
    }
    if (fleg == 0)
        printf("没有找到!\n");
    return 0;
}