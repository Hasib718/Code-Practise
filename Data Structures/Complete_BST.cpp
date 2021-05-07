#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  node *left;
  node *parent;
  node *right;
};

struct tree
{
  node *root = NULL;
  tree();
  ~tree();
  node *create_node(int item);
  node *insert(node *temp_node, int item);
  void pre_order(node *temp_node);
  void in_order(node *temp_node);
  void post_order(node *temp_node);
  node *search(int item);
  node *minimum(node *temp_node);
  node *del_node(node *temp_node, int item);
};

tree::tree()
{
  root = NULL;
}

tree::~tree()
{

}

node *tree::create_node(int item)
{
  node *new_node = new node;

  new_node->data = item;
  new_node->left = NULL;
  new_node->parent = NULL;
  new_node->right = NULL;

  return (new_node);
}

node *tree::insert(node* temp_node, int item)
{
  node *lchild, *rchild;
  if(temp_node == NULL) return create_node(item);

  if(temp_node->data >= item)
  {
    lchild = insert(temp_node->left, item);
    temp_node->left = lchild;
    lchild->parent = temp_node;
  }
  else if(temp_node->data < item)
  {
    rchild = insert(temp_node->right, item);
    temp_node->right = rchild;
    rchild->parent = temp_node;
  }

  return (temp_node);
}
void tree::pre_order(node *temp_node)
{
  cout << temp_node->data << " ";
  // if(temp_node->parent == NULL)
  //   cout << "Parent: NULL" << endl;
  // else
  //   cout << "Parent: " << temp_node->parent->data << endl;

  if(temp_node->left != NULL)
    pre_order(temp_node->left);

  if(temp_node->right != NULL)
    pre_order(temp_node->right);
}

void tree::post_order(node *temp_node)
{
  if(temp_node->left != NULL)
    post_order(temp_node->left);

  if(temp_node->right != NULL)
    post_order(temp_node->right);

    cout << temp_node->data << " ";
  // if(temp_node->parent == NULL)
  //   cout << "Parent: NULL" << endl;
  // else
  //   cout << "Parent: " << temp_node->parent->data << endl;
}

void tree::in_order(node *temp_node)
{
  if(temp_node->left != NULL)
    in_order(temp_node->left);

    cout << temp_node->data << " ";
  // if(temp_node->parent == NULL)
  //   cout << "Parent: NULL" << endl;
  // else
  //   cout << "Parent: " << temp_node->parent->data << endl;

  if(temp_node->right != NULL)
    in_order(temp_node->right);
}

node *tree::search(int item)
{
  node *temp = root;

  while(temp != NULL)
  {
    if(temp->data == item) return (temp);

    if(temp->data > item) temp = temp->left;
    else if(temp->data < item) temp = temp->right;
  }
}

node *tree::minimum(node *temp_node)
{
  node *cur = temp_node;

  while(cur && cur->left != NULL)
    cur = cur->left;

  return (cur);
}

node *tree::del_node(node *temp_root, int item)
{
  if (root == NULL)
    return (temp_root);

  if (temp_root->data > item)
  {
    temp_root->left = del_node(temp_root->left, item);
    return (temp_root);
  }
  else if (temp_root->data < item)
  {
    temp_root->right = del_node(temp_root->right, item);
    return (temp_root);
  }
  else
  {
      if (temp_root->left == NULL)
  {
    node *temp = temp_root->right;
    delete temp_root;
    return (temp);
  }
  else if (temp_root->right == NULL)
  {
    node *temp = temp_root->left;
    delete temp_root;
    return (temp);
  }

    node *successor = temp_root->right;

    while (successor->left != NULL)
      successor = successor->left;

    temp_root->data = successor->data;

    temp_root->right = del_node(temp_root->right, successor->data);

    return temp_root;
  }
}

int main()
{
  tree t;
//  t.root = t.insert(t.root, 44);
  t.root = t.insert(t.root, 10);
  node *p = t.root;

  //vector<int> v = {17, 28, 29, 88, 97, 65, 54, 82, 76, 80, 78};
vector<int> v = {5, 17, 3, 7, 12, 19, 1, 4, 13, 3};

  for(int i=0; i<v.size(); i++)
    p = t.insert(p, v[i]);

  t.in_order(t.root);
  cout << endl;
  //node *q = t.search(17);
  t.root = t.del_node(t.root, 3);
  t.in_order(t.root);
  cout << endl;

  return 0;
}
