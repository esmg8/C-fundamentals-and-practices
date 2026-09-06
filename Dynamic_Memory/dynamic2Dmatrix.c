#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int row, int column);
void fillMatrix(int **matrix, int row, int column);
void printMatrix(int **matrix, int row, int column);
void freeMatrix(int **matrix, int row);

int main() {
	int **matrix;
	int row, column;
	
	printf("Enter number of rows and columns:\n");
	scanf("%d%d",&row, &column);
	
	matrix=createMatrix(row, column);
	if(matrix==NULL) return 1;
	
	fillMatrix(matrix, row, column);
	printMatrix(matrix, row, column);
	freeMatrix(matrix, row);
	

	
	return 0;
}



int **createMatrix(int row, int column) {
	int **matrix;
	
	
	matrix=malloc(sizeof(int*)*row); 
	
	if(matrix==NULL) {
		printf("Matrix is NULL!\n");
		return NULL;
	}
	
	for(int i=0;i<row;i++) {
		matrix[i]=malloc(sizeof(int)* column);
		
		if(matrix[i]==NULL) {
			printf("matrix[%d] is NULL!\n", i);
			for(int j=0;j<i;j++) {
				free(matrix[j]);
			}
			free(matrix);
			return NULL;
		}
	}
	
	return matrix;
}


void fillMatrix(int **matrix, int row, int column) {
		for(int i=0; i<row;i++) {
		for(int j=0;j<column;j++){
			printf("Enter the value of matrix[%d][%d]:\n", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}

}


void printMatrix(int **matrix, int row, int column) {
	for(int i=0; i<row;i++) {
		for(int j=0;j<column;j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


void freeMatrix(int **matrix, int row) {
	for(int i=0;i<row;i++) {
		free(matrix[i]);
	}
	free(matrix);
}

