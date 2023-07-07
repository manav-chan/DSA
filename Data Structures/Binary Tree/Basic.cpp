#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    node* head = new node(1);
    head->left = new node(2);
    head->right= new node(3);

    head->left->left = new node(4);
    head->left->right= new node(5);
    
    return 0;
}