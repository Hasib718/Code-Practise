#include <stdio.h>
#include <math.h>

int main()
{
	double value;
    double r,c,f;
    scanf("%lf",&value);
    f=floor(value);
    c=ceil(value);	
    
    r=round(value);
    printf("Round = %lf\nCieling = %lf\nFloor = %lf\n",r,f,c);
    return 0;
}