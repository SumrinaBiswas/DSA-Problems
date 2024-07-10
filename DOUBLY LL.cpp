#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	struct node* prev;
	struct node* next;
	int data;
};

struct node* head=NULL;
int len()
{
	int length=0;
	struct node* t=head;
	if(head==NULL)
		return 0;
	else
	{
		while(t!=NULL)
		{
			t=t->next;
			length++;
		}
		return length;	
	}
}
void pushbeg()
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&n->data);
	if(head==NULL)
	{
		head=n;
		n->next=NULL;
		n->prev=NULL;
	}
	else
	{
		head->prev=n;
		n->next=head;
		head=n;
		head->prev=NULL;
	}
}
void pushend()
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&n->data);
	if(head==NULL)
	{
		head=n;
		n->next=NULL;
		n->prev=NULL;
	}
	else
	{
		struct node* t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=n;
		n->prev=t;
		n->next=NULL;
		t=t->next;
	}
}

void pushpos()
{
	int pos;
	struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&n->data);
	printf("Enter the position :");
	scanf("%d",&pos);
	if(pos==1)
	{
		pushbeg();
	}
	else if(pos==len())
	{
		pushend();
	}
	else
	{
		struct node* t=head;
		for(int i=1;i<pos;i++)
		{
		
			t=t->next;	
		}
		n->prev=t->prev;
		t->prev->next=n;
		t->prev=n;
		n->next=t;
		
	}
}
void popbeg()
{
	struct node* t=head;
	head=t->next;
	t->next=NULL;
	head->prev=NULL;
	free(t);
}
void popend()
{
	struct node* t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->prev->next=NULL;
	t->prev=NULL;
	free(t);
}

void poppos()
{
	int pos;
	printf("Enter the position :");
	scanf("%d",&pos);
	if(pos==1)
		popbeg();
	else if(pos==len())
	{
		popend();
	}
	else
	{
		struct node* t=head;
		for(int i=1;i<pos;i++)
		{
			t=t->next;	
		}
		t->prev->next=t->next;
		t->next->prev=t->prev;
		free(t);
	}
}
void popdata()
{
	int d;
	printf("Enter data to be popped : ");
	scanf("%d",&d);
	struct node* t=head;
	for(int i=1;i<=len();i++)
	{
		if(t->data==d)
		{
			if(i==1)
				popbeg();
			else if(i==len())
			{
				popend();
			}
			else
			{
				t->prev->next=t->next;
				t->next->prev=t->prev;
				free(t);
			}
			break;
		}
		t=t->next;
	}
}
void disp()
{
	struct node* p=head;
	struct node* last;
	//Forward LL
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		last=p;            // last element of LL
		p=p->next;
		// if last=p is declared here then last pointer denotes next elem of the last elem of LL which is NULL
	}
	//Reverse LL
	printf("\nReverse: ");
	while(last!=NULL)
	{
		printf("%d\t",last->data);
		last=last->prev;
	}
}
int main()
{
	printf("\n1. pushbeg\n2. pushend\n3. popbeg\n4. popend\n5. pushpos\n6. poppos\n7. popdata\n9. disp\n0. exit\n");
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
			pushbeg();
		else if (ch==2)
			pushend();
		else if (ch==3)
			popbeg();
		else if (ch==4)
			popend();
		else if (ch==5)
			pushpos();
		else if (ch==6)
			poppos();
		else if (ch==7)
			popdata();
		else if (ch==9)
			disp();
		else if (ch==0)
			break;
		else
			printf("\nInvalid choice");
	}
}
