/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include <queue>
class compare
{
    public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minh;
    Node<int> *head = NULL,*tail = NULL;
    
    int k = listArray.size();
    if(k == 0)
        return NULL;
    
    for(int i=0; i<k; i++)
    {
        if(listArray[i] != NULL)
            minh.push(listArray[i]);
    }
    
    while(minh.size() > 0)
    {
        Node<int>* top = minh.top();
        minh.pop();
        
        if(top->next != NULL)
                minh.push(top->next);
        
        if(head == NULL)
        {
            head = tail = top;
        }
        else
        {
            tail->next = top;
            tail = top; // tail = tail->next
        }
    }
    return head;
}
