#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue *link;
};
void display(struct Queue *pfront)
{
	while(pfront!=NULL)
	{
		printf("%i\t",pfront->data);
		pfront=pfront->link;
	}
}
/*void display(strcut Queue *pfront)
{
	struct Queue *temp=pfront;
	while(temp->link!=pfront)
	{
		printf("\n%i\t",temp->data);
		temp=temp->link;
	}
	printf("%i\t",temp->data);
}*/          //         (Circular)
void delQ(struct Queue **pfront,struct Queue **prear)
{
	if( *pfront == NULL && *prear==NULL)
	{
		printf("Queue is Empty");
	}
	else
	{
		struct Queue *temp=*pfront;
		printf("\nDeleted Data is = %i\n",temp->data);
		*pfront=temp->link;
		if(*pfront==NULL)
		{
			*prear=NULL;
		}
		//*(prear)->link=*pfront;      (Circular)
		free(temp);
	}
}
void addQ(struct Queue **pfront,struct Queue **prear,int data)
{
	struct Queue *r;
	r=(struct Queue*)malloc(sizeof(struct Queue));
	r->data=data;
	r->link=NULL;
	if(*pfront == NULL && *prear == NULL)
	{
		*pfront=r;
		*prear=r;
	}
	else
	{
	    (*prear)->link=r;
	    *prear=r;
//	     r->link=*pfront;          (Circular)
	}
}
void main()
{
	struct Queue *front=NULL;
	struct Queue *rear=NULL;
	addQ(&front,&rear,10);
	addQ(&front,&rear,20);
	addQ(&front,&rear,30);
	display(front);
	delQ(&front,&rear);
	display(front);
	delQ(&front,&rear);
	display(front);
	delQ(&front,&rear);
	display(front);
	delQ(&front,&rear);
	display(front);
}
		
