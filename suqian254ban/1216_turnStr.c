#include <stdio.h>

#define BUFFER_SIZE 100

void TurnStr(char * ptr, int idx, int jdx)
{
    
    while(idx < jdx)
    {
        int tmp = 0;
        tmp = ptr[idx];
        ptr[idx++] = ptr[jdx];
        ptr[jdx--] = tmp;
    }
}

void turnString(char *ptr)
{
    int idx = 0;
    int jdx = 0;
    
    //去除第一个单词前的空格
    while (ptr[idx])
    {
        while (*ptr == ' ')
        {
            if (ptr[idx] != ' ')
            {
                ptr[jdx] = ptr[idx];
                jdx++;
            }
            idx++;
        }
        //去除单词之间的空格
        if (ptr[idx] != ' ')
        {
            ptr[jdx] = ptr[idx];
            jdx++;
        }
        else
        {
            if (ptr[idx + 1] != ' ')
            {
                ptr[jdx] = ptr[idx];
                jdx++;
            }
        }
        idx++;
    }
    //去除最后一个单词后的空格
    if (ptr[jdx - 1] == ' ')
    {
        ptr[jdx - 1] = '\0';
        jdx -= 2;
    }   
    else
    {
        ptr[jdx] = '\0';
        jdx -= 1;
    }
    idx = 0;
    //字符串第一次翻转
    TurnStr(ptr, idx, jdx);
    printf("第一次翻转:%s\n", ptr);
    //字符串第二次翻转
    int idx2 = 0;
    while(ptr[idx])
    { 
        if(ptr[idx + 1] == ' ' || ptr[idx + 1] == '\0')
        {
            TurnStr(ptr, idx2, idx);
            idx2 = idx + 2;
        }
        idx++;
    }
    printf("第二次翻转:%s\n", ptr);

}

int main()
{
    char StringArray[BUFFER_SIZE] = {0};
    printf("请输入要翻转的字符串!\n");
    scanf("%[^\n]", StringArray);

    turnString(StringArray);
    return 0;
}