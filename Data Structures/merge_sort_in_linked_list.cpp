    #include <bits/stdc++.h> 

    using namespace std; 

    class node
    { 
        public: 
        int val; 
        node* next; 
    }; 

    node* root = NULL; 

    node* SortedMerge(node* root, node* b) 
    { 
        node* result = NULL; 

        if (root == NULL) 
            return (b); 
        else if (b == NULL) 
            return (root); 

        if (root->val <= b->val) { 
            result = root; 
            result->next = SortedMerge(root->next, b); 
        } 
        else { 
            result = b; 
            result->next = SortedMerge(root, b->next); 
        } 
        return (result); 
    } 

    void FrontBackSplit(node* head, node** front, node** back) 
    { 
        node* fast;
        node* slow;
        slow = head; 
        fast = head->next; 

        while (fast != NULL) { 
            fast = fast->next; 
            if (fast != NULL) { 
                slow = slow->next; 
                fast = fast->next; 
            } 
        } 

        *front = head;
        *back = slow->next; 
        slow->next = NULL;
    }

    void MergeSort(node** temp)
    { 
        node* head = *temp; 
        node* root; 
        node* b; 

        if ((head == NULL) || (head->next == NULL)) 
            return; 

        FrontBackSplit(head, &root, &b); 

        MergeSort(&root); 
        MergeSort(&b); 

        *temp = SortedMerge(root, b); 
    } 


    void printList() 
    {
        node *temp = root; 
        while (temp != NULL) { 
            cout << temp->val << " "; 
            temp = temp->next; 
        }
        cout << endl;
    } 

    void push(node** head_ref, int new_data) 
    { 
        node* new_node = new node(); 

        new_node->val = new_data; 

        new_node->next = (*head_ref); 

        (*head_ref) = new_node; 
    } 

    void ins(int val)
    {
        push(&root, val);
        MergeSort(&root);
    }

    void dlt()
    {
        if(root == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        node *tmp;
        tmp = root;
        root = root->next;
    }

    int main() 
    { 
        ins(15); 
        ins(10); 
        ins(5); 
        ins(20); 
        ins(3); 
        ins(2); 

        printList(); 
        dlt();
        printList();
        return 0; 
    } 

