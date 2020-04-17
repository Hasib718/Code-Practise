#include <bits/stdc++.h>

using namespace std;


class node
{
    public:
    int val;
    int height;
    node *left, *right;

    node();
    node(int key)
    {
        val = key;
        height = 1;
        left = NULL;
        right = NULL;
    }
    ~node();
};

class AVL: public node
{    
    public:
    node *root;

    AVL();
    ~AVL();
    int get_height(node *x);
    int get_balance(node *x);
    node *in_order_successor(node *x);
    node *right_rotate(node *y);
    node *left_rotate(node *y);
    node *insert(node *temp_node, int key);
    node *Delete(node *temp_node, int key);
    void pre_order(node *x);
};


node::node(){}
node::~node(){}

AVL::AVL()
{
    root = NULL;
    cout << "Created a AVL Tree" << endl;
}
AVL::~AVL() { cout << "Destroyed the tree" << endl; }

int AVL::get_height(node *x)
{
    if(!x) return 0;
    return x->height;
}

int AVL::get_balance(node *x)
{
    if(!x) return 0;
    return get_height(x->left) - get_height(x->right);
}

node *AVL::in_order_successor(node *x)
{
    node *temp = x;
    
    while(temp->left) temp = temp->left;

    return temp;
}

node *AVL::right_rotate(node *y)
{
    node *x = y->left;
    node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

node *AVL::left_rotate(node *y)
{
    node *x = y->right;
    node *temp = x->left;

    x->left = y;
    y->right = temp;

    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

node *AVL::insert(node *temp_node, int key)
{
    if(temp_node == NULL) return (new node(key));

    if(key < temp_node->val) temp_node->left = insert(temp_node->left, key);
    else if(key > temp_node->val) temp_node->right = insert(temp_node->right, key);
    else return temp_node;

    temp_node->height = 1 + max(get_height(temp_node->left), get_height(temp_node->right));
    
    int balance = get_balance(temp_node);

    //Left Left Case
    if(balance > 1 and key < temp_node->left->val) return right_rotate(temp_node);

    //Right Right Case
    if(balance < -1 and key > temp_node->right->val) return left_rotate(temp_node);

    //Left Right Case
    if(balance > 1 and key > temp_node->left->val)
    {
        temp_node->left = left_rotate(temp_node->left);
        return right_rotate(temp_node);
    }

    //Right Left Case
    if(balance < -1 and key < temp_node->right->val)
    {
        temp_node->right = right_rotate(temp_node->right);
        return left_rotate(temp_node);
    }

    return temp_node;
}

node *AVL::Delete(node *temp_node, int key)
{
    if(!temp_node) return temp_node;

    if(key < temp_node->val)
        temp_node->left = Delete(temp_node->left, key);
    else if(key > temp_node->val)
        temp_node->right = Delete(temp_node->right, key);
    else
    {
        if(!temp_node->left or !temp_node->right)
        {
            node *temp = temp_node->left ? temp_node->left : temp_node->right;

            if(!temp)
            {
                temp = temp_node;
                temp_node = NULL;
            }
            else temp_node = temp;

            delete temp;
        }
        else 
        {
            node *temp = in_order_successor(temp_node->right);

            temp_node->val = temp->val;

            temp_node->right = Delete(temp_node->right, temp->val);
        }
    }
    
    if(!temp_node) return temp_node;

    root->height = 1 + max(get_height(temp_node->left), get_height(temp_node->right));

    int balance = get_balance(temp_node);

    //Left Left Case
    if(balance > 1 and get_balance(temp_node->left) >= 0)
        return right_rotate(temp_node);

    //Left Right Case
    if(balance > 1 and get_balance(temp_node->left) < 0)
    {
        temp_node->left = left_rotate(temp_node->left);
        return right_rotate(temp_node);
    }

    //Right Right Case
    if(balance < -1 and get_balance(temp_node->right) <= 0)
        return left_rotate(temp_node);

    //Right Left Case
    if(balance < -1 and get_balance(temp_node->right) > 0)
    {
        temp_node->right = right_rotate(temp_node->right);
        return left_rotate(temp_node);
    }

    return temp_node;
}

void AVL::pre_order(node *x)
{
    if(x)
    {
        cout << x->val << " ";
        pre_order(x->left);
        pre_order(x->right);
    }
}

int main()
{
    AVL t, p;

    vector<int> v {9, 5, 10, 0, 6, 11, -1, 1, 2};

    for(int i=0; i<9; i++)
        t.root=t.insert(t.root, v[i]);

    cout << "traversal" << endl;
    t.pre_order(t.root);
    cout << endl;

    t.root = t.Delete(t.root, 10);

    t.pre_order(t.root);
    cout << endl;

    return 0;
}