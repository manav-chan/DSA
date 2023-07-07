#include <iostream>
#define MAX 100
using namespace std;

class heap // MAX HEAP
{
    int arr[MAX];
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int idx = size;
        arr[idx] = val;

        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[idx] > arr[parent])
            {
                swap(arr[idx], arr[parent]);
                idx = parent;
            }
            else
                return;
        }
    }

    void remove() // removes root
    {
        if (size == 0)
        {
            cout << "empty\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int idx = 1;
        while (idx < size)
        {
            int lchild = 2 * idx;
            int rchild = (2 * idx) + 1;

            if ((lchild <= size) && arr[idx] < arr[lchild])
            {
                swap(arr[idx], arr[lchild]);
                idx = lchild;
            }
            else if ((rchild <= size) && arr[idx] < arr[rchild])
            {
                swap(arr[idx], arr[rchild]);
                idx = rchild;
            }
            else
                return;
        }
    }
    void display()
    {
        for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";

        cout << endl;
    }
};

void heapify(int arr[], int n, int idx)
{
    int largest = idx;
    int lchild = 2 * idx;
    int rchild = (2 * idx) + 1;

    if (lchild <= n && arr[largest] < arr[lchild])
        largest = lchild;
    if (rchild <= n && arr[largest] < arr[rchild])
        largest = rchild;

    if (idx != largest)
    {
        swap(arr[idx], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapifyArr(int arr[], int n)
{
    for(int i = n/2; i > 0; i--)
    heapify(arr,n,i);
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.display();

    int brr[] = { -1,50,52,53,54,55 };
    int n = sizeof(brr) / sizeof(brr[0]) - 1;
    heapifyArr(brr, n);

    for(int i=1;i<=n;i++)
    cout<<brr[i]<<" ";
    
    cout<<"\n";
    return 0;
}