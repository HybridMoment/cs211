#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


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

int main ( int arc, char * argv[]){

	FILE* fp = fopen(argv[1] , "r");

	if(fp == NULL){
		printf("error\n");
	}

	Node* root = NULL;
	int truthVal = 0;
	char insert_or_delete; 
	int data = 0;

	while(!feof(fp)){
		fscanf(fp, "%c %d\n",&insert_or_delete, &data);
		//printf(" Line #%d\n",i );
		//printf("tok:%cVal:%d\n",inOrdel,value);
		Node* newNode = create(data);

		if(insert_or_delete == 'i'){

			truthVal = bool_search(root,data,1);
			if(truthVal){
				printf("duplicate\n");
			}else{
				//insert
				root = insert(root,newNode);
				printf("inserted %d\n",newNode->level);
			}

		}else if(insert_or_delete == 's'){
			truthVal = bool_search(root,data,1);
			if(truthVal){
				printf("present %d\n",truthVal);
			}else{
				printf("absent\n");
			}
		}else{
			printf("error on input\n");
		}
	}
}
Node* insert( Node* root , Node* newNode){
	int level = 1;
	if(root == NULL){
		root = newNode;
		root->level = 1;
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
			level++;
		}
		if(prev->key < newNode->key){
			newNode->level = level;
			prev->right = newNode; // if off by one add +1 to level here 
		}else{
			newNode->level = level;
			prev->left = newNode;
		}
		
	}
	
	//printf("Success insert");
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
