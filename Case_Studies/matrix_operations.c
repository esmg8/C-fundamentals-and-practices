#include <stdio.h>

#define ROWS 5
#define COLUMNS 4
int sum(int array[][COLUMNS]);

int main () {
	int matrix[ROWS][COLUMNS];
	int number;
		
	printf("Enter number:\n");
	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLUMNS;j++) {
			
			scanf("%d", &matrix[i][j]);
		}
	}
	
	
	printf("==== NUMBERS ====\n");
    for(int i=0;i<ROWS;i++) {
    	for(int j=0;j<COLUMNS;j++) {
    		printf("%d ", matrix[i][j]);
		}
    	printf("\n");
	}
	
	// SEARCH PART 
	int found=0;
			
	printf("Enter the number you want to search:\n");
	scanf("%d", &number);
	
	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLUMNS;j++) {
			if(number== matrix[i][j]) {
				printf("Your number %d is found at matrix[%d][%d].\n", number, i, j);
				found=1;
			}
		}
	  }
	  if(found==0) {
	  	printf("The number %d is not found!\n", number);
	  }
	
	// ---------------------
	
	// BIGGEST - SMALLEST PART
	int max=matrix[0][0];
	int min=matrix[0][0];
	
	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLUMNS;j++) {
			if(matrix[i][j]>max) max=matrix[i][j];
			if(matrix[i][j]<min) min=matrix[i][j];
		}
	}
	
	printf("The biggest number in the matrix is %d\n",max);
	printf("The smallest number in the matrix is %d\n", min);
	
	// ---------------------------
	
	// SUM
	int total=sum(matrix);	
	printf("The sum of elements is %d\n", total);
	
	return 0;
}

int sum(int array[][COLUMNS]) {
	int sum=0;
	for(int x=0;x<ROWS;x++) {
		for(int y=0;y<COLUMNS;y++) {
			sum+=array[x][y];
		}
	}
	return sum;
}