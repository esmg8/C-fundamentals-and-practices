#include <stdio.h>

// Shape drawing examples
// practicing nested for loops and pattern printing.

int main() {
	
	// SHAPE 1
	for(int i=1;i<=5;i++){
		printf("*****\n");
	}
	printf("\n\n");
	
	// SHAPE 2
	for(int i=1;i<=5;i++){
		for(int j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
	// SHAPE 3
	for(int i=1;i<=5;i++){
		printf("**\n");
	}
	printf("\n\n");
	
	// SHAPE 4
	for(int i=1;i<=5;i++){
		for(int j=5;j>=i;j--){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
	// SHAPE 5
	for(int i=1;i<=5;i++){
		for(int j=1;j<=i;j++){
			printf("*");
		}
		for(int k=5;k>=i;k--){
			printf(" ");
		}
		for(int k=5;k>=i;k--){
			printf(" ");
		}
		for(int j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	for(int i=1;i<=5;i++) {
	for(int j=5;j>=i;j--) {
		printf("*");
	}
	
	for(int j=1;j<=i;j++){
		printf(" ");
	}
	
	for(int j=1;j<=i;j++) {
		printf(" ");
	}
	
	for(int k=5;k>=i;k--) {
		printf("*");
	}
	printf("\n");
}
printf("\n\n");

    // SHAPE 6
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5-i;j++)
		{
			printf(" ");
		}
		
		for(int j=1;j<=i;j++)
		{
			printf(" *");
		}
		printf("\n");
		
	}
printf("\n\n");

    // SHAPE 7
int width, length;
	printf("Enter the width value:\n");
	scanf("%d", &width);
	
	printf("Enter the length value:\n");
	scanf("%d", &length);
	
	for(int i=1;i<=length;i++) {
		for(int j=1;j<=width;j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
return 0;
}

