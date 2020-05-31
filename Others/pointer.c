#include <stdio.h>

int main()
{
    int x[10][20]={15,17};
    x[6][3] = 54;
    printf("x = %d, x+2 = %d\n",x,x+2);
    printf("x[0][1] = %d, x[6][3] = %d\n",*(*x),*(*(x+6)+3));
    return 0;
}
