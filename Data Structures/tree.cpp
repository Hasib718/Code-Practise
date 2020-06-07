#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

node *create_node(int item)
{
  node *new_node = new node;

  new_node->data = item;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

void pre_order(node *temp_node)
{
  cout << temp_node->data << " ";

  if(temp_node->left != NULL)
    pre_order(temp_node->left);

  if(temp_node->right != NULL)
    pre_order(temp_node->right);
}

void post_order(node *temp_node)
{
  if(temp_node->left != NULL)
    post_order(temp_node->left);

  if(temp_node->right != NULL)
    post_order(temp_node->right);

    cout << temp_node->data << " ";
}

void in_order(node *temp_node)
{
  if(temp_node->left != NULL)
    in_order(temp_node->left);

    cout << temp_node->data << " ";

  if(temp_node->right != NULL)
    in_order(temp_node->right);
}

int main()
{
  node *root = create_node(2);

  root->left = create_node(7);

  root->left->left = create_node(1);
  root->left->right = create_node(6);

  root->left->right->left = create_node(5);
  root->left->right->right = create_node(10);

  root->right = create_node(9);

  root->right->right = create_node(8);

  root->right->right->left = create_node(3);
  root->right->right->right = create_node(4);

  in_order(root);
  puts(" ");

  return 0;
}
