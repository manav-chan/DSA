#include <stdio.h>
#define MAX 50

int read_array(int*, int);
int unique(int*, int*, int);
int check(int*,int*, int, int*);
int print_array(int*, int*, int);

int main()
{
    int n;
    int a[MAX],b[MAX];
    printf("Enter array size\n");
    scanf("%d",&n);

    read_array(a,n);
    unique(a,b,n);
    
}

int read_array(int* x , int n)
{
    for(int i=0;i<n;i++)
    scanf("%d",&x[i]);
    return 0;
}

int unique(int* x, int* y, int n)
{
    int f[n];
    int c = 0;
    for(int i=0;i<n;i++)
    {
        check(y,f,x[i],&c);
    }
    print_array(y,f,c);
}

int check(int* y, int* f, int e, int* c)
{
    for(int i=0;i<*c;i++)
    {
        if(y[i] == e)
        {
        f[i]++;
        return 0; 
        }
    }
    y[*c] = e;
    f[*c] = 1;
    *c = *c+1;
    return 0;
}

int print_array(int* x, int* y, int n)
{
    printf("Elements and Frequency\n");
    for(int i=0;i<n;i++)
    printf("%d\t%d\n",x[i],y[i]);
    return 0;
}
