// Write a program to implement Tower of Hanoi Problem.

#include<stdio.h>
void TOH(int n,char s , char a,char d)
{
	if(n==1)
	{
		printf("\n%dth disc move from %c to %c",n,s,d);
	return;
	}
	TOH(n-1,s,d,a);
	printf("\n%dth disc move from %c to %c",n,s,d);
	TOH(n-1,a,s,d);
}
int main()
{
	int n;
	printf("enter no : ");
	scanf("%d",&n);
	TOH( n, 'S' ,'A','D');
	
}
