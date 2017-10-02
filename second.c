#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sortAscending(int[], int);

/*
		problem 2
*/
int main (int argc , char * argv[]){

	FILE* fp= fopen("test1.txt", "r");
	int size; 
	int data_read;
	char* str;
	int i = 0;
	fscanf( fp, "%d", &size);
	int array[size];
	//printf(" SIZE : %d\n", size);

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
	/*
	printf("Pre sort\n");
	int x = 0;
	while(x < size){
		printf("PRINTING ARRAY VAL : %d " "AT X : %d""\n", array[x], x );
		x++;
	}
	*/
	//printf("Post sort\n");
	sortAscending(array, size);
	
	int x=0;
	while(x < size){
		printf("%d\t", array[x]);
		x++;
	}
	
	return 0;
}//end of main 
void sortAscending(int needs_sorting[] , int size_of_array ){
	int i , j , k,  tmp;
	for(j = 0; j < size_of_array; j++){
		for(k = j+1 ; k< size_of_array; k++){
			if(needs_sorting[j] > needs_sorting[k]){
				tmp = needs_sorting[j];
				needs_sorting[j] = needs_sorting[k];
				needs_sorting[k] = tmp;
			}
		}
	}
	
}
