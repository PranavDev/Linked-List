# include<stdio.h>
# include<stdlib.h>

void AddPoly();
void SubPoly();
void DisplayPoly1();
void DisplayPoly2();
void Display();

struct Node
{
	int coe;
	int expo;
	struct Node *nxt;
}*p,*q,*r,*s,*head1,*head2,*head3,*tmp;

int main()
{
	int n,N,i,j,choice;
	printf(">> Accepting Polynomial 1 entries : \n\n");
	head1 = (struct Node*)malloc(sizeof(struct Node));
	
	printf("Enter the Coefficient for the Head Node : ");
	scanf("%d",&head1->coe);
	
	printf("Enter the Exponent for the Head Node : ");
	scanf("%d",&head1->expo);
	
	head1->nxt = NULL;
	p = head1;
	
	printf("\n\n");
	printf("Enter the no. of Nodes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		q = (struct Node*)malloc(sizeof(struct Node));
		printf("\n\nEnter the Coefficient for this Node : ");
		scanf("%d",&q->coe);
		printf("Enter the Exponent for the Node : ");
		scanf("%d",&q->expo);
		p->nxt = q;
		q->nxt = NULL;
		p = q;
	}
	printf("The Entered Polynomial is : \n\n");
	DisplayPoly1();
	
	printf("\n\n*****************************************************\n\n");
	printf(">> Accepting Polynomial 2 entries : \n\n");
	head2 = (struct Node*)malloc(sizeof(struct Node));
	
	printf("Enter the Exponent for the Head Node : ");
	scanf("%d",&head2->expo);
	
	printf("Enter the Coefficient for the Head Node : ");
	scanf("%d",&head2->coe);
	
	head2->nxt = NULL;
	r = head2;
	
	printf("\n\n");
	printf("Enter the no. of Nodes : ");
	scanf("%d",&N);
	
	for(j=0;j<N;j++)
	{
		s = (struct Node*)malloc(sizeof(struct Node));
		printf("\n\nEnter the Coefficient for this Node : ");
		scanf("%d",&s->coe);
		printf("Enter the Exponent for the Node : ");
		scanf("%d",&s->expo);
		r->nxt = s;
		s->nxt = NULL;
		r = s;
	}
	printf("The Entered Polynomial is : \n\n");
	DisplayPoly2();
	
	printf("\n\n*****************************************************\n\n");
	
	while(1)
	{
	    printf("Select The Type of Operation to be Performed : \n\n");
	    printf("1.Addition of the Two Polynomials\n");
	    printf("2.Subtraction of the Two Polynomials\n");
	    printf("3.Multiplication of the Two Polnomials\n");
	    printf("4.Exit\n\n");
	    printf("Enter your Choice : ");
	    scanf("%d",&choice);
	
	    switch(choice)
	    {
		    case 1 : printf("You Chose : Addition of the Two Polynomials\n\n");
		             AddPoly();
		             printf("Result : \n\n");
		             Display();
		             break;
		         
		    case 2 : printf("You Chose : Subtraction of the Two Polynomials\n\n");
		             SubPoly();
		             printf("Result : \n\n");
		             Display();
		             break;
		         
		    case 4 : printf("You Chose : Exit\n\n");
		             exit(0);
		         
		    default : printf("Wrong Choice\n\n");
		              break;
	    }
    }
	return 0;
}

void AddPoly()
{
	p = head1;
	q = head2;
	head3 = (struct Node*)malloc(sizeof(struct Node));
	head3->nxt = NULL;
	r = head3;
	
	while(p!=NULL && q!=NULL)
	{
		if(p->expo==q->expo)
		{
			r->coe = p->coe + q->coe;
			r->expo = p->expo;
			p = p->nxt;
			q = q->nxt;
		}
		else if(p->expo > q->expo)
		{
			r->coe = p->coe;
			r->expo = p->expo;
			p = p->nxt;
		}
		else
		{
			r->coe = q->coe;
			r->expo = q->expo;
			q = q->nxt;
		}
		tmp = (struct Node*)malloc(sizeof(struct Node));
		r->nxt = tmp;
		tmp->nxt = NULL;
		r = tmp;
	}
	
	while(p!=NULL)
	{
		r->coe = p->coe;
		r->expo = p->expo;
		p = p->nxt;
		tmp = (struct Node*)malloc(sizeof(struct Node));
		r->nxt = tmp;
		tmp->nxt = NULL;
		r = tmp;
	}
	while(q!=NULL)
	{
		r->coe = q->coe;
		r->expo = q->expo;
		q = q->nxt;
		tmp = (struct Node*)malloc(sizeof(struct Node));
		r->nxt = tmp;
		tmp->nxt = NULL;
		r = tmp;
	}
}

void SubPoly()
{
	p = head1;
	q = head2;
	head3 = (struct Node*)malloc(sizeof(struct Node));
	head3->nxt = NULL;
	r = head3;
	
	while(p!=NULL && q!=NULL)
	{
		if(p->expo==q->expo)
		{
			r->coe = p->coe - q->coe;
			r->expo = p->expo;
			p = p->nxt;
			q = q->nxt;
		}
		else if(p->expo > q->expo)
		{
			r->coe = p->coe;
			r->expo = p->expo;
			p = p->nxt;
		}
		else
		{
			r->coe = q->coe;
			r->expo = q->expo;
			q = q->nxt;
		}
		tmp =  (struct Node*)malloc(sizeof(struct Node));
		r->nxt = tmp;
		tmp->nxt = NULL;
		r = tmp;
	}
	
	while(p!=NULL)
	{
		r->coe = p->coe;
		r->expo = p->expo;
		p = p->nxt;
		tmp =  (struct Node*)malloc(sizeof(struct Node));
		r->nxt = tmp;
		tmp->nxt = NULL;
		r = tmp;
	}
	while(q!=NULL)
	{
		r->coe = q->coe;
		r->expo = q->expo;
		q = q->nxt;
		tmp =  (struct Node*)malloc(sizeof(struct Node));
		r->nxt = tmp;
		tmp->nxt = NULL;
		r = tmp;
	}
}

void DisplayPoly1()
{
	p = head1;
	while(p->nxt!=NULL)
	{
		printf("%dx^%d + ",p->coe,p->expo);
		p = p->nxt;
	}
	printf("%dx^%d",p->coe,p->expo);
}

void DisplayPoly2()
{
	q = head2;
	while(q->nxt!=NULL)
	{
		printf("%dx^%d + ",q->coe,q->expo);
		q = q->nxt;
	}
	printf("%dx^%d",q->coe,q->expo);
}

void Display()
{
	q = head3;
	while(q->nxt!=NULL)
	{
		printf("%dx^%d + ",q->coe,q->expo);
		q = q->nxt;
	}
	printf("%dx^%d",q->coe,q->expo);
}
