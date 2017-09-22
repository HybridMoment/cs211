#ifndef FIRST_H
#define FIRST_H

/*
	Struct for creating nodes
*/
typedef
struct _NODE{

	int data;
	struct _NODE * next;
	

}Node;

/*
	Function for node creation
*/
node* create(int data , node* next){
	
	Node* new_Node = (Node*)malloc(sizeOf(Node)); //Do i need to use _NODE?
	
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
node* insert(node* head, node* node_to_insert){
	//STEP 1: Check if list already contains node with that value
	// if so... do not insert...

}

#endif