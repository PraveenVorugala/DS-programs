#include <stdio.h>
#include <stdlib.h> 
 
struct node
{
    int num;
    struct node *next;
}; 
void create(struct node **);    // function for creating persons with circular list
void display(struct node *);   // displays the people in the list
int survivor(struct node **, int);  // function for finding the person who is not killed
  
int main()
{
    struct node *head = NULL;
    int survive, skip;
     
    create(&head);
    printf("The persons in circular list are:\n");
    display(head);
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &skip);
    survive = survivor(&head, skip);
    printf("The person number to survive is : %d\n", survive);
    free(head);
 
    return 0;
}
 
int survivor(struct node **head, int k)
{
    struct node *p, *q;
    int i;
 
    q = p = *head;    // intialised to head
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;   // tracing until the place where we want to kill
            p = p->next;   
        }
        q->next = p->next;  // killing people in list 
        printf("Person number %d has been killed.\n", p->num);
        free(p);
        p = q->next;  //starting count again from next person 
    }
    *head = p;
 
    return (p->num);   // survior number is returned
}

void display(struct node *head)
{
    struct node *temp;
 
    temp = head;
    printf("%d   ", temp->num);
    temp = temp->next;
    while (head != temp)
    {
        printf("%d   ", temp->num);   // display people in list 
        temp = temp->next;
    }
    printf("\n");
}

 
void create (struct node **head)
{
    struct node *temp, *rear;
    int a, ch;
 
    do
    {
        printf("Enter a Person number: ");
        scanf("%d", &a);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = a;    // assigining people number in list 
        temp->next = NULL;
        if (*head == NULL)  // if list is empty 
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you want to add a Person by entering his number [1/0]? ");
        scanf("%d", &ch);
    } while (ch != 0);
    rear->next = *head;   // condition for circular list 
}
 