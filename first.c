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
	while( fgets( str, 60, fp)){	//Read in information line by line 
		//granted, check if 60 is large enough 
		token = strtok(str, " ");
		data = strtok(NULL, " ");
		if(*token == 'i'){
			//need to insert / create node
			
		}else if (str[0] == 'd'){
			//delete

		}else{
			//ERROR BAD TXT FILE INPUT !!!!!
		}
	}

	fclose(fp);// close file 
	
	return 0;
}