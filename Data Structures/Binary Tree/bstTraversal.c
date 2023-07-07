#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
} treetype;


treetype* create(int);
void insertBST(treetype**, int);
void inorder(treetype*);
void push(treetype* stack[], int *top, treetype* val);
void pop(int *top);
treetype* topVal(treetype *stack[], int top);
void preorderLoop(treetype*);
void preorder(treetype*);
void postorder(treetype*);
void postorderLoop(treetype*);
void inorder(treetype*);
void inorderLoop(treetype*);

int main()
{
	treetype *root = NULL;
	int ch, val;
	
	do {
		printf("1 to insert, 0 to exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter value: ");
			scanf("%d", &val);
			insertBST(&root, val);
			break;
			
			case 0:
			ch = 0;
			break;
			
			default:
			break;
		}
	} while(ch != 0);
	
	//inorder(root);
	//printf("\n");
	printf("Preorder\n");
	preorder(root);
	printf("\n");
	preorderLoop(root);
	printf("\nPostorder\n");
	postorder(root);
	printf("\n");
	postorderLoop(root);
	printf("\nInorder\n");
	inorder(root);
	printf("\n");
	inorderLoop(root);
	return 0;
}

treetype* create(int val)
{
	treetype *p = (treetype*)malloc(sizeof(treetype));
	if(p == NULL)
	{
		printf("No memory");
		return NULL;
	}
	p->info = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void insertBST(treetype** root, int val)
{
	if(*root == NULL)
	{
		*root = create(val);
		return;
	}
	else
	{
		if(val < (*root)->info)
			insertBST(&(*root)->left, val);
		else if(val > (*root)->info)
			insertBST(&(*root)->right, val);
		else
		{
			printf("No repeating elements allowed");
			return;
		}
	}
}

void inorder(treetype *root)
{
	if(root == NULL)
		return;
		
	inorder(root->left);
	printf("%d ",root->info);
	inorder(root->right);
}

void push(treetype* stack[], int *top, treetype* val)
{
	if(*top == 99)
	return;
	
	*top = *top + 1;
	stack[*top] = val;
}

void pop(int *top)
{
	if(*top == -1)
	return;
	
	*top = *top - 1;
}

treetype* topVal(treetype *stack[], int top)
{
	if(top != -1)
	{
		return stack[top];
	}
}

void preorder(treetype *root)
{
	if(root == NULL)
		return;
		
	printf("%d ",root->info);
	preorder(root->left);
	preorder(root->right);
}

void preorderLoop(treetype *root)
{
	treetype *stack[100] = {0};
	treetype *temp = NULL;
	int top = -1;

	
	if(root == NULL)
	return;
	
	push(stack, &top, root);
	while(top != -1)
	{
		temp = topVal(stack, top);
		pop(&top);
		printf("%d ", temp->info);
		
		if(temp->right != NULL)
		push(stack, &top, temp->right);
		if(temp->left != NULL)
		push(stack, &top, temp->left);
	}
}

void postorder(treetype *root)
{
	if(root == NULL)
	return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->info);
}
	
void postorderLoop(treetype *root)
{
	treetype *stack1[100] = {0};
	treetype *stack2[100] = {0};
	treetype *temp = NULL;
	int top1 = -1, top2 = -1;
	
	if(root == NULL)
	return;
	
	push(stack1, &top1, root);
	while(top1 != -1)
	{
		temp = topVal(stack1, top1);
		pop(&top1);
		push(stack2, &top2, temp);
		
		if(temp->left != NULL)
		push(stack1, &top1, temp->left);
		
		if(temp->right != NULL)
		push(stack1, &top1, temp->right);
	}
	
	while(top2 != -1)
	{
		printf("%d ", stack2[top2]->info);
		top2--;
	}
}	

void inorderLoop(treetype *root)
{
	treetype* stack[100] = {0};
	treetype* temp = NULL, *hist = NULL;
	int top = -1;

	if(root == NULL)
	return;

	push(stack, &top, root);
	while(top != -1)
	{
		temp = topVal(stack, top);
		if(hist == NULL || temp->left != hist)
		{
			while(temp->left != NULL)
			{
				temp = temp->left;
				push(stack, &top, temp);
			}
		}
		printf("%d ", temp->info);
		temp = topVal(stack, top);
		hist = temp;
		pop(&top);

		if(temp->right != NULL)
		{
			push(stack, &top, temp->right);
		}
	}	
}
			
		
