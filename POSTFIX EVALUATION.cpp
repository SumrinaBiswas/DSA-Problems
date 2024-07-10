#include <stdio.h>
#include <conio.h>
#include <string.h>

#define size 20

int top = -1;
int stack[size];		//entering char as int
char postfix[size];	// user input = char

void push(char c)
{
    if (top == size - 1)
        printf("\noverflow");
    else
    {
        stack[++top] = c;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\nunderflow");
        return -1;
    }
    else
    {
        int c = stack[top];
        top--;
        return c;
    }
}

int isempty()
{
    return top == -1;
}
int eval()
{
	int i,j=0;
	int a,b;

	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
		{
			push(postfix[i]-'0');
		}
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+':
					push(b+a);
					break;
				case '-':
					push(b-a);
					break;
				case '*':
					push(b*a);
					break;
				case '/':
					push(b/a);
					break;
				case '^':
					push(b^a);
					break;
			}
		}
	}
	return pop();
}
int main()
{
	int d;
	printf("Postfix : ");
	gets(postfix);
	d= eval();
	printf("\nresult : %d",d);
}

