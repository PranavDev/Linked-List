/*Write a Program to Create A GLL of type A=(a,b,(c,d),e,(f,g),h).Perform EQUIVALENCE Operation on it.*/

# include<stdio.h>
# include<ctype.h>
# include<stdlib.h>

struct gll_node
{
	int flag;
	struct gll_node *next;
	union
	{
		char data;
		struct gll_node *down;
	}U;
}*head,*head1,*head2,*p,*q,*r,*temp,*M,*N;

char str1[50], str2[50];
struct gll_node *Downlist(struct gll_node *q);
struct gll_node *Create_GLL(char str[]);
int Equivalence(struct gll_node *p,struct gll_node *q);
void Display(struct gll_node *p);

int main()
{	
    int Result;
    
	printf(">> This is the Program for the GLL Equivalence >>\n\n\n");
	
	printf("Enter the First Expression : \n");
	scanf("%s",str1);
	
	printf("\n\n");
	
	printf("Enter the Second Expression : \n");
	scanf("%s",str2);
	
	printf("\n\nCreation of GLL : \n\n");
	
	M = Create_GLL(str1);
	
	N = Create_GLL(str2);
	
	printf("The First Expression Entered is : \n");
	Display(M);

	printf("\n\nThe Second Expression Entered is : \n");
	Display(N);
	
	printf("\n\nEquivalence Check >>\n\n");
	
	Result = Equivalence(M,N);
	
	if(Result==1)
    {
    	printf("\n\nThe Expressions are EQUIVALENT!\n\n");
	}
    else
    {
        printf("\n\nThe Expressions are NOT EQUIVALENT!\n\n");
    }
    
	return 0;
}

struct gll_node *Create_GLL(char str[])
{
	int i = 0;

	if(isalpha(str[i]))
	{
		head = (struct gll_node*)malloc(sizeof(struct gll_node));
		head->flag = 0;
		head->U.data = str[i];
		head->next = NULL;
		p = head;
		i++;
	}

	while(str[i]!=NULL)
	{	
		q = (struct gll_node*)malloc(sizeof(struct gll_node));
		
		if(str[i]==',')
    	{
    		i++;
		}
		if(isalpha(str[i]))
		{
			q->flag = 0;
			q->U.data = str[i];
			q->next = NULL;
			p->next = q;
			p = q;
			i++;
		}
		else if(str[i]=='(')
		{
			q->flag = 1;
		    p->next = q;
		    p = q;
		    q->next = NULL;
		    q->U.down = NULL;
		    i++;
		    
		    if(isalpha(str[i]))
		    {
				q = (struct gll_node*)malloc(sizeof(struct gll_node));
			    q->flag = 0;
			    q->U.data = str[i];
			    p->U.down = q;
			    temp = q;
			    q->next = NULL;
			    i++;
			}
		    
		    
	        while(str[i]!=')')
			{
			    if(isalpha(str[i]))
			    {
				    q = (struct gll_node*)malloc(sizeof(struct gll_node));
			        q->flag = 0;
			        q->U.data = str[i];
			        temp->next = q;
			        temp = q;
			        q->next = NULL;
			        i++;
			    }
			    else if(str[i]==',')
			    {
			    	i++;
				}
		    }
		}
		
		if(str[i]==')')
		{
		    i++;
		}
	}
	return head;
}

int Equivalence(struct gll_node *p,struct gll_node *q)
{
	int Ans = 0;
	
	if(p==NULL && q==NULL)
	{
		return 1;
	}
	
	if(p->flag==q->flag)
	{
		if(p->flag==0)
		{
		    if(p->U.data==q->U.data)
			{
				Ans = 1;
			}
			else
			{
				Ans = 0;
			}
		}
		
		else if(p->flag==1)
		{
			Ans = Equivalence(p->U.down, q->U.down);
		}
		
		if(1)
		{
			Ans = Equivalence(p->next,q->next);
		}
		
		if(0)
		{
			return 0;
		}
	}
	return Ans;
}

void Display(struct gll_node *p)
{
	while(p!=NULL)
	{
		if(p->flag==0 && p!=NULL) 
		{
			printf("%c",p->U.data);
			p = p->next;
		}
		else if(p->flag==1)
		{
			q = p;
			q = p->U.down;
			printf("(");
			while(q->flag==0 && q->next!=NULL)
			{
				printf("%c",q->U.data);
			    q = q->next;
			}
			printf("%c",q->U.data);
			printf(")");
			p = p->next;
		}
	}
}
