#include <stdio.h>
#include <math.h>

int main()
{
    double AB=50, BC=20, CD=40, DA=23;

    double s=(AB+BC+CD+DA)/2;

    double sq=sqrt(((s-AB)*(s-CD)*(s-CD-BC)*(s-CD-DA)));

    double ans=((AB+CD)/(AB-CD))*sq;

    printf("ans: %.2f\n", ans);

    return 0;
}