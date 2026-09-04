#include <stdio.h>

void findMax(int data[],int size, int *maxValue);

int main() {
	int size;
	do{
	printf("Enter the array size:\n");
	scanf("%d", &size);
	 if(size<=0) {
	 	printf("Invalid number! Try again\n");
	 }
	} while (size<=0);
	int data[size];
	for(int i=0;i<size;i++) {
		printf("Enter the %d. number:\n", i+1);
		scanf("%d", &data[i]);
	}
	
	printf("Your array:\n");
	for(int i=0;i<size;i++) {
		printf("%d ", data[i]);
	}
	
	
	int maxValue;
	findMax(data, size, &maxValue);
	printf("\nThe max value in the array is %d.", maxValue);
	return 0;
}

void findMax(int data[], int size, int *maxValue) {
	*maxValue=data[0];
	for(int i=1;i<size;i++) {
	if(data[i]>*maxValue) *maxValue=data[i];
   }
}