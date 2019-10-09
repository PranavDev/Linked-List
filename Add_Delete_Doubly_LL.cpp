/* Implement ADD and DELETE operations of Queue on Doubly Linked Lists */

# include<stdio.h>
# include<conio.h>
# include<malloc.h>

int N,i,choice;
int front,rear;
char ch;
int dt,value,max,x,m;

void enQueue_rear();
int deQueue_front();
void display();

struct DLinked_List
{
	int data;
	struct DLinked_List* prev;
	struct DLinked_List* Nxt;
	
}*head,*p,*q;


int main()
{
	front = -1;
	rear = -1;
	
	printf("Implementing the ADD and DELETE operations of Queue on Doubly Linked List\n\n");
	printf("Enter the maximum size of the List : ");
	scanf("%d",&max);
	printf("\n");
	
	do
	{
	    printf("\nChoice of Operations are :\n\n");
	    printf("1.ADD Element from rear\n");
	    printf("2.DELETE Element from front\n\n");
	    printf("Enter Your Choice : ");
	    scanf("%d",&choice);
	    
	    switch(choice)
	    {
	    	case 1 : printf("\nYou Have Chosen to ADD Element from rear\n\n");
	    	         printf("Enter the no. of Numbers to be enQueued at a time : ");
	    	         scanf("%d",&N);
	    	         for(i=0;i<N;i++)
	    	         {
	    	         	printf("Enter the Element %d : ",i+1);
			         	scanf("%d",&value);
			         	enQueue_rear();
					 }
					 printf("\n");
					 display();
					 break;
					 
			case 2 : printf("\nYou Have Chosen to Delete Element from front\n\n");
			         printf("Enter the no. of Numbers to be deQueued at a time : ");
			         scanf("%d",&N);
			         for(i=0;i<N;i++)
			         {
			         	x = deQueue_front();
			         	printf("Element Removed is : %d",x);
			         	printf("\n");
					 }
					 printf("\n");
					 display();
					 break;
	    	         
	    	default : printf("Wrong Choice\n");
	    	          break;
		}
		
		printf("Do You Want to Continue (Y/N) : ");
		ch = getch();
		printf("\n\n");
		
	}while(ch=='Y'||ch=='y');

    return 0;
}

void display()
{
	if(head!=NULL)
	{
	    p = head;
	    while(p->Nxt!=NULL)
	    {
		    printf("%d ",p->data);
		    p = p->Nxt;
	    }  
	    printf("%d ",p->data);
	    printf("\n\n");
    }
}

void enQueue_rear()
{
	if(head==NULL)
	{
		head = (struct DLinked_List*)malloc(sizeof(struct DLinked_List));
		if(head==NULL)
		{
		    printf("List is Full\n");
			return;
		}
		head->prev = NULL;
		head->data = value;
		head->Nxt = NULL;
		p = head;
	}
	else
	{
	    rear++;
		q = (struct DLinked_List*)malloc(sizeof(struct DLinked_List));
		if(q==NULL)
		{
		    printf("The List is Full\n");
			return;
		}
		q->data = value;
		q->Nxt = NULL;
		q->prev = p;
		p->Nxt = q;
		p = q;
	}
	
}

int deQueue_front()
{
	if(head==NULL && p==NULL)
	{
		printf("The List is Empty\n");
	}
	else
	{
		if(head==p)
		{
			front = -1;
			rear = -1;
		    p->prev = NULL;
		    p->Nxt = NULL;
		    m = p->data;
			free(p);
			head=NULL;
			free(head);		
		}
		else
		{
			front++;
			q = head;
			head = q->Nxt;
			q->Nxt = NULL;
			q->prev = NULL;
			m = q->data;
			free(q);
		}
		
	}
	return m;
}

