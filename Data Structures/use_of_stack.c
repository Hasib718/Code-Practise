#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int balanced(char input[])
{
  char stack[100], last_char;
  int top=0, i, len;

  memset(stack, 0, sizeof(char));

  len = strlen(input);

  for(i=0; i<len; i++)
    if(input[i] == '(' || input[i] == '{' || input[i] == '[')
    {
      stack[top] = input[i];
      top++;
    }
    else if(input[i] == ')' || input[i] == '}' || input[i] == ']')
    {
      if(top == 0) return 0;
      top--;
      last_char = stack[top];
      if(last_char != '(' && last_char != '{' && last_char != '[') return 0;
    }
    if(top == 0) return 1;
    else return 0;
}

int main()
{
  char input[100];
  scanf("%s", input);

  if(balanced(input)) printf("%s is balanced\n", input);
  else printf("%s isn't balanced\n", input);

  return 0;
}
