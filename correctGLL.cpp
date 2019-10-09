#include<stdio.h>
#include<stdlib.h>

typedef struct gll_node
{
    int flag;
    struct gll_node *next;
    union
    {
        char data;
        struct gll_node *down;
    }link;
}Node;


Node* Create_gll(char str[],int i);
int Equivalence(Node *P, Node *Q);
void Display(Node *P);

char str1[20], str2[20];


int main()
{
    Node *P , *Q , *head1 , *head2;
    int Result,i=0;

    printf("Enter the first expression : \n");
    scanf("%s",str1);
    printf("\nEnter the second expression : \n");
    scanf("%s",str2);

    printf("\n\nCreation of Generalised Linked List : \n\n");

    P = Create_gll(str1,i);

    Q = Create_gll(str2,i);

	
	Display(P);

    Display(Q);

    printf("Equivalence Check : \n\n");
    
    P = head1;
    Q = head2;
    
    Result = Equivalence(P, Q);
    
    if(Result==1)
    {
    	printf("\n\nThe Expressions are EQUIVALENT\n\n");
	}
    else
    {
        printf("\n\nThe Expressions are NOT EQUIVALENT!\n\n");
    }
    return 0;
}


Node* Create_gll(char str[],int i)
{
	Node *temp;
	
    while(str[i]!='\0')
    {
    	temp = (Node*)malloc(sizeof(Node));
	
    	if(str[i]==',')
    	{
    		i++;
		}
	
	    if(str[i]=='(')
	    {
		    temp->flag = 1;
		    i++;
		    temp->link.down = Create_gll(str,i);
	    }
	
	    else if(str[i]!=')' || str[i]!=',')
	    {  
		    temp->flag = 0;
		    temp->link.data = str[i];
		    i++;
            if(str[i]!=NULL)
            {
		        temp->next = Create_gll(str,i); 
            }
	    }   
	
	    else
	    {
		     if(str[i]==')')
		    {
			    free(temp);
			    i++;
			    return NULL;
		    }
	    }
	    return temp;
    }
}


int Equivalence(Node *P, Node *Q)
{
    int Ans = 0;
    
    if(P==NULL && Q==NULL)
    {
    	return 1;
	}
	
    if(P->flag==Q->flag)
    {
        if(P->flag==0)
        {
            if(P->link.data==Q->link.data)
            {
            	Ans = 1;
			}
			else
			{
				Ans = 0;
			}
        }
        else if(P->flag==1)
        {
        	Ans = Equivalence(P->link.down, Q->link.down);
		}

       	if(1)
       	{
       	    Ans = Equivalence(P->next, Q->next);
	    }
    }
	return Ans;	
}


void Display(Node *P)
{
	while(P!=NULL)
	{
		if(P->flag==0)
		{
			printf("%c", P->link.data);
		}
		else if(P->flag==1)
		{
			printf("(");
			Display(P->link.down);
			printf(")\n");
		}
		P = P->next;
	}
}


