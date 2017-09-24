#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "first.h"

int main (int argc, char * argv[]){
// READ FILE  TODO: UPDATE TEST.TXT NAME TO CORRECT NAME 
	FILE* fp = fopen("TEST.txt" , "r");

	//Case 1 : FILE EMPTY
	if(fp == NULL){ 
		
		printf("0\n", ); // Print 0 ... No file read case
		
	}
	//Case 2 : File NOT empty
	char str[60]; // this might need to be bigger, depending on # used 
	char* token; 
	char* data;
	int actual_Data;
	Node* head;
	Node* new_Node;
	while( fgets( str, 60, fp)){	//Read in information line by line 
		//granted, check if 60 is large enough 
		token = strtok(str, " ");
		data = strtok(NULL, " ");
		if(*token == 'i'){
			//need to insert / create node
			actual_data = atoi(data); // convert data to int

			if(head == NULL){
				//Linked list empty
				head = create( actual_data , NULL); // first item in Linked List
			
			}else{
				
				// LL not empty, need to insert data in order
				new_Node = create (actual_data , NULL);
				head = insert(head, new_Node);
				
			}
			
			
		}else if (*token == 'd'){
			//delete

		}else{
			//ERROR BAD TXT FILE INPUT !!!!!
		}
	}

	fclose(fp);// close file 
	
	return 0;
}