#include <stdio.h>
#include <malloc.h>

typedef struct node1{
    int val;
    node1 *next;
} node;

node *start;

void print_list()
{
    node *cur = start;
    puts("List Start");
    while(cur!=NULL)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    puts("");
    puts("List End");
}

void enqueue(int x)
{
    node *cur = (node*) malloc(sizeof(node)),*temp;
    cur->val = x;
    cur->next = NULL;
    printf("%d is added.\n", x);
    if(start==NULL)
    {
        start = cur;
        return;
    }
    temp = start;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = cur;
}

void dequeue()
{
    node *temp = start;
    if(start!=NULL)
    {
        start = start->next;
        printf("%d is removed.\n", temp->val);
        free(temp);
        return;
    }
    puts("Underflow occured!");
}

int main()
{
    start = NULL;print_list();
    enqueue(5);print_list();
    enqueue(15);print_list();
    enqueue(3);print_list();
    dequeue();print_list();
    enqueue(17);print_list();
    dequeue();print_list();
    dequeue();print_list();
    dequeue();print_list();
    enqueue(25);print_list();
    dequeue();print_list();
    dequeue();print_list();
    return 0;
}
