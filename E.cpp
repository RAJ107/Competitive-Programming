#include <stdio.h> 
#include <stdlib.h>

int main()
{
    char *c; scanf("%s", c);
    printf("%ld\n", sizeof(c));
    printf("%ld\n", sizeof(&c));
    printf("%ld\n", sizeof(*c));
    printf("%s\n", c);c
    return 0;
}