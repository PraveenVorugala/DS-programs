#include <stdio.h> 
#include <stdlib.h>
struct node { 
	int key; 
	struct node *left, *right;  // left and right node pointers 
	int c;
}; 
struct node* newNode(int item) 
{ 
	struct node* temp 
		= (struct node*)malloc(sizeof(struct node));   // allocating memory 
	temp->key = item;   // element to the node
	temp->left = temp->right = NULL;  // for left and right node of first node are null 
//	printf("%d,",temp->key);
	return temp; 
} 
struct node* insert(struct node* node, int key) 
{ 
	if (node == NULL)
		return newNode(key); 
	if (key < node->key)
		node->left = insert(node->left, key);  //inserting of left nodes 
	else if (key > node->key)
		node->right = insert(node->right, key);  // inserting of right nodes 
	return node;
} 
int check(struct node *n)
{
   if(n==NULL)
   return 0;
   else
   {
   int h =check(n->left);   // checking left sub tree 
   int t =check(n->right);  // checking right sub tree 
   if(h>t)
   return(h+1);  // returning height 
   else
   return (t+1);
}}
int main() 
{ 
    int n,i;
    int a[100];
	struct node* root = NULL;  // root node 
	scanf("%d",&n);
	if(n==0)
	printf("%d",n);  
	else
	{
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);  
    root=insert(root,a[0]);  // insert function called for inserting elements 
    for(i=1;i<n;i++)
    insert(root,a[i]);
	int r=check(root);  // returns height of tree 
	printf("%d",r);
	}
	return 0; 
}
