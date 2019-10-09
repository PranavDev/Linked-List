# include<stdio.h>
# include<stdlib.h>

void Create();
void AddAfter();
void Delete();
void GetLength();
void Display();

struct Node
{
	int info;
	struct Node *Prev;
	struct Node *Next;
}*head,*p,*q;

int main()
{
	int choice;
	while(1)
	{
	    printf("\n\nSelect the Operations to be Performed : \n\n");
	    printf("1.Creation of A Circular Doubly Linked List.\n");
	    printf("2.Adding an Element After a Specified Element.\n");
	    printf("3.Deleting a Specified Element.\n");
	    printf("4.Get the Length of the List.\n");
	    printf("5.Exit.\n\n");
	    printf("Enter your Choice : ");
	    scanf("%d",&choice);
	    
	    switch(choice)
	    {
	    	case 1 : printf("You Chose : Creation of A Circular Doubly Linked List.\n\n");
	    	         Create();
	    	         printf("The List after Creation is : \n\n");
	    	         Display();
	    	         printf("\n\n");
	    	         printf("***********************************************");
	    	         break;
	    	         
	    	case 2 : printf("You Chose : Adding an Element After a Specified Element.\n\n");
	    	         AddAfter();
	    	         printf("The List after Adding an Element is : \n\n");
	    	         Display();
	    	         printf("\n\n");
	    	         printf("***********************************************");
	    	         break;
	    	         
	    	case 3 : printf("You Chose : Deleting a Specified Element.\n\n");
	    	         Delete();
	    	         printf("The List after Deleting an Element is : \n\n");
	    	         Display();
	    	         printf("\n\n");
	    	         printf("***********************************************");
	    	         break;
	    	         
	    	case 4 : printf("You Chose : Get the Length of the List.\n\n");
	    	         printf("The length of the Final List is : \n\n");
	    	         GetLength();
	    	         printf("\n\n");
	    	         printf("***********************************************");
	    	         break;
	    	         
	    	case 5 : printf("You Chose : Exit.\n\n");
	    	         exit(0);
	    	         
	    	default : printf("Wrong Choice\n\n");
	    	          printf("\n\n");
	    	          printf("***********************************************");
	    	          break;
		}
	}
	return 0;
}

void Create()
{
	int N,i;
	head = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the Data for the Head Node : ");
	scanf("%d",&head->info);
	head->Next = NULL;
	head->Prev = NULL;
	p = head;
	printf("\n\n");
	printf("Enter the No. of Node : ");
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		q = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the Data for %d Node after the Head Node : ",i+1);
		scanf("%d",&q->info);
		q->Prev = p;
		p->Next = q;
		p = q;
		q->Next = head;
		head->Prev = q;
	}
}

void AddAfter()
{
	int data_search;
	p = head;
	
	printf("Enter the Data after which a new Data Node is to be Added : ");
	scanf("%d",&data_search);
	
	printf("\n\n");
	
	while(p->info!=data_search)
	{
		p = p->Next;
	}
	q = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the New Data for the Node : ");
	scanf("%d",&q->info);
	p->Next->Prev = q;
	q->Next = p->Next;
	p->Next = q;
	q->Prev = p;
	p = q;
}

void Delete()
{
	int dt;
	p = head;
	printf("Enter the Data Node that is to be Deleted : ");
	scanf("%d",&dt);
	while(p->info!=dt)
	{
		p = p->Next;
		if(p->Next==head)
		{
			printf("Not Found\n");
			exit(1);
		}
	}
	if(head->info==dt)
	{
		p->Prev->Next = p->Next;
	    p->Next->Prev = p->Prev;
	    head = p->Next;
	    p->Next = NULL;
	    p->Prev = NULL;
	    free(p);
	}
	else
	{
		p->Prev->Next = p->Next;
	    p->Next->Prev = p->Prev;
	    p->Next = NULL;
	    p->Prev = NULL;
	    free(p);
	}
}

void Display()
{
	if(head->Next==NULL && head->Prev==NULL)
	{
		p = head;
		printf("%d",p->info);
	}
	else
	{
	    p = head;
	    while(p->Next!=head)
	    {
		    printf("%d ",p->info);
		    p = p->Next;
	    }
	    printf("%d",p->info);
	}
}

void GetLength()
{
	int count = 0;
	p = head;
	if(head->Next==NULL && head->Prev==NULL)
	{
		count = 1;
		printf("%d",count);
	}
	else
	{
		count = 1;
	    while(p->Next!=head && head->Next!=NULL)
	    {
		    count++;
		    p = p->Next;
	    }
	    printf("%d",count);
    }  
}
