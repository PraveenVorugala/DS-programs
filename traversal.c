#include <stdio.h> 
#include <stdlib.h>
struct Node 
{ 
	int key; 
	struct Node *left, *right;  // left and right pointers of node 
};
struct Stack 
{ 
    int size;  // size of stack  
    int top;   // top element of stack 
    struct Node* *array;   // stack array 
}; 
struct Node* newNode(int item) 
{ 
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->key = item;  // adding elements in nodes 
	temp->left = temp->right = NULL;  // for first node left and right pointers are null 
	//printf("%d,",temp->key);
	return temp; 
} 
struct Node* insert(struct Node* node, int key) 
{ 
	if (node == NULL)
		return newNode(key);   
	if (key < node->key)
		node->left = insert(node->left, key);  // insert elements in left side of node
	else if (key > node->key)
		node->right = insert(node->right, key); // insert elements in right side of node
	return node;
} 
struct Stack* createStack(int size) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->size = size; // stack size is stored 
    stack->top = -1; // stack top intialised to -1
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*));  // allocating memory for stack array 
    return stack; 
} 
void push(struct Stack* stack, struct Node* nod) 
{  
    stack->array[++stack->top] = nod; //storing element in stack array 
} 
struct Node* pop(struct Stack* stack) 
{  
    return stack->array[stack->top--]; // popping elements from stack array 
} 
void post(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
    struct Stack* stack = createStack(100); // creating stack of 100
    do
    { 
        while (root) 
        { 
            if (root->right) 
                push(stack,root->right); // pushing right node into stack array 
            push(stack, root); // pushinh root element into stack array 
            root = root->left; // assigining root as root left 
        } 
        root = pop(stack); // popping top element of stack array that is root 
        if (root->right && stack->array[stack->top] == root->right) // checking if 
        { 
            pop(stack);   // popping element from stack 
            push(stack, root);   // push root into stack 
            root = root->right;  // root is right element of root 
        } 
        else 
        { 
            printf("%d ", root->key); 
            root = NULL; 
        } 
    } while (stack->top!=-1); // loop runs unless stack elements are popped 
}
void in(struct Node* root) 
{ 
    if (root != NULL) { 
        in(root->left); //inorder recursive call untill last left node  
        printf("%d ", root->key); 
        in(root->right); //inorder recursive call untill last right node  
    } 
} 
void pre(struct Node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->key);   
     pre(node->left); //preorder recursive call untill last left node   
     pre(node->right); //preorder recursive call untill last right node 
} 
int main() 
{ 
    int n,i;
    int a[100];
	struct Node* root = NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    root=insert(root,a[0]);
    for(i=1;i<n;i++)
    insert(root,a[i]); // insert elements into nodes 
    pre(root); // prorder call 
    printf("\n");
    in(root); // inorder call 
    printf("\n");
    post(root); // postorder call 
	return 0; 
}
