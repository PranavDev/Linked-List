# include<stdio.h>
# include<stdlib.h>

struct node
{
	int info;
	struct node *nxt;
}*head,*ptr,*prev,*q,*next,*current,*insertionPtr,*P,*Q;

struct node *Reverse();
struct node *InsertionSort();
void display(struct node *P);

int main()
{
	int i,N;
	
	head = (struct node*)malloc(sizeof(struct node));
	head->nxt = NULL;
	printf("Enter the data for the Head node : ");
	scanf("%d",&head->info);
	ptr = head;
	
	printf("Enter the no. of Nodes : ");
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		q = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data for node %d : ",i+1);
		scanf("%d",&q->info);
		q->nxt = NULL;
		ptr->nxt = q;
		ptr = q;
	}
	
	printf("\n\nReverse the List : \n\n");
	P = Reverse();
	
	display(P);
	
	printf("\n\n");
	
	printf("Inserion Sort : \n\n");
	
	Q = InsertionSort();
	
	display(Q);
	
	return 0;
}

struct node *Reverse()
{
	prev = NULL;
	ptr = head;
	while(ptr!=NULL)
	{
	    next = ptr->nxt;
	    ptr->nxt = prev;
	    prev = ptr;
	    ptr = next;
	}
	head = prev;
	
	return head;
}

void display(struct node *P)
{
	while(P->nxt!=NULL)
	{
		printf("%d ",P->info);
		P = P->nxt;
	}
	printf("%d",P->info);
}

struct node *InsertionSort()
{
	current = head;
	insertionPtr = current;
	current = current->nxt;
	
	while(current!=NULL)
	{
		insertionPtr = head;
		
		while(insertionPtr!=current)
		{
			if(insertionPtr->info > current->info)
			{
				int temp = current->info;
				current->info = insertionPtr->info;
				insertionPtr->info = temp;
			}
			else
			{
				insertionPtr = insertionPtr->nxt;
			}
		}
		current = current->nxt;
	}
	return head;
}





