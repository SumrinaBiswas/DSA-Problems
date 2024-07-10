// Write a program to find the factorial of a number using tail recursion.
#include<stdio.h>

int fact(int n,int result)
{
	if(n==1)
		return result;
	else
		return fact(n-1,n*result);
}
int main()
{
	int n,i;
	printf("enter no : ");
	scanf("%d",&n);
	printf("factorial : %d",fact(n,1)); // result =1; it will return value when n=1 , otherwise (n*1) is the value of each iteration and 
										//result is modified and n is decreasing when n=1, new result will display
}

