#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Struct Declaration*/
typedef
struct _Node{

	int data;
	struct _Node * next;
	

}Node;

/*Function declarations*/
Node* create(int , Node*);
Node* insert(Node* , int);
Node* delete(Node* , int);


int main (int argc, char * argv[])
{
	// READ FILE  TODO: UPDATE TEST.TXT NAME TO CORRECT NAME 
	FILE* fp = fopen("firstTest1.txt" , "r");

	//Case 1 : FILE EMPTY
	if(fp == NULL)
	{ 
		
		printf("error\n"); // Print 0 ... No file read case
		
	}
	//Case 2 : File NOT empty
	char* buffer = (char*)malloc(sizeof(char)); // this might need to be bigger, depending on # used 
	char* token; 
	char* data;
	int actual_Data;
	Node* head = NULL;
	Node* new_Node = NULL;

	while( fgets( buffer, sizeof(buffer), fp) != NULL)
	{	
		//Read in information line by line 
		//granted, check if 60 is large enough 
		token = strtok(buffer, "\t");
		printf("TOKEN : %s\n", token);
		data = strtok(NULL, " ");
		actual_Data = atoi(data); // convert data to int
		printf("DATA : %d\n", actual_Data );
		
		if(*token == 'i')
		{
			//need to insert / create node 

			if(head == NULL)
			{
				//Linked list empty
				head = create( actual_Data , NULL); // first item in Linked List
			
			}else
			{
				// LL not empty, need to insert data in order
				//new_Node = create (actual_Data , NULL);
				head = insert(head, actual_Data);
				
			}
			
			
		}else if (*token == 'd')
		{
			//delete
			 head = delete(head , actual_Data);

		}else
		{
			//ERROR BAD TXT FILE INPUT !!!!!
			printf("ERROR WITH INPUT " );
		}
	}
	//Printing out information of Linked List 
	//this is garbage error check this 
	Node* fun_ptr = head;
	int fun_data;
	while(fun_ptr != NULL){
		fun_data = (int)(fun_ptr->data);
		printf("%d\n", fun_data);
		fun_ptr = fun_ptr->next;
	}	


	fclose(fp);// close file 
	
	return 0;
}// main end


/*
	Function for node creation
*/
Node* create(int data , Node* next){
	
	Node* new_Node = malloc(sizeof(Node)); //is int right?
	
	if(new_Node == NULL){
		printf("ERROR CREATING NEW NODE...CHECK FUNCTION!!!");
	} 

	new_Node->data = data;
	new_Node->next = next;

	return new_Node;
}



/*
	Function for inserting node in LL
*/
Node* insert(Node* head, int storeData){

	Node* ptr = head->next;  
	Node* prev = NULL;
	//Head is null ... No LL yet
	if(head == NULL){
		head = create(storeData, NULL);
		return head; 
	}

	//if head == data you do not need to store 
	if(head->data == storeData){
		return head;
	}

	//insert at head 
	if(head->data > storeData){
		head = create(storeData, head);
		return head;
	}
	//insert into LL of size 1 lol
	if(head->data < storeData && ptr == NULL){
		head->next = create(storeData, NULL);
		return head;
	}
	//iterate to find insert location 
	prev = head; 
	while(ptr != NULL){

		if(ptr->data > storeData ){
			//between two nodes
			prev->next = create(storeData, ptr);
			return head;

		}else if( ptr->data <  storeData && ptr->next == NULL){
			//insert at tail 
			ptr->next = create( storeData , NULL); 
			return head; 
		}else{
			//update nodes 
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return head;
	
}

Node* delete(Node* head, int data_to_delete)
{
	Node* prev = head;
	Node* nxt = head->next;

	if(head == NULL)
	{
		// error case deleting from empty LL
		printf("ERROR CANNOT delete FROM EMPTY LL");
		
	}
	//Case 1 deleting from head 
	if(head->data == data_to_delete)
	{
		head = nxt;
		//free(nxt);
		//free(prev);
		return head;
	}

	while(nxt != NULL){

		if(nxt->data == data_to_delete)
		{
			//delete next 
			nxt = nxt->next;
			prev->next = nxt;
			//free(nxt); 
		}else
		{
			//else update pointers to loop on
			prev = nxt;
			nxt = nxt->next;
		}
		
	}

	return head;
}



