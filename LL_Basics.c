#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node *start=NULL;
struct node *create(struct node*);
struct node *insert_end(struct node*);
struct node *insert_beg(struct node*);
struct node *display(struct node*);
struct node *count_node(struct node*);
struct node *last_seclast(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *insertion_given(struct node*);
struct node *delete_given(struct node*);
struct node *print_reverse(struct node*);
struct node *reverse_list(struct node*);
void element_present(struct node*);
void middle_node(struct node*);
void empty();
void delete();
int main(){
	int choice;
	printf("*************************************");
	printf("\n\3 0->Create A Linked list.");
	printf("\n\3 1->Display the Linked list.");
	printf("\n\3 2->Enter at the end of the linked list.");
	printf("\n\3 3->Count the number of nodes is the Linked list");
	printf("\n\3 4->Display the SECOND_LAST and LAST node of the linked list.");
	printf("\n\3 5->Enter at the begining of the linked list.");
	printf("\n\3 6->Deletion at the begining of the linked list.");
	printf("\n\3 7->Deletion at the end of the linked list.");
	printf("\n\3 8->Inserstion at any given position in the linked list.");
	printf("\n\3 9->Deletion at any given position in the linked list.");
	printf("\n\3 10->Search if a element is present or not.");
	printf("\n\3 11->print the middle node.");
	printf("\n\3 12->print the Linked List in reverse order.");
	printf("\n\3 13->Reverse the Linked List.");
	printf("\n\3 Enter your choice:");
	scanf("%d",&choice);
	do{
		switch(choice){
			case 0:	{
				start=create(start);
				break;
			}
			case 1:{
				display(start);
				break;
			}
			case 2:{
				start=insert_end(start);
				break;
			}
			case 3:{
				start=count_node(start);
				break;
			}
			case 4:{
				start=last_seclast(start);
				break;
			}
			case 5:{
				start=insert_beg(start);
				break;
			}
			case 6:{
				start=delete_beg(start);
				break;
			}
			case 7:{
				start=delete_end(start);
				break;
			}
			case 8:{
				start=insertion_given(start);
				break;
			}
			case 9:{
				start=delete_given(start);
				break;
			}
			case 10:{
				element_present(start);
				break;
			}
			case 11:{
				middle_node(start);
				break;
			}
			case 12:{
				start=print_reverse(start);
				break;
			}
			case 13:{
				start=reverse_list(start);
				break;
			}
			default:{
				printf("\n\4\4\4\4INVALID OPTION\4\4\4\4");
				break;
			}
		}
		printf("\n*************************************"); //10 20 30 40 50
		printf("\n\3 0->Create A Linked list with 1 Node");
		printf("\n\3 1->Display the Linked list.");
		printf("\n\3 2->Enter at the end of the linked list.");
		printf("\n\3 3->Count the number of nodes is the Linked list");
		printf("\n\3 4->Display the SECOND_LAST and LAST node of the linked list.");
		printf("\n\3 5->Enter at the begining of the linked list.");
		printf("\n\3 6->Deletion at the begining of the linked list.");
		printf("\n\3 7->Deletion at the end of the linked list.");
		printf("\n\3 8->Inserstion at any given position in the linked list.");
		printf("\n\3 9->Deletion at any given position in the linked list.");
		printf("\n\3 10->Search if a element is present or not.");
		printf("\n\3 11->print the middle node.");
		printf("\n\3 12->print the Linked List in reverse order.");
		printf("\n\3 13->Reverse the Linked List.");
		printf("\n\3 Enter your choice:");
		scanf("%d",&choice);
	}while(choice!=-1);
	return 0;
}
struct node *create(struct node* start){
	struct node* temp,*ptr=start;int d;
	temp=malloc(sizeof(struct node));
	if(start==NULL){
		empty();
		printf("\nEnter the Data:");
		scanf("%d",&d);
		temp->data=d;
		temp->link=NULL;
		start=temp;
		printf("\nlinked list has been created.");
		do{
			printf("\nEnter -1 to stop inserting.");
			scanf("%d",&d);
			if(d!=-1)
				start=insert_end(start);
		}while(d!=-1);	
	}
	else{
		start=insert_end(start);
	}
	return start;
}
struct node *insert_end(struct node* start){
	int data;
	struct node *ptr=start,*temp=malloc(sizeof(struct node));
	if(start==NULL)
		start=create(start);
	printf("\nEnter the data:");
	scanf("%d",&data);
	temp->data=data;
	temp->link=NULL;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=temp;
	return start;
}
void empty(){
	printf("\nThe Linked List is currently EMPTY.");
}
struct node *display(struct node* start){
		printf("\n\n.................DISPLAYING.................");
		struct node *temp;
		temp=start;
		printf("\n");
		while(temp!=NULL){
			printf("%d	", temp->data);
			temp=temp->link;
		}
		return start;
}
struct node *count_node(struct node* start){
	int count=0;
	struct node* temp=start;
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}
	if(count==0)
		empty();
	else{
		printf("\nRESULT\nThere are %d nodes in the Linked List.",count);
	}
	return start;
}
struct node *last_seclast(struct node* start){
	struct node* temp=start;
	if(start==NULL)
		empty();
	while(temp->link->link!=NULL){
		temp=temp->link;
	}
	printf("\nThe second last element is %d",temp->data);
	printf("\nThe last element is %d",temp->link->data);
	return start;
}
struct node *insert_beg(struct node* start){
	struct node* temp,*ptr=start; int d;
	temp=malloc(sizeof(struct node));
	if(ptr==NULL){
		empty();
		start=create(start);
	}
	printf("\nEnter the data:");
	scanf("%d",&d);
	temp->data=d;
	temp->link=ptr;
	start=temp;
	return start;
}
struct node *delete_beg(struct node* start){
	struct node* temp=start;
	start=temp->link;
	free(temp);
	delete();
	return start;
}
void delete(){
	printf("\nNode has been deleted.");
}
struct node* delete_end(struct node* start){
	struct node* temp=start,*temp2;
	while(temp->link->link!=NULL){
		temp=temp->link;
	}
	temp2=temp->link;
	temp->link=NULL;
	free(temp2);
	delete();
	return start;
}
struct node *insertion_given(struct node* start){
	int data,pos,count=0,i;
	struct node* temp2, *ptr=start,*temp=malloc(sizeof(struct node));
	printf("\nEnter the position:");
	scanf("%d",&pos);
	while(ptr!=NULL){
		count++;
		ptr=ptr->link;
	}
	if(pos>count){
		printf("\nLinked List has less nodes than the given value.");
	}
	printf("\nEnter the data:");
	scanf("%d",&data);
	temp->data=data;
	ptr=start;
	for(i=1;i<pos-1;i++)
		ptr=ptr->link;
	temp2=ptr->link;
	ptr->link=temp;
	temp->link=temp2;
	return start;
}
struct node* delete_given(struct node* start){
	int i,pos;
	struct node* temp=start,*temp2=NULL;
	printf("\nEnter the position:");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++)
		temp=temp->link;
	temp2=temp->link->link;
	free(temp->link);
	temp->link=temp2;
	delete();
	return start;
}
void element_present(struct node* start){
	int data,flag=0;
	struct node* temp= start;
	printf("\nEnter the data you want to search:");
	scanf("%d",&data);
	while(temp!=NULL){
		if(temp->data==data){
			flag=1;
			break;
		}
		temp=temp->link;
	}
	flag==0?printf("%d is not present in the linked list.",data):printf("%d is present in the linked list.");
}
void middle_node(struct node* start){
	struct node* temp=start;
	int i,count=0;
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}
	temp=start;
	if(count%2!=0){
		for(i=0;i<(count/2);i++)
			temp=temp->link;
		printf("\nMiddle node is:%d",temp->data);
	}
	else{
		for(i=1;i<count/2;i++)
			temp=temp->link;
		printf("\nThe middle nodes are:%d, %d",temp->data,temp->link->data);
	}
}
struct node* print_reverse(struct node* start){
	struct node* temp = start;
	if(temp->link!=NULL)
		print_reverse(temp->link);
	printf("%d	",temp->data);
	return start;
}
struct node* reverse_list(struct node* start){
	struct node* temp1=start,*temp2,*temp3,*ptr;
	if(temp1==NULL){
		printf("\nLinked List is empty.");
		exit(13);
	}
	temp2=temp1->link;
	temp3=temp2->link;
	temp1->link=NULL;
	do{
		temp2->link=temp1;
		temp1=temp2;temp2=temp3;temp3=temp3->link;
	}while(temp3!=NULL);
	temp2->link=temp1;
	start=temp2;
	printf("\nList has been reversed.");
	return start;
}
