#include<stdio.h>
#define size 6
#include<malloc.h>
int arr[size],t=-1;

										// USING ARRAY //
void push()
{
	if(t==size-1)
	{
		printf("Stack is overflow");
	}
	else
	{
		printf("Enter data to be pushed :");
		scanf("%d",&arr[++t]);
	}
 	
}
void pop()
{
	if(t==-1)
	{
		printf("Underflow");
	}
	else
	{
		printf("Deleted elemnt is : %d",arr[t--]);
	}
}
void display()
{
	if(t==-1)
	{
		printf("\nEmpty stack");
	}
	else
	{
		printf("\nStack elems are :\n");
		for(int i=t;i>=0;i--)
		{
			printf("%d\n",arr[i]);
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.exit");
		printf("enter ur choice:");
		scanf("%d",&ch);
		if(ch==1)
			push();
		else if(ch==2)
			pop();
		else if(ch==3)
			display();
		else if(ch==4)
			break;
		else
			printf("\nInvalid choice ");
	}
}

                                        // USING LINKED LIST \\
                
struct node{
	int data;
	struct node* next;
};
struct node*head=NULL;
void Push()
{
	struct node* n=(struct node*)malloc(sizeof(struct node*));
	if(head==NULL)
	{
		printf("enter data: ");
		scanf("%d",&n->data);
		n->next=head;
		head=n;
		head->next=NULL;
		
	}
	else
	{
		printf("\nenter data: ");
		scanf("%d",&n->data);
		n->next=head;
		head=n;
	}
}
void Pop()
{
	if(head==NULL)
	{
		printf("\nUnderflow");
	}
	else
	{
		struct node* temp=head;
		head=temp->next;
		printf("Delete elem is : %d",temp->data);
		free(temp);
		
	}
}
void Display()
{
	if(head==NULL)
	{
		printf("\nEmpty Stack");
	}
	struct node* p=head;
	while(p!=NULL)
	{
		printf("\n%d\n",p->data);
		p=p->next;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.exit");
		printf("enter ur choice:");
		scanf("%d",&ch);
		if(ch==1)
			Push();
		else if(ch==2)
			Pop();
		else if(ch==3)
			Display();
		else if(ch==4)
			break;
		else
			printf("\nInvalid choice ");
	}
}
