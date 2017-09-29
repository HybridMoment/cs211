#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

	Problem 6 

*/



int main (int argc, char * argv[])
{
	
	if(argc > 2){
		printf("error\n");
		return 1;
	}
	
	char* str = argv[1];
	int length = strlen(argv[1]);
	char* strToReturn = (char*)malloc(sizeof(char)*length+1);
	int* occurence = (int*)malloc(sizeof(int)*length);
	if(length == 1){
		strToReturn[0] = str[0];
		strToReturn[1] = '1';
		printf("%s",strToReturn);
		return 0;
	}

	int count = 1;
	int next = 1;
	int i = 0;
	int prev = 0;
	while(next +1 < length){

		strToReturn[i] = str[prev];
		while(str[prev] == str[next]){
			count++;
			next++;
		}
		occurence[i] = count; 
		i++;
		count = 1;
		prev = next;
		next = next +1;

	}
	//print string 
	int x = 0;
	while(x < i){
		
		printf("%c%d",strToReturn[x],occurence[x]);
		x++;

	}
	
	printf("\n");

	return 0;



}

