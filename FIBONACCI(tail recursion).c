// Write a program to find the nth Fibonacci number using tail recursion.

#include<stdio.h>
#include<conio.h>

int fib_tail(int n,int a,int b)
{
	if(n==0)
		return a;
	else
		return fib_tail(n-1,b,a+b);
	
}

int main()
{
	int n,i;
	printf("enter no : ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		printf("%d\t",fib_tail(i,0,1));
	}
}
