#include<stdio.h>
#include<conio.h>
#define size 6

int binary_search(int a[],int n)
{
	int low=0, high=n-1;
	int mid,f=0;
	int x;
	printf("\n Enter data to be searched : ");
	scanf("%d",&x);
	while(1)
	{
	
		mid = (low+high)/2;
		if(x==a[mid])
		{
			f=1;
			break;
		}
		else if(x<a[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(f=0)
		printf("\nnot found");
	else
		return(mid);
}
int main()
{
	int n,p;
	printf("Enter array size : ");
	scanf("%d",&n);	
	int ar[n];
	printf("\nenter elem :  ");
	for(int i=0;i<n;i++)
	{
		scanf("%d\t",&ar[i]);
	}
	
	
	binary_search(ar,n);
}


	
