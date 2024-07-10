#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node* next;
};
struct node* head=NULL;
void pushbeg(){
	struct node *Node=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be pushed :");
	scanf("%d",&Node->data);
	if(head == NULL){
		head = Node;
	 	head->next=NULL;
	}
	else{
		Node->next=head;
		head=Node;
	}
}
void pushend(){
	struct node* Node=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be pushed :");
	scanf("%d",&Node->data);
	if(head == NULL){
		head = Node;
	 	head->next=NULL;
	}
	else{
		struct node *p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=Node;
		Node->next=NULL;
	}
}
void popbeg(){
	struct node*temp=head;
	if(head==NULL)
	{
		printf("underflow");
	}
	head=temp->next;
	temp->next=NULL;
	free(temp);
}
void popend(){
	if (head==NULL)
		printf("\nUnderflow");
	else if (head->next==NULL)
	{
		popbeg();
	}
	else{
	
	struct node*temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	printf("deleted data %d",temp->next->data);
	temp->next=NULL;
	free(temp->next);
}
}
void pushpos(){
	if(head==NULL){
		pushbeg();
	}
	int pos;
	struct node *Node=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be pushed :");
	scanf("%d",&Node->data);
	printf("postion :");
	scanf("%d",&pos);
	struct node* p=head;
	for(int i=1;i<pos-1;i++){
		p=p->next;
	}
	Node->next=p->next;
	p->next=Node;
}

void disp(){
	printf("Linked list \n");
	struct node *p=head;
	while(p!=NULL){
		
		printf("%d\t",p->data);
		p=p->next;
	}
}
void poppos(int pos){
		if (head==NULL)
			printf("\nUnderflow");
	
		struct node* temp=head;
		
		for(int i=0;i<pos-1;i++){
			temp=temp->next;
			}
		struct node* del=temp->next;
		temp->next=temp->next->next;
		printf("deleted item",del->data);
		free(del);
	
}
void popdata(){
	int i=0,f=0;
	struct node* p=head;
	if (head==NULL)
			printf("\nUnderflow");
		int data;
		printf("enter the item :");
		scanf("%d",&data);
	while(p!=NULL){
	if (p->data==data)
			{
				f=i;
				break;
			}
			else
			{
				p=p->next;
				i++;
			}
		}
		if (f==-1)
			printf("\nData not found");
		else
			poppos(f);	
}
	
int main()
{
	printf("1. pushbeg\n2. pushend\n3. popbeg\n4. popend\n5. pushpos\n6. poppos\n7. popdata\n9. disp\n0. exit");
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
		else if (ch==6){
				int pos;
		printf("enter the position :");
		scanf("%d",&pos);
		if(pos==0){
			popbeg();
		
		}
		poppos(pos);
		}
			
		
		else if (ch==7)
			popdata();
		else if (ch==9)
			disp();
		else if (ch==0)
			break;
		else
			printf("\nInvalid choice");
	}

getch();
}

