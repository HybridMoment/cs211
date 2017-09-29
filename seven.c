#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Problem #7 get last chars of argv input and return them 
*/
int main (int argc, char * argv[]){
	//printf("%d\n", argc );

	if(argc == 1){
		printf("Error on input\n");
	}

	int i = 1; // args from pc start at 2 
	int length = strlen(argv[1]); // length of first string
	//printf("length : %d\n", length ); 
	char* charStorage = (char*)malloc(sizeof(char) *argc);
	char* str = (char*)malloc(sizeof(char)*length+1);
	
	
	int Last_Val_index = 0;
	
	while(i < argc)
	{	

		length = strlen(argv[i]);
		//printf("LENGTH INSIDE LOOP : %d  %d\n", length , i );
		if(i > 1)
		{
			//realloc
			str = realloc( str, sizeof(char)*length+1);
		}
		strcpy(str , argv[i]);
		//str[length+1] = '\0';
		charStorage[Last_Val_index] = str[length-1];

		i++;
		Last_Val_index++;
		

	}

	
	printf("%s\n", charStorage );


	return 0;

}
