#include <stdio.h>

int main() {
	int first_number;
	int second_number;
	int sum;
	int count;
	double average;
	char choice;
	
	do{
	do {
		sum=0;
		count=0;
		printf("Enter two values respectively:\n");
		scanf("%d%d", &first_number, &second_number);
		
		if(first_number>second_number) printf("Incorret order! Please try again.\n");
	} while(first_number>second_number);
	
	for(int i=first_number;i<=second_number;i++) {
		sum+=i;
		count++;
	}
	average= (double)sum/count;
	printf("The sum of the numbers from %d to %d is equal to %d.\n", first_number, second_number, sum);
	printf("There are %d numbers between %d to %d.\n", count, first_number, second_number);
	printf("The average is %.2f\n", average);		
	
	printf("Do you want to do it again? (Y or N)\n");
	scanf(" %c", &choice);
	
	}while(choice == 'Y' || choice == 'y');
	
	return 0;
}

