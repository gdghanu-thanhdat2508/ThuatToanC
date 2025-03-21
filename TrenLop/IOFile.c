#include <stdio.h>
#include <stdlib.h>
typedef struct Book bk;

int main()
{
    char ch;
    FILE *fp = fopen("Skibidi.txt", "r"); // read mode
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    return 0;
}