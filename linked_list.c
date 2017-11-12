#include <stdio.h>


typedef struct node NODE;

struct node{
	int data;
	NODE *next;
};


NODE* insert_node(NODE* head, int data)
{
	NODE *new = NULL, *temp;
	/* create a new node and fill it*/
	new = (NODE *)malloc(sizeof(NODE));
	
	if(new != NULL){
		new->data = data;
		new->next = NULL;
	}
	
	if(head == NULL)
	{
		/* we get an empty list*/
		head = new;
	}
	else
	{
		temp = head;
		/* getting to the end of LL*/
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = new;		
	}
		
	return head;
}

void print_linked_list(NODE *head)
{
	NODE *temp;
	int count = 0;
	
	if(head == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		temp = head;
	
		while(temp != NULL){
			count++;
			printf("temp->data = %d\n", temp->data);
			temp = temp->next;
		}
	
		printf("Number of elements = %d\n", count);				
	}
}

/*
	Biggest learnigns
1)  NULL deferencing is possibility
    assigning values to NULL elements is also
    a possiblity.
   
    take extra care not to do that.

2)  in while loop: follow a pattern

    while(temp->next != NULL) seems safer

    than 

    temp = head->next;
    while(temp != NULL)
	
3)  always test the program for 
    empty list
	single element list
    two element list
    three element list
    multilple element list (more that three)

4)  
    
*/


#define TOTAL_NODES 15

void main()
{
	NODE list[TOTAL_NODES];
	NODE *head[5];
	int total_nodes = TOTAL_NODES;

	printf("Program Started\n");
		
	for(int i = 0; i < total_nodes; i++){
		list[i].data = i;
		list[i].next = &list[i+1];
	}

	list[total_nodes-1].next = NULL;

		
	/*empyt list*/
	head[0] = NULL;
	
	/*list with one element*/
	head[1] = &list[0];
	head[1]->next = NULL;
	
	/*list with two  elements*/
	head[2] = &list[1];
	list[2].next = NULL;

	/*list with three elements*/
	head[3] = &list[3];
	list[5].next = NULL;
	
	/*list with more than three elements*/
	head[4] = &list[6];

	/*print the list as it is*/
	for(int i = 0; i < 5; i++){
		printf("list= %d ------------------\n", i+1);
		print_linked_list(head[i]);
	}

	for(int i = 0; i < 5; i++){
		printf("iter= %d ------------------\n", i);
		
		head[i] = insert_node(head[i], total_nodes);
		print_linked_list(head[i]);
	}

 
	printf("Program Finsished\n");
}