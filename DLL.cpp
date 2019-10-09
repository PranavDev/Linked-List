# include<stdio.h>
# include<stdlib.h>

struct node
{
	int info;
	struct node *prev;
	struct node *next;
	
}*head,*p,*q,*r;

void Create();
void Display();
void AddAtBeg();
void AddAtEnd();
void AddAtPos();
void DelfromEnd();
void DelfromBeg();
void DelfromPos();

int main()
{
	while(1)
	{
	    int choice;
     	printf("Choose Operation to be Performed on a Doubly Linked List : \n\n");
    	printf("1.Creation of a List\n");
    	printf("2.Insertion at End of a List\n");
	    printf("3.Insertion at Beginning of a List\n");
	    printf("4.Insertion at Any Position in the List\n");
	    printf("5.Deletion from the End of the List\n");
	    printf("6.Deletion from the Beginning of the List\n");
	    printf("7.Deletion from any Position in the List\n");
	    printf("8.Exit\n\n");
	    printf("Enter your Choice : ");
	    scanf("%d",&choice);
	    
	    switch(choice)
	    {
		    case 1 : printf("\n\nYou Chose :- Creation of a List\n\n");
		             Create();
		             printf("\n\n");
	                 printf("The List is : ");
                   	 Display();
	                 printf("*****************************************\n\n");
		             break;
		         
		    case 2 : printf("You Chose :- Insertion at End of a List\n\n");
		             AddAtEnd();
		             printf("\n\nThe List is : ");
		             Display();
		             printf("******************************************\n\n");
		             break;
		         
		    case 3 : printf("You Chose :- Insertion at Beginning of a List\n\n");
		             AddAtBeg();
		             printf("\n\nThe List is : ");
		             Display();
		             printf("******************************************\n\n");
		             break;
		    
		    case 4 : printf("You Chose :- Insertion at Any Position in the List\n\n");
		             AddAtPos();
		             printf("\n\nThe List is : ");
		             Display();
		             printf("******************************************\n\n");
		             break;
		             
		    case 5 : printf("You Chose :- Deletion from the End of the List\n\n");
		             DelfromEnd();
		             printf("\n\nThe List is : ");
		             Display();
		             printf("******************************************\n\n");
		             break;
		             
		    case 6 : printf("You Chose :- Deletion from the Beginning of the List\n\n");
		             DelfromBeg();
		             printf("\n\nThe List is : ");
		             Display();
		             printf("******************************************\n\n");
		             break;
		             
		    case 7 : printf("You Chose :- Deletion from Any Position in the List\n\n");
		             DelfromPos();
		             printf("\n\nThe List is : ");
		             Display();
		             printf("******************************************\n\n");
		             break;
			         
		    case 8 : exit(0);
		         
		    default : printf("Wrong Choice\n\n"); 
		              break;
	    }
	}
	
	return 0;
}


void Create()
{
	int data,n,i;
	
	head = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data for the First Node : ");
	scanf("%d",&head->info);
	head->next = NULL;
	head->prev = NULL;
	p = head;
	
	printf("Enter the no. of Nodes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\n\n");
		q = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data for the %d node : ",i+1);
		scanf("%d",&q->info);
		q->prev = p;
		p->next = q;
		p = q;
		q->next = NULL;
	}
}


void Display()
{
	if(head!=NULL)
	{
	    p = head;
	    while(p->next!=NULL)
	    {
		    printf("%d ",p->info);
		    p = p->next;
	    }
	    printf("%d",p->info);
	    printf("\n\n");
    }
}

void AddAtEnd()
{
	int data;
	p = head;
	r = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Data to be Added at the End of the List : ");
	scanf("%d",&r->info);
	while(p->next!=NULL)
	{
		p = p->next;
	}
	p->next = r;
	r->prev = p;
	r->next = NULL;
}


void AddAtBeg()
{
	int data;
	p = head;
	r = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Data to be Added at the Beginning of the List : ");
	scanf("%d",&r->info);
	if(p->prev==NULL)
	{
		r->next = p;
		p->prev = r;
		r->prev = NULL;
		head = r;
		p = r;
	}
}

void DelfromEnd()
{
	p = head;
	while(p->next!=NULL)
	{
	    p = p->next;
	}
	p->prev->next = NULL;
	p->prev = NULL;
	free(p);
}

void DelfromBeg()
{
	p = head;
	head = head->next;
	p->next = NULL;
    head->prev = NULL;
	free(p);
}

void AddAtPos()
{
	int data,search_data;
	p = head;
	q = (struct node*)malloc(sizeof(struct node));
	printf("Enter the Data after which a New Data Node is to be Added : ");
	scanf("%d",&search_data);
	printf("\n\n");
	printf("Enter the new Data to be Added : ");
	scanf("%d",&data);
	q->info = data;
	while(p->info!=search_data)
	{
		p = p->next;
	}
	q->prev = p;
	p->next->prev = q;
	q->next = p->next;
	p->next = q;
}

void DelfromPos()
{
	int data;
	p = head;
	printf("Enter the Data to be Deleted : ");
	scanf("%d",&data);
	while(p->info!=data)
	{
		p = p->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->next = NULL;
	p->prev = NULL;
	free(p);
}
