#include <stdio.h>
#include <string.h>

int main()
{
   char s[1000], r[1000];
   int begin, end, count = 0;

   scanf("%[^\t\n]s", s);

    count = strlen(s);

   end = count - 1;

   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }

   r[begin] = '\0';

   printf("%s\n", r);

   return 0;
}