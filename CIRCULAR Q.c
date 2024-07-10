#include<stdio.h>
#include<conio.h>
#define size 6
int r=-1,f=-1;
int a[size];

void enq()
{
	if((r+1)%size==f)		// not (size-1) as it is cq
	{
		printf("\nOverflow");
	}
	else if(f==-1 && r==-1)
	{
		f=r=0;
		printf("\nEnter data : ");
		scanf("%d",&a[r]);
	}
	else
	{
		r=(r+1)%size;
		printf("\nEnter data : ");
		scanf("%d",&a[r]);
		
	}
}

void deq()
{
	
	if(f==-1 && r==-1)
		printf("\nUnderflow");
	else if(f==r)
		f=r=-1;
	else
	{
		printf("\nDeleted elem : %d",a[f]);
		f=(f+1)%size;
		printf("\nNew front=%d and rear=%d",a[f],a[r]);
	}
}
void peek()
{
	printf("\nPeek=%d ",a[f]);
}
void display()
{
	if(r==-1 && f==-1)
		printf("\nEmpty list");
	else
	{
		int i=f;
		while(i!=r)
		{
			printf("%d\t",a[i]);
			i=(i+1)%size;
		}
		printf("%d\t",a[r]);
	}
}
int main()
{
	while(1)
	{
		printf("\n\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n0.exit");
		int ch;
		printf("\nEnter choice :");
		scanf("%d",&ch);
		if(ch==1)
			enq();
		else if(ch==2)
			deq();
		else if(ch==3)
			peek();
		else if(ch==4)
			display();
		else if(ch==0)
			break;
		else
			printf("\nInvalid choice");
	}
}

