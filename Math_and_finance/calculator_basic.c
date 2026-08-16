#include <stdio.h>

int main()
{
	
	double number1, number2;
	int choice;
	double calculation;
	char sign;
	char answer;
	int valid;
	
	do {
	
	do {	
	printf("Choice a number between 1-4:\n");
	scanf("%d",&choice);
	
	if (choice <1  || choice >4) {
		printf("Invalid number! Please enter between 1-4\n");
	}
	
	} while (choice<1|| choice>4);
	
	
	printf("Enter two numbers:\n");
	scanf("%lf%lf", &number1, &number2);
	
	valid=1;
	
	
	switch (choice) {
		case 1: 
		sign = '/';
		if(number2==0) {
			printf("Error! Cannot divide by zero.\n");
			valid =0;
			break;
		}
		calculation = number1 / number2;
		break;
		
		case 2:
			sign = '*';
			calculation = number1 * number2;
			break;
			
	    case 3:
	    	sign = '+';
	    	calculation = number1 + number2;
	    	break;
	    	
	    case 4:
	    	sign = '-';
	    	calculation = number1 - number2;
	    	break;  	
	}
	
	if(valid) {
	printf("-----------------\n");
	printf("Your numbers are %.2f and %.2f\n", number1, number2);
	printf("You selected %d and your sign is %c\n", choice, sign);
	printf("Your calculation is %.2f %c %.2f = %.2f \n", number1, sign, number2, calculation);
	printf("Your result: %.2f\n", calculation);
		
	}

	
	printf("Do you want to calculate again? (Y/N)\n"); 
	scanf(" %c", &answer);
	
	//Program tekrar calisacak
	} while (answer == 'y' || answer == 'Y');
	
	 if (answer == 'n' || answer == 'N') {
		printf("Exiting....\n");
	} else {
		printf("Invalid answer. Exiting...\n");
	}
	
	return 0;
 } 