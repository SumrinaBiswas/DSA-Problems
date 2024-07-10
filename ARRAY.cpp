/* Write a menu driven program to perform the following operations on an array.
(a) update an element x at position k in the array.
(b) insert an element x at position k in the array.
(c) search an element x from the array.
(d) remove an element x from the array.
(e) display an element x from the array. */

#include<stdio.h>

void update(int a[],int e,int k,int s)
{
	a[k]=e;
}
void insert(int a[],int e,int k,int s)
{
	int i;
	if(k<0 || k>=s)
		printf("\ninvalid idx");
	else
	{
		for(i=s-1;i>=k;i--)		// right shift (coz taking a void space from right of array)
		{
			a[i+1]=a[i];
		}
		a[k]=e;
		s++;
	}
}
int search(int a[],int e,int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(a[i]==e)
		{
			return i;
			break;
		}
	}
}
void remove(int a[],int e,int s)
{
	int c;
	for(int i=0;i<s;i++)
	{
		if(a[i]==e)
		{
			c=i;
			break;
		}
	}
	for(int i=c;i<s;i++)
	{
		a[i]=a[i+1];
	}
	s--;
}
void display(int a[],int s)
{
	int i;
	for( i=0;i<s;i++)
		printf("%d\t",a[i]);
}
int main()
{
	int n;
	printf("Enter the sizeofarray : ");
	scanf("%d",&n);
	int ar[n],i;
	printf("enter array elems:");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	while(1)
	{
		printf("\n1.update\n2.Insertion\n3.search\n4.remove\n5.display\n0.exit\n");
		int ch;
		printf("Choice : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			int x,k;
			printf("Enter elem and idx :");
			scanf("%d ",&x);
			scanf("%d",&k);
			update(ar,x,k,n);
			printf("updated : ");
			display(ar,n);
		}
		else if(ch==2)
		{
			int x,k;
			printf("Enter elem and idx :");
			scanf("%d",&x);
			scanf("%d",&k);
			insert(ar,x, k,n);
			printf("new array :");
			display(ar,n+1);
		}
		else if(ch==3)
		{
			int x;
			printf("Enter elem :");
			scanf("%d",&x);
			int p = search(ar,x,n);
			printf("idx :%d",p);
			
		}
		else if(ch==4)
		{
			int x;
			printf("Enter elem to del:");
			scanf("%d",&x);
			remove(ar,x,n);
			printf("new array :");
			display(ar,n-1);
		}
		else if(ch==5)
		{
			printf("array : ");
			display(ar,n);
		}
		else if(ch==0)
			break;
		else
			printf("\invalid ch");
	}
}
