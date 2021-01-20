#include<stdio.h>
#include<string.h>   
#include<stdlib.h>
char a[50],r[50]; //take a array is infix and r array as postfix.
int t;        // top is used for traversing stack.
int stack[50];   // stack used for pushing operators. 

void push(int h)
{
        stack[++t]=h;    // pushing into stack.
}
int pop()
{
        return (stack[t--]); // popping from stack.
}
int priority(char u)  // priority is given to operators for calculating  
{                              // according to precedence.
        



switch(u)
        {
        case '(': return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        default :return 0;
        }
}
void convert()   //function used for converting infix to postfix.
{
         int i,p=0;
        char z;
        char x;
        for(i=0;i<strlen(a);i++) // loop used for traversing infix.
        {
        x=a[i];
        if(x!=' ')
        {
        switch(x)     // any operators will go to cases but operand 
        {                  // comes we will add in postfix.
        case '(':
        push(x);
        break;
        case ')':
        while((z=pop())!='(')
        r[p++]=z;
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        while( t!=-1 &&  priority(stack[t])>= priority(x) )
        r[p++]=pop();    // priority checking in while loop.
        push(x);         // first operator directly enters stack.
        break;
        default: 
        r[p++]=x;
        }
        }
        }
        while(t!=-1)    // final popping operators from stack and
        r[p++]=pop();    // popping and adding postfix
        r[p]='\0'; 
}

int postfixevaluation()   // postfix evaluation function
{
        int a,b,c,d;
        int i,o,y,x,w;
        char s;
        for(i=0;i<strlen(r);i++)  // for loop traversing postfix
        {
        if(r[i]<='9' && r[i]>='0')  // checking each digit of postfix
        {
        push(r[i]-'0');
        }
        else
        {
        a=pop();   // popping elements sent to stack. 
        b=pop();   // popping elements sent to stack.
        y=(b*10)+a;  // for 2 digit calculation.
        c=pop();    
        d=pop();
        x=(d*10)+c;
        

switch(r[i])
        {
        case '+':
        o=y+x; break;
        case '-':
        o=y-x;break;
        case '*':
        o=y*x;break;
        case '/':
        o=y/x;break;
        case '%':
        o=y%x;break;
        }
        s=o%10;
        w=o/10;
        push(w);   // pushing again into stack for calculating 
        push(s);    // pushing again into stack for calculation
        }
        }
        return o;    // final result stored in o;
}
void main()
{
        int e;
        t=-1;
        printf(" infix : ");
        scanf("%s",a);   // display infix
        convert();  // calling conversion function
        printf("Postfix : %s\n",r);   // postfix display. 
        e=postfixevaluation();    // evaluation fun.
        printf("postfix evaluation : %d\n",e);     // final result.
  }

