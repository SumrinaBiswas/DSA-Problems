#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node* next;
};
struct node* last=NULL;

void pushbeg()
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be pushed: ");
	scanf("%d",&n->data);
	
	if(last==NULL)
	{
		n->next=n;
		last=n;
		last->next=n;    // not necessary
	}
	else
	{
		n->next=last->next;
		last->next=n;
	}
	
}
void pushend()
{
		struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be pushed: ");
	scanf("%d",&n->data);
	
	if(last==NULL)
	{
		n->next=n;
		last=n;
		last->next=n;    // not necessary
	}
	else
	{
		n->next=last->next;
		last->next=n;
		last=n;
	}
}
int length()
{
		struct node* p=last->next;
		int count=0;
		
		
		while(p!=last)
		{
			count=count+1;
			p=p->next;
		}
	return (count+1);	
}
void delbeg()
{
	if(last==NULL)
	{
		printf("\nUnderflow");
	}
	else if(last==last->next)
	{
		struct node* p=last;
		printf("\n deleted data :%d",p->data);
		last=NULL;
		free(p);
	}
	else
	{
		struct node* p=last->next;
		last->next=p->next;
		printf("\n deleted data :%d",p->data);
		p->next=NULL;
		free(p);
	}
}
void delend()
{
	if(last==NULL)
	{
		printf("\nUnderflow");
	}
		else if(last==last->next)
	{
		struct node* p=last;
		printf("\n deleted data :%d",p->data);
		last=NULL;
		free(p);
	}
	else
	{
			struct node* x=last;
			struct node* p=last->next;
			while(p->next!=last)
			{
				p=p->next;
			}
			p->next=last->next;
			last->next=NULL;
			last=p;
			printf("\n deleted data :%d",x->data);
			free(x);
	}
}
void pushpos()
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	int pos;
	printf("\nEnter data: ",n->data);
	scanf("%d",&n->data);
	printf("\nEnter position : ");
	scanf("%d",&pos);
	if(pos==1)
	{
		n->next=last->next;
		last->next=n;	//pushbeg();
	}
	else if(pos==length())
	{
		n->next=last->next;
		last->next=n;
		last=n;//pushend();
	}
	else
	{
		struct node* p=last->next;
		for(int i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		n->next=p->next;
		p->next=n;
	}
}
void deldata()
{
	int d,fl=0;
	printf("\nEnter data: ",d);
	scanf("%d",&d);
	struct node* p=last->next;
	struct node* x=p->next;
	if(p->data==d)
	{
		delbeg();
	}
	else if(last->data==d)
		delend();
	else
	{
		while(p!=last)
		{
			if(p->next->data==d)
			{
				fl=1;
				
				break;
			}
			else
				p=p->next;
				x=x->next;
		}
		if(fl==0)
		{
			printf("\n not found");
		}
		else
		{
			printf("\nDeleted data: %d",x->data);
			p->next=x->next;
			free(x);
		}
	}
}
void insert_after_data()
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ",n->data);
	scanf("%d",&n->data);
	
	int d;
	printf("\nEnter data for execution: ",d);
	scanf("%d",&d);
	if(last->data==n->data)
	{
		n->next=last->next;		//pushend
		last->next=n;
		last=n;
	}
	else
	{
		struct node* p=last->next;
		while(p!=last)
		{
			if(p->data==d)
			{
				printf("\n insert after : %d",p->data);
				n->next=p->next;
				p->next=n;
				break;
			}
			else
				p=p->next;
		}
		
	}
	
}
void insert_before_data()
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ",n->data);
	scanf("%d",&n->data);
	
	int d;
	printf("\nEnter data for execution: ",d);
	scanf("%d",&d);
	if(last->data==n->data)
	{
		n->next=last->next;		//pushbeg
		last->next=n;
	}
	else
	{
		struct node* p=last->next;
		while(p!=last)
		{
			if(p->next->data==d)
			{
				printf("\n insert before : %d",p->next->data);
				n->next=p->next;
				p->next=n;
				break;
			}
			else
				p=p->next;
		}
		
	}
		
	}

void lsrch()
{
	int d;
	int fl=0, count=0;
	printf("\nEnter data: ",d);
	scanf("%d",&d);
	
	struct node* p=last->next;
	for(int i=1;i<=length();i++)
	{
		if(p->data==d)
		{
			printf("\n%d is foundt at %d",p->data,i);
			fl=1;
			break;
		}
		else
		{
			p=p->next;
		}
	}
	if(fl==0)
		printf("\nnot found");
}
void display()
{
	struct node* p=last->next;
	if(last==NULL)
		printf("\nEmpty list");
	else
	{
	
		do{
		printf("%d\t",p->data);
		p=p->next;
		}while(p!=last->next);
	}
}
int main()
{
	
	while (true)
	{
		printf("\n\n1. pushbeg()\n2. disp()\n3. pushend()\n4. delend()\n5.delbeg()\n6. lsrch()\n7. deldata()\n8.insert_after_data()\n9. insert_before_data()\n10. exit\n11. length\n 12.pushpos");
		int ch;
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		if (ch==1)
			pushbeg();
		else if (ch==2)
			display();
		else if(ch==3)
			pushend();
		else if(ch==4)
			delend();
		else if(ch==5)
			delbeg();
		else if(ch==6)
			lsrch();
		else if(ch==7)
			deldata();
		else if(ch==8)
			insert_after_data();
		else if(ch==9)
			insert_before_data();
		else if (ch==10)
			break;
		else if(ch==11)
			printf("%d is length",length());
		else if(ch==12)
			pushpos();
		else
			printf("\nInvalid");
	}
}
