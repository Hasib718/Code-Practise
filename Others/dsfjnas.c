#include <stdio.h>
int main()
{
    int a[3][4],b[3][4],i,j;
    //here i = row and j= colum


    printf("enter A matrix\n");
    for(i = 0; i<3; i++ )
    {
        for(j =0; j<4; j++)
        {
            scanf("%d",&a[i][j]);
        }

    }
    for(i = 0; i<3; i++ )
    {
        for(j =0; j<4; j++)
        {
            printf("  %d  ",a[i][j]);
        }
printf("\n");
    }

    printf("give B matrix\n");

    for(i = 0; i<3; i++ )
    {
        for(j =0; j<4; j++)
        {
            scanf("%d",&b[i][j]);
        }

    }
    for(i = 0; i<3; i++ )
    {
        for(j =0; j<4; j++)
        {
            printf("  %d  ",b[i][j]);
        }

    }
    printf("sub of mtrix A and B");
    for(i = 0; i<3; i++)
    {
        for(j= 0; j<4; j++);
        {
            printf(" %d ",a[i][j]-b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("sum of mtrix A and B");
    for(i = 0; i<3; i++)
    {
        for(j= 0; j<4; j++)
        {
            printf(" %d ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
