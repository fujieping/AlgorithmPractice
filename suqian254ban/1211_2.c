#include <stdio.h>
#include <string.h>

int main()
{

    char*s[10];
    s[0]="suqian";
    s[1]="jiaoyu";
    printf("%c\n",*s[0]);
    printf("%c\n",*(s[0]+1));
    printf("%c\n",*s[0]+1);
    printf("%c\n",*(s[0]+6));
    printf("%c\n",*(s[0]+7));
    printf("%c\n",**(&s[0]+1));

}