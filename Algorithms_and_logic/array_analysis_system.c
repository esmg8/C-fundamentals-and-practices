#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

void displayArray(int array[], int size);
int findMaximum(int array[], int size);
int findMinimum(int array[], int size);
int findMaximumIndex(int array[], int size);
int findMinimumIndex(int array[], int size);
int calculateSum(int array[], int size);
double calculateAverage(int array[], int size);
void reverseArray(int array[], int size);
int searchElement(int array[], int size, int target);
void insertElement(int array[], int *size, int position, int value);
double calculateStandardDeviation(int array[], int size);
void displayMatrix(int matrix[][3], int rows, int columns);

int main() {
	int array[MAX_SIZE];
	int size=0;
	int choice, number, position, result;
	
	do{
		printf("\n===============================\n");
		printf("       ARRAY ANALYSIS SYSTEM\n");
		printf("=================================\n");
		printf("1. Enter Array\n");
		printf("2. Display Array\n");
		printf("3. Find Maximum and Minimum\n");
		printf("4. Calculate Sum and Average\n");
		printf("5. Reverse Array\n");
		printf("6. Insert Element\n");
		printf("7. Search Element\n");
		printf("8. Calculate Standard Deviation\n");
		printf("9. Display Example Matrix\n");
		printf("0. Exit\n");
		printf("=================================\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: 
			       printf("\nHow many numbers do you want to enter? ");
			       scanf("%d", &size);
			       
			       if(size<=0|| size>MAX_SIZE) {
			       	printf("Invalid array size!\n");
			       	size=0;
			       	break;
				   }
				   
				   for(int i=0;i<size;i++) {
				   	printf("Enter number: %d ", i+1);
				   	scanf("%d", &array[i]);
				   }
				   printf("Array successfully created.\n");
				   break;
			
			case 2: 
			       if(size==0) {
			       	printf("Array is empty. Please enter numbers first.\n");
				   } else {
				   	displayArray(array, size);
				   }
				   break;
				   
			case 3: 
			       if(size==0) {
			       	printf("Array is empty.\n");
				   } else {
				   	printf("\nMaximum value: %d", findMaximum(array, size));
				   	printf("\nMaximum index: %d", findMaximumIndex(array, size));
				   	
				   	printf("\nMinimum value: %d", findMinimum(array, size));
				   	printf("\nMinimum index: %d", findMinimumIndex(array, size));
				   }
				   break;
				   
			case 4: 
			       if(size==0) {
			       	printf("Array is empty.\n");
				   } else {
				   	printf("\nSum: %d", calculateSum(array, size));
				   	printf("\nAverage: %.2f\n", calculateAverage(array, size));
				   }
				   break;
				   
			case 5: 
			       if(size==0) {
			       	printf("Array is empty.\n");
				   } else{
				   	reverseArray(array, size);
				   	printf("Array reversed successfully.\n");
				   	displayArray(array, size);
				   }
				   break;
				   
			case 6: 
			       if(size >=MAX_SIZE) printf("Array is full!\n");
			       else {
			       	printf("Enter the number you want to insert: ");
			       	scanf("%d", &number);
			       	
			       	printf("Enter the position (0-%d): ", size);
			       	scanf("%d", &position);
			       	
			       	if(position<0|| position>size) printf("Invalid position!\n");
			       	else {
			       		insertElement(array, &size, position, number);
			       		printf("Element inserted successfully.\n");
			       		displayArray(array, size);
					   }
				   }
				   break;
				   
			case 7: 
			       if(size==0) {
			       	printf("Array is empty.\n");
				   }
				   else {
				   	printf("Enter the number you want to search: ");
				   	scanf("%d", &number);
				   	
				   	result= searchElement(array, size, number);
				   	
				   	if(result== -1) printf("Element not found.\n");
				   	else printf("Element found at index &d.\n", result);	   	
				   }
				  break; 
				   
			case 8: 
			        if(size==0) {
			       	printf("Array is empty.\n");
				   }
				   else {
				   	printf("Standard deviation: %.2f\n");
				   	calculateStandardDeviation(array, size);
				   }
				   break;
				   
			case 9: {
				int matrix[2][3]= { 
				{1, 4, 2},
				{3, 6, 8}
				};
				printf("\nExample Matrix: \n");
				displayMatrix(matrix, 2, 3);
				break;
			}
				   
			case 0: 
			       printf("Program terminated. Goodbye!\n");
			       break;
			       
			default: 
			        printf("Invalid choice! Please try again.\n");	   
		}
			
	}while(choice!=0);
	return 0;
}


// Displays all elements of the array
void displayArray(int array[], int size) {
	printf("\nArray: ");
	for(int i=0;i<size;i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

// Finds the maximum value
int findMaximum(int array[], int size) {
	int maximum=array[0];
	
	for(int i=1;i<size;i++) {
		if(array[i]>maximum) {
			maximum=array[i];
		}
	}
	return maximum;
}

// Finds the minimum value
int findMinimum(int array[], int size) {
	int minimum= array[0];
	for(int i=1;i<size;i++) {
		if(array[i]<minimum) minimum=array[i];
	}
	return minimum;
}

// Finds the index of the maximum value
int findMaximumIndex(int array[], int size) {
	int index=0;
	
	for(int i=1;i<size;i++) {
		if(array[i]>array[index]) index=i;
	}
	return index;
}

// Finds the index of the minimum value
int findMinimumIndex(int array[], int size) {
	int index=0;
	
	for(int i =1;i<size;i++) {
		if(array[i]<array[index]) index=i;
	}
	return index;
}

// Calculates the sum of the all elements 
int calculateSum(int array[], int size) {
	int sum =0;
	for(int i=0;i<size;i++) {
		sum+=array[i];
	}
	return sum;
}

// Calculates the average
double calculateAverage(int array[], int size) {
	return (double)calculateSum(array, size) /size;
}

// Reverses the array
void reverseArray(int array[], int size) {
	int temp;
	for(int i=0;i<size/2;i++) {
		temp=array[i];
		array[i]=array[size-1-i];
		array[size-1-i]=temp;
	}
}


// Searches for an element
int searchElement(int array[], int size, int target) {
	for(int i=0;i<size;i++) {
		if(array[i]==target) return i;
	}
	return -1;
}

// Inserts an element at a specific position
void insertElement(int array[], int *size, int position, int value) {
	for(int i =*size; i>position;i--) {
		array[i]=array[i-1];
	}
	array[position]=value;
	(*size)++;
}

// Calculates standard deviation
double calculateStandardDeviation(int array[], int size) {
	double mean=calculateAverage(array, size);
	double variance=0;
	
	for(int i=0; i<size;i++) {
		variance+=pow(array[i]-mean, 2);	
	}
	
	variance/=size;
	return sqrt(variance);
}

// Displays a 2D matrix
void displayMatrix(int matrix[][3], int rows, int columns) {
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			printf("%d", matrix[i][j]);
		}
printf("\n");
	}
}

