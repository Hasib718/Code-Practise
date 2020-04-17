#include <stdio.h>
#include <math.h>

int main()
{
	double val;
    double r,c,f;
    scanf("%lf", &val);
    f=floor(val);
    c=ceil(val);	
    
    r=round(val);
    printf("Round = %lf\nCieling = %lf\nFloor = %lf\n",r,f,c);
    
    return 0;
}