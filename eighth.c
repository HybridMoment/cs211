#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
struct _Node
{
	int key;
	int level;
	struct _Node* left;
	struct _Node* right;
}Node;

Node* insert(struct _Node* , struct _Node*);
int bool_search( struct _Node* , int , int);
Node* create(int);
void inorder(Node*);
int getLevel(Node*, Node*);

int main ( int arc, char * argv[]){
	
	FILE* fp = fopen(argv[1] , "r");

	if(fp == NULL){
		printf("Error opening file ");
	}
	char* buffer = (char*)malloc(sizeof(char));
	char* token;
	int data;
	Node* nodeToInsert = NULL;
	Node* root = NULL;
	int truthVal = 0;

	while(fgets( buffer, sizeof(buffer), fp)!= NULL){
		token = strtok(buffer, "\t");
		data = atoi(strtok(NULL,"\t")); 
		
		Node* newNode;
		newNode = create(data);

		if(*token == 'i'){
			//insert
			root = insert(root,newNode);
			//printf("New Node data : %d\n",newNode->key );
		}else if(*token == 's'){
			truthVal = bool_search(root,data,1);
			//printf("truthVal %d\n",truthVal );
			if(truthVal){
				printf("present %d\n",truthVal);
			}else{
				printf("abscent\n");
			}
		}else{
			//error
			printf("error with input");
		}
	}
	//inorder(root);

}
Node* insert( Node* root , Node* newNode){

	if(root == NULL){
		root = newNode;
	}else{
		Node* prev = NULL;
		Node* curr = root;
		while(curr != NULL){
			prev = curr;
			if(curr->key < newNode->key){
				
				curr = curr->right;
			}else{
			
				curr = curr->left;
			}
		}
		if(prev->key < newNode->key){
			prev->right = newNode;
		}else{
			prev->left = newNode;
		}
		
	}
	return root;
	
}
int bool_search(Node* root , int data, int level){
	if(root == NULL){
		return 0;
	}
	if(root->key == data){
		return level;
	}
	int result = bool_search(root->left,data,level+1);
	if(result != 0){
		return result;
	}
	result = bool_search(root->right,data,level+1);
	return result;
	/*
	if(root->key < data){
		 return bool_search(root->left, data , level+1);
	}else{
		return bool_search(root->right, data );
	}
	*/
}
Node* create(int data){
	Node* n = malloc(sizeof(Node));
	n->key = data;
	n->level = 1;
	n->left = n->right = NULL;
	return n;
}

void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("Data : %d\n", root->key );
		inorder(root->right);
	}
}




