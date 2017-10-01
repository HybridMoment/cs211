#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int calc_magic_property(int);
int scanCols(int*[] , int , int);
int scanRows(int*[] , int , int);
int scanDiagonal(int*[] , int , int);

int main ( int arc, char * argv[]){
	FILE * fp = fopen(argv[1] , "r");

	if(fp == NULL){
		printf("error no file\n" );
	}

	int n;
	fscanf(fp,"%d",&n);
	
	int magicProperty = calc_magic_property(n);
	int* matrix[n];
	int i , j ;
	//allocate memory 
	for(i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * n);
	}
	//populate matrix
	for(i = 0; i < n; i++ ){
		for(j = 0; j< n; j++){
			fscanf(fp, "%d" , &matrix[i][j]);
		}
	}
	/*/printing array for error checking
	for (i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d\n", matrix[i][j]);
		}
	}*/
	if(scanCols(matrix,magicProperty,n) && scanRows(matrix,magicProperty,n) && scanDiagonal(matrix,magicProperty,n)){
		printf("magic\n");
	}else{
		printf("not-magic\n");
	}
	
	return 0;



}
int calc_magic_property(int size){
	int n = size * (pow(size , 2) + 1)/2;
	return n;

}
int scanCols(int* matrix[] , int magicProperty , int n){
	
	int i , j;
	int sum = 0;
	for(j = 0; j < n; j++){
		sum = 0; //update sum for loop usage 
		for(i = 0; i< n; i++){
			sum += matrix[i][j];

		}
		//printf("sum : %d",sum );
		if(sum == magicProperty){
			continue;
		}else{
			return 0; // false
		}
		
	}
	
	return 1; //true

}
int scanRows(int* matrix[] , int magicProperty , int n){
	int i , j;
	int sum = 0;
	for(i = 0; i < n; i++){
		sum = 0;
		for (j = 0; j < n; ++j)
		{
			sum += matrix[i][j];
		}
		if(sum == magicProperty){
			continue;
		}else{
			return 0;
		}
	}
	return 1; //true 
}
int scanDiagonal(int* matrix[] , int magicProperty , int n){
	int j;
	int i = n-1;
	int sum = 0;
	int truthVal1 = 0;
	int truthVal2 = 0;
	//bottom left to top right scan 
	for (j = 0; j < n; ++j)
	{
		sum += matrix[i][j];
		i--;
	}
	if(sum == magicProperty){
		truthVal1 = 1;
	}else{
		truthVal1 = 0;
	}
	//printf("SUM DIAG 1 :%d\n",sum);
	//top left to bottom right scan 
	j = 0;
	sum = 0;
	for( i = 0; i < n; i++){
		sum +=  matrix[i][j];
		j++;
	}
	//printf("SUM DIAG 2 %d\n",sum );
	if(sum == magicProperty){
		truthVal2 = 1;
	}else{
		truthVal2 = 0;
	}
	if(truthVal1 && truthVal2){
		return 1;
	}else{
		return 0;
	}


}