# include<stdio.h>
# include<stdlib.h>

void Selection_Sort_By_Exchanging_Data();
void Selection_Sort_By_Exchanging_Links();
void Search(int Search_data,int N);

void Display();

struct node
{
	int data;
	struct node *ptr;
}*head,*p,*q,*r,*s,*tmp;

int main()
{
	int data,N,i,Search_data;
	
	head = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the total no. of Nodes : ");
	scanf("%d",&N);
	printf("\n\n");
	printf("Enter the Data for the Head Node : ");
	scanf("%d",&head->data);
	head->ptr = NULL;
	p = head;
	
	for(i=0;i<N;i++)
	{
		q = (struct node*)malloc(sizeof(struct node));
		printf("Enter the Data for the node %d : ",i+1);
		scanf("%d",&q->data);
		p->ptr = q;
		p = q;
		q->ptr = NULL;
	}
	
	printf("\n\n");
	printf("The Linked List is : \n\n");
	Display();
	
	printf("\n\nThe Sorted List by Exchanging Data Method : \n\n");
	Selection_Sort_By_Exchanging_Data();
	Display();
	
	printf("\n\nThe Sorted List by Exchanging Links Method : \n\n");
	Selection_Sort_By_Exchanging_Links();
	Display();
	
	printf("Enter an Element to be Searched : ");
	scanf("%d",&Search_data);
	Search(Search_data,N);
	
	return 0;
}

void Display()
{
	p = head;
	while(p->ptr!=NULL)
	{
		printf("%d ",p->data);
		p = p->ptr;
	}
	printf("%d",p->data);
	printf("\n\n");
}

void Selection_Sort_By_Exchanging_Data()
{
	int temp;
	p = head;
	
	while(p!=NULL)
	{
		q = p->ptr;
		while(q!=NULL)
		{
		    if(p->data > q->data)
		    {
			    temp = p->data;
			    p->data = q->data;
			    q->data = temp;
			    q = q->ptr;
		    }
		    else
		    {
		    	q = q->ptr;
			}
		}
		p = p->ptr;
	}
}

void Selection_Sort_By_Exchanging_Links()
{
    for(r=p=head; p!=NULL ; r = p , p = p->ptr)
    {
    	for(s=q=p->ptr; q!=NULL; s = q , q = q->ptr)
    	{
    		if(p->data > q->data)
    		{
    			tmp = p->ptr;
    			p->ptr = q->ptr;
    			q->ptr = tmp;
    			if(p!=head)
    			{
    				r->ptr = q;
    				s->ptr = p;
				}
				if(p==head)
				{
					head = q;
				}
				tmp = p;
				p = q;
				q = tmp;
			}
		}
	}
}

void Search(int Search_data,int N)
{
	int count = 0;
	p = head;
	while(p!=NULL)
	{
		if(p->data==Search_data)
		{
			printf("Data Entered : %d is found at position %d.",Search_data,count+1);
			break;
		}
		else
		{
			p = p->ptr;
			count++;
		}
		if(count>N)
		{
			printf("\n\nData Entered : %d is not found.",Search_data);
		}
	}
}
