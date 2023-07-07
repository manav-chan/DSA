#include <iostream>
#include <queue>
using namespace std;

struct node
{
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

int height(node* root)
{
    if(root == NULL)
    return 0;
    
    return max(height(root->left),height(root->right)) + 1;
}

int diameter(node* root) // O(n^2) very bad
{
    if(root == NULL)
    return 0;

    int currdia = height(root->left) + height(root->right) + 1;
    return max(currdia,max(diameter(root->left),diameter(root->right)));
}

int diameteropt(node* root, int &dia) // O(n) consider this function as a modification to the height function, best, lh and rh to store hts
{
    if(root == NULL)
    return 0;

    int lh = diameteropt(root->left, dia);
    int rh = diameteropt(root->right,dia);

    dia = max(dia,lh+rh+1); // or max(dai, lh+rh) if we are counting height and diameter by edges 
    return max(lh,rh) + 1;
}

int diameterdidi(node* root, int* height)
{
    if(root == NULL)
    return 0;

    int lh = 0, rh = 0;
    int ldia = diameterdidi(root,&lh);
    int rdia = diameterdidi(root,&rh);

    int currdia = lh + rh + 1;
    *height = max(lh,rh) + 1;
    
    return max(currdia,max(ldia,rdia));
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);

    root->left->left = new node(4);
    root->left->right= new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<height(root)-1<<"\n";
    cout<<diameter(root)<<"\n";

    int dia = 0;
    diameteropt(root,dia);
    cout<<dia<<"\n";    
    return 0;
}