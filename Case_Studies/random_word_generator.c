#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
void randoms();

int randNumbers[5];

int main() {
	char array[ARRAY_SIZE];
	char temp;
	int duplicate;
	
	srand(time(NULL));
	printf("Enter 10 elements for array:\n");
	
	for(int i=0;i<ARRAY_SIZE;i++) {
		do {
		
	    duplicate=0;
		scanf(" %c", &temp);
	   
	   for(int j=0;j<i;j++) {
	   	if(temp==array[j]){
	   		duplicate=1;
	   		printf("Enter a new character!\n");
		   } 
	   }
				
		}while(duplicate==1);
		array[i]=temp; 
	}

	for(int i=0;i<ARRAY_SIZE;i++) {
		printf("%c\n", array[i]);
	}
	
	for(int j=0;j<10;j++) {
	randoms();
    
    for(int i=0;i<5;i++) {
        printf(" %c", array[randNumbers[i]]); 	
	}
    printf("\n");
	}
    
	return 0;
}

void randoms() {
	for(int i=0;i<5;i++) {
		randNumbers[i]=rand()%10;
	}	
	
}
	
	
