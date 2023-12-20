#include <stdio.h>

#define ARRAY_SIZE 100

int judGment(char *ptr)
{
    if (!ptr)
        return 0;
    int idx1 = 0;
    int idx2 = 0;
    while (ptr[idx1])
    {
        if(ptr[idx1] >= 'a' && ptr[idx1] <= 'z')
        {
            ptr[idx1] -= 32;
            ptr[idx2] =  ptr[idx1];
            idx2++;
        }
        else if(ptr[idx1] >= 'A' && ptr[idx1] <= 'Z')
        {
            ptr[idx2] =  ptr[idx1];
            idx2++;
        }
        idx1++;
    }
    ptr[idx2] = '\0';
    printf("%s\n", ptr);
    int idx3 = 0;
    int idx4 = idx2 - 1;
    while(idx3 < idx4)
    {
        if(ptr[idx3] - ptr[idx4] !=0)
        {
            return 0;
        }
        idx3++;
        idx4--;
    }
    return 1;
}

int main()
{
    char Array[ARRAY_SIZE] = { 0 };
    printf("请输入要判断的字符串！\n");
    scanf("%[^\n]", Array);
    int temp = judGment(Array);
    printf("temp:%d\n",temp);
    if(temp == 1)
    {
        printf("这个字符串是回文字符串!\n");
    }
    else
    {
        printf("这个字符串不是回文字符串!\n");
    }
    return 0;
}