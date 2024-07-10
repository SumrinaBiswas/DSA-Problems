#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define size 6
struct elem{
	int data;
	int priority;
};
elem a[size];
int t=-1;

void enqueue()
{
	if(t==size-1)
	{
		printf("\nOverflow");
	}
	else
	{
		printf("\nEnter data: ");
		scanf("%d",&a[++t].data);
		printf("\nEnter priority: ");
		scanf("%d",&a[t].priority);			// ++t will denote next element of array so it is not used
	}
}

int peek()
{
	int count=0;
	if(t==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		
		int max=a[0].priority;
		for(int i=0;i<=t;i++)
		{
			if(a[i].priority>max)
			{
				max=a[i].priority;
				count=i;
			}
		}
		printf("\nPeek: %d\npriority: %d",a[count].data,a[count].priority);
	}
	return count;
}
void dequeue()
{
	if(t==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		int ind=peek();
		printf("\nDeleted item: %d\npriority: %d",a[ind].data,a[ind].priority);
		for(int i=ind;i<t;i++)
		{
			a[i].data=a[i+1].data;
			a[i].priority=a[i+1].priority;
		}
		t--;
	}
}

void display()
{
	printf("elems are :	");
	for(int i=0;i<=t;i++)
	{
		printf("%d||%d\t",a[i].data,a[i].priority);
	}
}
int main()
{
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n0. Exit");
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
			enqueue();
		else if (ch==2)
			dequeue();
		else if (ch==3)
			display();
		else if (ch==4)
			peek();
		else if (ch==0)
			break;
		else
			printf("\nInvalid");
	}
}
