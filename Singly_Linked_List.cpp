# include<stdio.h>
# include<malloc.h>
# include<conio.h>

void Create();
void Add_to_Begin();
void Add_to_End();
void Add_Random();
void display();
void Delete_Begin();
void Delete_End();
void Delete_Random();
void Sort();
void count();

struct Node
{
	int data;
	struct Node *ptr;
	
}*head,*p,*q,*r,*tmp;

int ch,n,i,dt,pos,c;
char choice;

int main()
{
	head = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the Data for the Head Node : ");
	scanf("%d",&(head->data));
	head->ptr = NULL;
	p = head;
	printf("\n");
	
	do
	{
		printf("\n1.Creating Linked List.\n");
		printf("2.Adding at Beginning.\n");
		printf("3.Adding at End.\n");
		printf("4.Adding at a Random place.\n");
		printf("5.Delete from Beginning.\n");
		printf("6.Delete from End.\n");
		printf("7.Delete from Random place.\n");
		printf("8.Count the length of list.\n");
		printf("9.Sorting the Entered Elements.\n\n");
		printf("Enter your Choice : ");
		scanf("%d",&ch);
		printf("\n");
		
		switch(ch)
		{
			case 1 : printf("You Have Chosen to Create a Linked List\n\n");
			         printf("Enter the Nodes You want to add : ");
			         scanf("%d",&n);
			         printf("\n");
					 	                 
			         for(i=0;i<n;i++)
			         {
			         	printf("Enter the Element %d : ",i+1);
			         	scanf("%d",&dt);
			         	Create();
					 }
					 
					 printf("\n\n");
					 printf("The List is : ");
					 display();
					 break;
					 
			case 2 : printf("You Have Chosen to Add a Node at Beginning\n\n");
			         printf("Enter the Data to be Entered at Beginning : ");
			         scanf("%d",&dt);
			         Add_to_Begin();
			         printf("\n\n");
			         printf("The List is : ");
			         display();
			         break;
			         
			case 3 : printf("You Have Chosen to Add a Node at End\n\n");
			         printf("Enter the Data to be Entered at End : ");
			         scanf("%d",&dt);
			         Add_to_End();
			         printf("\n\n");
			         printf("The List is : ");
			         display();
			         break;
			         
			case 4 : printf("You Have Chosen to Add Element in a Random Place\n\n");
			         printf("We will first have to create a Linked List \n\n");
			         
			         printf("Enter the Data to be Entered : ");
			         scanf("%d",&dt);
			    
			         printf("Enter the position where you want to enter the Element : ");
			         scanf("%d",&pos);
			         
			        Add_Random();
			        
			         printf("\n");
			         display();
					 break;
			         
			case 5 : printf("You Have Chosen to Delete from the Beginning\n\n");
			         Delete_Begin();
			         printf("\n\n");
			         display();
			         break;
			         
			case 6 : printf("You Have Chosen to Delete from the End\n\n");
			         Delete_End();
			         printf("\n\n");
			         display();
			         break;
			         
			case 7 : printf("You Have Chosen to Delete from the Random Place\n");
			         printf("Enter the Position from where you want to Delete the Element : ");
			         scanf("%d",&pos);
			         printf("\n");
			         Delete_Random();
			         printf("\n\n");
			         display();
			         break;
			         
			case 8 : printf("You Have Chosen to Count the Length of List\n");
			         count();
			         printf("\n\n");
			         display();
			         break;
			         
			case 9 : printf("You Have Chosen to Sort the Elements After Inserting An Element\n");
			         printf("Enter the Data of the Element to be Added : ");
			         scanf("%d",&dt);
			         Sort();
			         printf("\n\n");
			         display();
			         break;
			         
			default : printf("Wrong Choice\n");
			          break;
		}
		
		printf("Do you want to continue (Y/N) : ");
		choice = getch();
		
	}while(choice=='Y' || choice=='y');
	
	return 0;
}


void Create()
{
	q = (struct Node*)malloc(sizeof(struct Node));
	q->data = dt;
	q->ptr = NULL;
	p->ptr = q;
	p = q;
}

void Add_to_Begin()
{
	p = head;
	q = (struct Node*)malloc(sizeof(struct Node));
	q->data = dt;
	q->ptr = p;
	p = q;
	head = q;
}

void Add_to_End()
{
	p = head;
	q = (struct Node*)malloc(sizeof(struct Node));
	q->data = dt;
	while(p->ptr!=NULL)
	{
		p = p->ptr;
	}
	p->ptr = q; 
	q->ptr = NULL;
}

void display()
{
	p = head;
	while(p->ptr!=NULL)
	{
		printf("%d ",p->data);
		p = p->ptr;
	}
	printf("%d ",p->data);
	printf("\n\n");
	printf("End of the List\n");
}

void Add_Random()
{
	q = (struct Node*)malloc(sizeof(struct Node));
	q->data = dt;
	p = head;
	for(i=0;i<pos-1;i++)
	{
	    p = p->ptr; 
    }
    q->ptr = p->ptr;
    p->ptr = q;
}

void Delete_Begin()
{
	p = head;
	head = head->ptr;
	p->ptr=NULL;
	free(p);
}

void Delete_End()
{
	p = head;
	q = p->ptr;
	while(q->ptr!=NULL)
	{
		p = q;
		q = q->ptr;
    }
	p->ptr = NULL;
	free(q);
}

void Delete_Random()
{
	p = head;
	q = p->ptr;
	for(i=0;i<pos-1;i++)
	{
		p = q;
		q = q->ptr;
	}
	p->ptr = q->ptr;
	q->ptr = NULL;
	free(q);
}

void count()
{
	p = head;
	while(p->ptr!=NULL)
	{
		c++;
		p = p->ptr;
	}
	printf("Length of List is : %d",c+1);
}

void Sort()
{
	p = head;
	q = p->ptr;
	r = q->ptr;
	tmp = head->ptr;
	
	for(i=0;i<c;i++)
	{    
	    while(p->data < q->data && p->data < r->data)
	    {
	    	p = p->ptr;
	    	q = q->ptr;
	    	r = r->ptr;
		}
		while(p->data > q->data)
		{
			if(q->data > r->data)
			{
				q->ptr = r->ptr;
				r->ptr = q;
				p->ptr = r;
				q = r;
				r = r->ptr;
			}
			else
			{
				if(head->ptr = p)
				{
					p->ptr = q->ptr;
					q->ptr = p;
					tmp = q;
				}
			}
		}
	}
}
