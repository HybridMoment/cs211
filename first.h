#ifndef FIRST_H
#define FIRST_H

/*
	Struct for creating nodes
*/
typedef
struct _Node{

	int data;
	struct _NODE * next;
	

}Node;

/*
	Function for node creation
*/
_Node* create(int data , _Node* next){
	
	_Node* new_Node = (_Node*)malloc(sizeOf(_Node)); //Do i need to use _NODE?
	
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
_Node* insert(_Node* head, _Node* node_to_insert){
	//STEP 1: Check if list already contains node with that value
	// if so... do not insert...
	//THIS FUNCTION RETURNS HEAD OF NEW LIST 
	_Node* ptr = head; // TODO: Do you need to use _NODE since pre-compiler 
	
	if( head->data > node_to_insert->data){
		// node needs to be inserted in front
		node_to_insert->next = head;
		return node_to_insert; // returns this to update head

	}else{

		while( ptr != NULL){
		//scan list if node is contained in list
		if(ptr.data == node_to_insert.data){

			return head; 
			//  base case for checking if node is in list
			// if it is we just return head and DO NOT insert;

		}

			ptr = ptr->next;
		}
	}
	
	//need to insert if getting to this point 
	ptr = head; // reset ptr to head 
	while(ptr != NULL){
		// since we already have  inserting at head handled outside in main we only have two cases
		_Node* next = ptr->next;
		if(ptr->data < node_to_insert->data && node_to_insert->data < next->data){
			//we need to insert in between two nodes
			node_to_insert->next = next;
			ptr->next = node_to_insert;
			return head; // successful insert
		}
		else if( next == NULL){ // checking for insertion at end
			ptr->next = node_to_insert;
			return head;
		}
		else{
			ptr = ptr->next;
		}


	}
}
_Node* delete(_Node* head, _Node* node_to_delete){
	
	_Node* cur = head;
	_Node* nxt = cur->next;

	while(cur != NULL){

		if(cur->data == node_to_delete->data){
			//delete head
			head->next = nxt;
			cur->next = NULL;
			return head;
		}else if(nxt->data == node_to_delete->data){
			//delete next 
			cur->next = nxt->next;
			nxt->next = NULL;
			return head;
		}else{
			cur = nxt;
			nxt = nxt->next;
		}
		//TODO: validate this works 
}





}

#endif