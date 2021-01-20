#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include<math.h>
struct node 
{ 
	int data; 
	char symbol;
	char s[1];
	struct node *left, *right; 
};
struct node* newNode(int a, char b, int c) 
{
    struct node* n =(struct node *)malloc(sizeof(struct node));
    if(c == 1)
	{
		n->data = a;
		n->symbol = b;	
		n->s[0] = b;	
	}
    else
	{
		n->symbol = b; 
		n->s[0] = b;	
	}
	n->left = n->right = NULL; 
	return n; 
} 
int isoperand(char j)
{
	if(j=='+'||j=='-'||j=='*'||j=='/'||j=='^'||j==')')
	   return 0;
	else
		return 1;
}
int getPriority(char p)
{
    switch(p)
    {
	    case '(':
	    return 0;
	    case ')':
	    return 0;
	    case '+':
	    return 1;
	    case '-':
	    return 1;
	    case '*':
	    return 2;
	    case '/':
	    return 2; 
	    case '^':
	    return 3;
    } 
}
int isValidChar(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == '0' || s == '1' || 
	   s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' ||  s == '8' || s == '9' ||  	   
	   s == ')' )
	   return 1;
	else
		return 0;
}
struct node* build(char q[],int n) 
{
	struct node* Num[50]; 
	char C[50]; 
    struct node*t = (struct node *) malloc( sizeof(struct node) );
    struct node*t1 = (struct node *) malloc( sizeof(struct node) );
    struct node*t2 = (struct node *) malloc( sizeof(struct node) );
    int i;
    int v,f=0;
    int ct=-1,nt = -1;
	for (i=0;i<n;i++) 
	{ 
		if (q[i] == '(')
		{ 
			f=0;  
			ct++;
			C[ct] = q[i];
		} 
		else if (isoperand(q[i])) 
		{   
			v = q[i] - '0';
			if(f == 1) 
			{
			Num[nt]->data = Num[nt]->data *10 + v;
			}
			else
			{
			t = newNode(v,q[i],1); 
			nt++;
			Num[nt] = t; 
			} 
			f=1;
		} 
		else if (getPriority(q[i]) > 0) 
		{   
		f=0; 
		while ( ct!= -1 && C[ct] != '('
				&& ((q[i] != '^' && getPriority(C[ct]) >= getPriority(q[i])) 
					|| (q[i] == '^'&& getPriority(C[ct]) > getPriority(q[i])))) 
			{ 
			t = newNode(0,C[ct],0);  
			C[ct] = '\0';
			ct--;
			t1 = Num[nt];  
			Num[nt] = '\0';
			nt--;
			t2 = Num[nt];  
			Num[nt] = '\0';
			nt--;
			t->left = t2; 
			t->right = t1; 
			nt++;
			Num[nt] = t;
			} 
			ct++;
			C[ct] = q[i];
		} 
		else if (q[i] == ')') { 
		    f= 0;
			while ( ct!= -1 &&C[ct] != '(') 
			{ 
				t = newNode(0,C[ct],0);  
				C[ct] = '\0';
				ct--;
				t1=Num[nt];  
				Num[nt]='\0';
				nt--;
				t2=Num[nt];  
				Num[nt] = '\0';
				nt--;
				t->left = t2; 
				t->right = t1;  
				nt++;
				Num[nt] = t;
			}  
			C[ct] = '\0';
			ct--;
		} 
	} 
	t = Num[nt]; 
	return t; 
} 
int eval(struct node* root)  
{   
	int temp;
    if (!root)  
        return 0;    
    if (!root->left && !root->right)  
        return root->data;  
    int l_val = eval(root->left);  
    int r_val = eval(root->right);  
    switch(root->symbol)
    {
	    case '+':
	            temp=l_val+r_val;break;
	    case '-':
	            temp=l_val-r_val;break;
	    case '*':
	            temp=l_val*r_val;break;
	    case '/':
	            temp=l_val/r_val;break;
	    case '%':
	            temp=l_val%r_val;break;
	    case '^':
	            temp=pow(l_val,r_val);
    }
    return temp;
}  
int main() 
{ 
	int i,n; 
	char s1[100],s2[60];   
    scanf("%s", s1);    
   	n=strlen(s1);    	
   	s2[0]='('; 
   	i=0;
   	while(i<n)
	{
   		if(isValidChar(s1[i]))
   		s2[i+1]=s1[i]; 
		else
		{
	    printf("Invalid");
		return 0;
		}
		i++; 	
	}
   	s2[i+1]=')'; 
	struct node*root=build(s2,n+2); 
	if(root)
	printf("\n%d",eval(root)); 
	else 
    printf("Root is null");
	return 0; 
}