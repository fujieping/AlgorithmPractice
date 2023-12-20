#include <stdio.h>
#include <string.h>

#define YITFTGHY void*

void add(YITFTGHY ptr)
{
    int b[3] = {0};
    b[0] = *(int*)ptr;
    printf("%d\n", b[0]);
    *(int*)ptr = 8;
}

int main()
{
    int a = 4;
    add((void*)&a);
    printf("%d \n", a);
    return 0;
}