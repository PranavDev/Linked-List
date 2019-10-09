# include<stdio.h>
# include<stdlib.h>

void AddPoly();
void SubPoly();
void MulPoly();
void DisplayPoly1();
void DisplayPoly2();
void Display();
void AcceptPoly1();
void AcceptPoly2();

struct Node
{
	int expo;
	int coe;
	struct Node *nxt;
}*p,*q,*r,*m,*head1,*head2,*head3;

//main driver

int main()
{
	int choice;
	AcceptPoly1();
	AcceptPoly2();
	
	while(1)
	{
	    printf("\n\nSelect The Type of Operation to be Performed : \n\n");
	    printf("1.Addition of the Two Polynomials\n");
	    printf("2.Subtraction of the Two Polynomials\n");
	    printf("3.Multiplication of Two Polynomials\n");
	    printf("4.Exit\n\n");
	    printf("Enter your Choice : ");
	    scanf("%d",&choice);
	
	    switch(choice)
	    {
		    case 1 : printf("\nYou Chose : Addition of the Two Polynomials\n\n");
		             AddPoly();
		             printf("Result : \n\n");
		             Display();
		             break;
		         
		    case 2 : printf("You Chose : Subtraction of the Two Polynomials\n\n");
		             SubPoly();
		             printf("Result : \n\n");
		             Display();
		             break;
		             
		    case 3 : printf("You Chose : Multiplication of the Two Polynomials\n\n");
		             MulPoly();
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

//Addition Function

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
		if(p!=NULL && q!=NULL)
		{
			m = (struct Node*)malloc(sizeof(struct Node));
		    r->nxt = m;
		    m->nxt = NULL;
		    r = m;
		}
	}
	
	
	while(p!=NULL)                     //Adding the Elements that might be remaining in either of the two Polynomials 
	{
		r->coe = p->coe;
		r->expo = p->expo;
		p = p->nxt;
		r->nxt = (struct Node*)malloc(sizeof(struct Node));
		r = r->nxt;
	}
	while(q!=NULL)                    //Adding the Elements that might be remaining in either of the two Polynomials 
	{
		r->coe = q->coe;
		r->expo = q->expo;
		q = q->nxt;
		r->nxt = (struct Node*)malloc(sizeof(struct Node));
		r = r->nxt;
	}
}

//Subtraction Function

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
			r->coe = (-1) * (q->coe);
			r->expo = q->expo;
			q = q->nxt;
		}
		if(p!=NULL && q!=NULL)
		{
		    m = (struct Node*)malloc(sizeof(struct Node));
		    r->nxt = m;
		    m->nxt = NULL;
		    r = m;
	    }
	}
	
	while(p!=NULL)
	{
		r->coe = (-1) * (p->coe);
		r->expo = p->expo;
		p = p->nxt;
		r->nxt = (struct Node*)malloc(sizeof(struct Node));
		r = r->nxt;
	}
	while(q!=NULL)
	{
		r->coe = (-1) * (q->coe);
		r->expo = q->expo;
		q = q->nxt;
		r->nxt = (struct Node*)malloc(sizeof(struct Node));
		r = r->nxt;
	}
}

//Multiplication Function

void MulPoly()
{
	p = head1;
	q = head2;
	head3 = (struct Node*)malloc(sizeof(struct Node));
	head3->nxt = NULL;
	r = head3;
	
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			r->coe = p->coe * q->coe;
			r->expo = p->expo + q->expo;
			q = q->nxt;
			m = (struct Node*)malloc(sizeof(struct Node));
		    r->nxt = m;
		    m->nxt = NULL;
		    r = m;
		}
		p = p->nxt;
		q = head2;
	}
}

//Displaying Polynomial 1

void DisplayPoly1()
{
	if(head1!=NULL)
	{
	    p = head1;
	    while(p->nxt!=NULL)
	    {
		    printf("%dx^%d + ",p->coe,p->expo);
		    p = p->nxt;
	    }
	    printf("%dx^%d",p->coe,p->expo);
	}
}

//Displaying Polynomial 2

void DisplayPoly2()
{
	if(head2!=NULL)
	{
	    q = head2;
	    while(q->nxt!=NULL)
	    {
		    printf("%dx^%d + ",q->coe,q->expo);
		    q = q->nxt;
	    }
	    printf("%dx^%d",q->coe,q->expo);
	}
}

//Accepting Polynomial 1

void AcceptPoly1()
{
	int n,i;
	printf(">> Accepting Polynomial 1 entries : \n\n");
	head1 = (struct Node*)malloc(sizeof(struct Node));
	
	printf("Enter the Exponent for the Head Node : ");
	scanf("%d",&head1->expo);
	
	printf("Enter the Coefficient for the Exponent entered for the Head Node : ");
	scanf("%d",&head1->coe);
	
	head1->nxt = NULL;
	p = head1;
	
	printf("\n\n");
	printf("Enter the no. of Nodes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		q = (struct Node*)malloc(sizeof(struct Node));
		printf("\n\nEnter the Exponent for the Node %d after Head Node : ",i+1);
		scanf("%d",&q->expo);
		printf("Enter the Coefficient for the Exponent entered for this Node : ");
		scanf("%d",&q->coe);
		q->nxt = NULL;
		p->nxt = q;
		p = q;
	}
	printf("\n\nThe Entered Polynomial is : \n\n");
	DisplayPoly1();
	
	printf("\n");
	printf("*****************************************************\n\n");
}

//Accepting Polynomial 2

void AcceptPoly2()
{
	int j,N;
	printf("\n\n>> Accepting Polynomial 2 entries : \n\n");
	head2 = (struct Node*)malloc(sizeof(struct Node));
	
	printf("Enter the Exponent for the Head Node : ");
	scanf("%d",&head2->expo);
	
	printf("Enter the Coefficient for the Exponent entered for the Head Node : ");
	scanf("%d",&head2->coe);
	
	head2->nxt = NULL;
	q = head2;
	
	printf("\n\n");
	printf("Enter the no. of Nodes : ");
	scanf("%d",&N);
	
	for(j=0;j<N;j++)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		printf("\n\nEnter the Exponent for the Node %d after Head Node : ",j+1);
		scanf("%d",&p->expo);
		printf("Enter the Coefficient for the Exponent entered for this Node : ");
		scanf("%d",&p->coe);
		p->nxt = NULL;
		q->nxt = p;
		q = p;
		
	}
	printf("The Entered Polynomial is : \n\n");
	DisplayPoly2();
	
	printf("\n");
	printf("*****************************************************\n\n");
}

//Display the Resultant Polynomial

void Display()
{
	r = head3;
    while(r->nxt!=NULL)
	{
	    printf("%dx^%d + ",r->coe,r->expo);
	    r = r->nxt;
	}
	printf("%dx^%d",r->coe,r->expo);
}
