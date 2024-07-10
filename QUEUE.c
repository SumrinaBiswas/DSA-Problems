#include<stdio.h>
#define size 6
#include<malloc.h>
int arr[size],t=-1;
int i=0;
										// USING ARRAY //
void enqueue()
{
	if(t==size-1)
	{
		printf("\noverflow ");
	}
	else
	{
		printf("Enter data : ");
		scanf("%d",&arr[++t]);
	}
}
void dequeue()
{
	if(t==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		printf("Deleted data  is: %d",arr[i]);
		i++;
		if(i==t+1)
		{
			t=-1;
		}
	}
}
void display()
{
		if(t==-1)
	{
		printf("\nEmpty Queue");
	}
	else
	{
		printf("\nelems are :");
		for(int j=i;j<=t;j++)
		{
			printf("%d\t",arr[j]);
			
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		printf("\nenter ur choice:");
		scanf("%d",&ch);
		if(ch==1)
			enqueue();
		else if(ch==2)
			dequeue();
		else if(ch==3)
			display();
		else if(ch==4)
			break;
		else
			printf("\nInvalid choice ");
	}	

}
										// USING LINKED LIST\\
										
struct node{
	int data;
	struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;

void Enqueue()
{
	struct node* n=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data : ");
	scanf("%d",&n->data);
	if(front==NULL)
	{
		n->next=front;
		front=n;
		rear=front;
		front->next=NULL;
	}
	else
	{
		struct node*p=front;
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		rear=n;
		rear->next=NULL;
		printf("\nfront= %d\n rear=%d",front->data,rear->data);
	}
}
void Dequeue()
{
	struct node* p=front;
	if(front==NULL && rear==NULL)
	{
		printf("Underflow");
	}
	else
	{
		struct node* del=front;
		printf("Deleted elem is : %d",del->data);
		front=front->next;
		free(del);
	}
}
void Display()
{
	if(front==NULL && rear==NULL)
	{
		printf("\nEmpty Queue");
	}
	struct node* p=front;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		printf("\nenter ur choice:");
		scanf("%d",&ch);
		if(ch==1)
			Enqueue();
		else if(ch==2)
			Dequeue();
		else if(ch==3)
			Display();
		else if(ch==4)
			break;
		else
			printf("\nInvalid choice ");
	}
}
