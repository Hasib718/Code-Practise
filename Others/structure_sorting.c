#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int reg;
    char name[10];
    char section;
    int session;
    int age;
    double cgpa;
} student;

void print_students(student s[],int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Serial#%02d,Reg.#%10d,",i,s[i].reg);
        printf("Name:%7s,Sec#%1c,",s[i].name,
               s[i].section);
        printf("Session#%4d,Age#%2d,CGPA#%.2lf\n",
               s[i].session, s[i].age, s[i].cgpa);
    }
}

int sortOnCGPA (const void * a, const void * b) {
   double dici = (((student *)a)->cgpa) - (((student *)b)->cgpa) ;
   char com = (((student *)a)->name) - (((student *)b)->name) ;
   if(dici<0) return 1;
   if(dici>0) return -1;
   if(dici==0)
   {
     if(com<0) return -1;
     if(com>0) return 1;
     return 0;
   }
}

int main()
{
    student x[200];
    int n,i;
//    printf("sizeof student = %d bytes\n",
//           sizeof(struct student));
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%lld %s %c %d %d %lf", &x[i].reg,
              x[i].name, &x[i].section,
              &x[i].session,&x[i].age,&x[i].cgpa );
    /** your code goes here */
    print_students(x,n);
    qsort(x,n,sizeof(student),sortOnCGPA);
    puts("After sorting on CGPA");
    print_students(x,n);
    return 0;
}
/**
5
2019331001 Alu A 2019 54 3.99
2019331002 Balu B 2019 16 4.00
2019331093 Chalu A 2019 32 3.99
2019331004 Khalu B 2019 81 3.51
2019331062 Potol B 2019 10 2.01

*/
