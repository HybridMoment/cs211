#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int* sortAscending(int*, int);

/*
		TODO: ERROR CHECK THIS AND FINISH SORTING 
*/
int main (int argc , char * argv[]){

	FILE* fp= fopen("test1.txt", "r");
	int size; 
	int data_read;
	char* str;
	int i = 0;
	fscanf( fp, "%d", &size);
	int array[size];
	printf(" SIZE : %d\n", size);

	char* buffer = (char*)malloc(sizeof(char));
	int exception = 1;

	while(fgets(buffer, sizeof(buffer), fp)!= NULL){

		while(i < size){
			fscanf( fp ,"%d", &data_read );
			array[i] = data_read;
			i++;
		}
		
		
	}

	//ERROR TESTING TO PRINT CONTENTS OF ARRAY
	int x = 0;
	while(x < size){
		printf("PRINTING ARRAY VAL : %d " "AT X : %d""\n", array[x], x );
		x++;
	}
	return 0;
}//end of main 
