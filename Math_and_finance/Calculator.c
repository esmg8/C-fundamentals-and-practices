#include <stdio.h>

// CALCULATOR

int main() {
	double number1, number2;
	double result;
	int choice;
	char answer;
	
	printf("Please enter first number:\n");
		scanf("%lf", &number1);
	
	do{
		printf("Please enter second number:\n");
		scanf("%lf", &number2);
		
		
		printf("------- MENU -------\n");
		printf("1- x+y\n");
		printf("2- x-y\n");
		printf("3- x*y\n");
		printf("4- x/y\n");
		printf("Enter the process you want to do:\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: result=number1+number2;
			printf("The result is %.2f\n", result);
			break;
			
			case 2: result= number1-number2;
			printf("The result is %.2f\n", result);
			break;
			
			case 3: result= number1*number2;
			printf("The result is %.2f\n", result);
			break;
			
			case 4: if(number2==0) {
				printf("Undefined!...\n");
				break;
			} 
			result=number1/number2;
			printf("The result is %.2f\n", result);
			break;
			
			default: printf("Invalid choice!...\n");
			break;
		}
		
		if(number2!=0 || choice!=4) number1=result;
		
		printf("Do you want to continue calculating? (y||n)");
		scanf(" %c", &answer);
		if(answer== 'n' || answer == 'N') break;	
		
	} while(answer== 'y' || answer == 'Y');
	
	
	return 0;
}