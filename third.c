#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Problem 3 
*/

int num_bucket = 10000;

typedef
struct _Node{
	int key;
	int data; 
	struct _Node * next;

}Node;

Node* bucket[10000];
Node* create(int, int, Node*);
int hash(int);
int bool_search(int);

int main ( int arc, char * argv[]){

	FILE * fp = fopen("argv[1]", "r");

	if(fp == NULL){
		printf("error no file ");
	}

	char* buffer = (char*)malloc(sizeof(char));
	char* token;
	int data;
	Node* head = NULL;

	while(fgets( buffer, sizeof(buffer), fp)!= NULL){
		token = strtok(buffer, "\t");
		data = atoi(strtok(NULL,"\t")); //hopefully this works 
		int key = hash(data);

		if(*token == 'i'){
			//insert 
			//key = hash(data);
			head = bucket[key];
			//emtpy list need to insert
			if(head == NULL){
				bucket[key] = create(key,data,NULL);
				printf("inserted\n");
			}else if (bool_search(data)){
				printf("duplicate\n");
			}else{
				bucket[key] = create(key , data , head);
				printf("inserted\n");
			}
			
		}else if (*token == 's'){
			//search
			if(bool_search(data)){
				printf("present\n");
			}else{
				printf("abscent\n");
			}

		}else{
			printf("error with input");
		}

	}

	return 0;

}
int hash(int key){

	key = key % num_bucket;
	return key;

}
Node* create(int key , int data, Node* next){
	Node* new_Node = malloc(sizeof(Node));

	if(new_Node == NULL){
		printf("ERROR CREATING NODE");
	}
	new_Node->key = key;
	new_Node->data = data;
	new_Node->next = next;

	return new_Node;
}
int bool_search(int data){
	int key = data % num_bucket;
	Node* head = bucket[key];
	//Linked list at bucket[key] is empty 
	if( head == NULL){
		return 0;
	}
	//traverse list to search for key 
	while(head != NULL){
		if(head->data == data){
			//found...duplicate
			return 1;
		}else{
			head = head->next;
		}
	}
	//search not successful
	printf("abscent\n"); 
	return 0;

}
