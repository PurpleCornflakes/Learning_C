#include <stdio.h>
#define SQURE(x) ((x)*(x)*(x))
int main()
{
    int x=5;
    printf("%d", SQURE(++x));
    return 0;
}
