#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(){}
    Node(int x)
    {
      data = x;
      left = right = NULL;
    }
    ~Node(){}
};

void *insert(Node *root, int data)
{
  if(root == NULL) return new Node(data);

  if(root->data >= data)
    insert(root->left, data);
  else if(root->data < data)
    insert(root->right, data);

  return (root);
}

void postorderTraversal(Node*);

void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, arr);

    arr.push_back(root->data);

    inorderTraversal(root->right, arr);
}

void BSTToMaxHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;

    BSTToMaxHeap(root->left, arr, i);

    BSTToMaxHeap(root->right, arr, i);

    root->data = arr[++*i];
}

void convertToMaxHeapUtil(Node* root)
{
    vector<int> arr;
    int i = -1;

    inorderTraversal(root, arr);

    BSTToMaxHeap(root, arr, &i);
}

void postorderTraversal(Node* root)
{
    if (!root)
        return;

    postorderTraversal(root->left);

    cout << root->data << " ";

    postorderTraversal(root->right);

}

int main()
{
    Node* root1 = new Node(12);

    root1->left = new Node(7);
    root1->right = new Node(15);
    root1->right->left = new Node(17);
    root1->right->right = new Node(19);
    root1->left->left = new Node(3);
    root1->left->right = new Node(10);
    root1->left->left->left = new Node(2);
    root1->left->left->right = new Node(5);

    convertToMaxHeapUtil(root1);
    cout << "Postorder Traversal of Tree:" << endl;
    postorderTraversal(root1);

    return 0;
}
