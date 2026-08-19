#include <stdio.h>

void countEvenOdd(void);
void findDivisors(void);
void countNumberTypes(void);
void sumDigits(void);
void sumNumbers(void);

int main() {
	
	int choice;
	
	do {
		printf("\n==== MENU ====\n");
	printf("1- Odd/Even Counter\n");
	printf("2- Finding the Divisors\n");
	printf("3- Positive, negative, and zero number counter\n");
	printf("   (Runs until stopped)\n");
	printf("4- Sum of the digits\n");
	printf("5- The sum of the numbers from 1 to n\n");
	printf("6- Exit\n");
	
	printf("Enter your choice:\n");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1: countEvenOdd();
		        break;
		case 2: findDivisors();
		        break;
		case 3: countNumberTypes();
		        break;
		case 4: sumDigits();
		        break;
		case 5: sumNumbers();
		        break;
		case 6: printf("Exiting...\n");
		        break;
		default: printf("Invalid choice!\n");
	 }
	} while(choice!=6);
	
	return 0;
}


void countEvenOdd() {
	int number;
	int i;
	int evenCount=0;
	int oddCount=0;
	
	printf("Enter a number:\n");
	scanf("%d", &number);
	
	for(i=1;i<=number;i++) {
		if(i%2==0){
			evenCount +=1;
			printf("%d is an even number.\n", i);
		} else {
			oddCount +=1;
			printf("%d is an odd number.\n", i);
		}
	}	
	printf("The count of even numbers: %d\n", evenCount);
	printf("The count of odd numbers: %d\n", oddCount);
	
}


void findDivisors() {
	int number, i;
	
	do {
		printf("Enter a positive number:\n");
		scanf("%d", &number);
		
		if(number<=0) printf("Invalid number!\n");
	} while(number<=0);
	
	for(i=1;i<=number;i++) {
		if(number%i==0) {
			printf("%d is a factor of %d\n", i, number);
		}	
	}
}


void countNumberTypes() {
	int number, count=0;
	int positives=0, negatives=0, zeros=0;
	int sentinel=-1;
	
	printf("Enter a number(enter -1 to stop):\n");
	while(1) {
		scanf("%d", &number);
		if(number== sentinel) {
			break;
		} else if(number>0){
			positives++;
		} else if (number<0) {
			negatives++;
		} else {
			zeros++;
		}
		count++;
	}
	printf("Count of all the numbers: %d\n", count);
	printf("Count of positive numbers: %d\n", positives);
	printf("Count of negative numbers: %d\n", negatives);
	printf("Count of zeros: %d\n", zeros);	
}


void sumDigits() {
	int number;
	int sum=0;
	printf("Enter a number:\n");
	scanf("%d", &number);
	
	if(number<0) number=-number;
	
	printf("Your number: %d\n", number);
	while(number>0) {
		sum+=number%10;
		number/=10;
	}
	printf("Sum of digits is equal to %d\n", sum);
	
}



void sumNumbers() {
	int number, i=1, total=0;
	
	do{
		printf("Enter a positive number:\n");
		scanf("%d", &number);
		
		if(number<0) printf("Invalid number!\n");
	} while(number<=0);
	
	while(i<=number) {
		total+=i;
		i++;
	}
	printf("The sum of numbers from 1 to %d: %d", number, total);
}















