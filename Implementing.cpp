# include<stdio.h>
# include<conio.h>
# include<string.h>
# include<malloc.h>

int n,i,j,dt,value;
int ch1;
void Add_Node();
void Delete_Node();
void display();

struct Node
{
	int data;
	struct Node *ptr;
	
}*p,*q,*head;

int main()
{
	head = NULL;
	printf("This is the Insertion of New Nodes Program\n\n");
		    
	printf("Enter the Size of the List : ");
	scanf("%d",&n);
	printf("\n");
	
	printf("Adding Nodes : \n\n");            
    Add_Node();
    
	printf("\n\n");
	printf("The Output : ");
	display();
			    
	printf("\n\n");
	
	return 0;
}


void Add_Node()
{
	printf("Enter the Data for the First Node : ");
	scanf("%d",&dt);
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data = dt;
	head->ptr = NULL;
	p = head;
	
	for(i=0;i<n;i++)
	{
		q = (struct Node*)malloc(sizeof(struct Node));
	    printf("Enter the Element : ");
	    scanf("%d",&value);
	    q->data = value;
	    q->ptr = NULL;
	    p->ptr = q;
	    p = q;
	}
	
}


void display()
{
	if(head==NULL)
	{
		printf("The List is Empty\n");
	}
	else
	{
		q = head;
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q = q->ptr;
		}
	}
}
