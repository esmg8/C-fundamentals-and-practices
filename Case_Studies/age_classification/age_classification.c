#include <stdio.h>

void identifying_age(int age);

int main()
{
	int age;
	char choice;
	
	do {
	
	printf("Enter the person's age: ");
	scanf("%d", &age);
	
	identifying_age(age);	
    printf("Do you want to enter another age? (Y/N)");
	scanf(" %c", &choice);
		
	} while(choice== 'Y' ||choice == 'y');
	

	return 0;	
}

void identifying_age(int age) {
	
    if (age<0) {
		printf("Invalid age entered!\n");
		
	}
	
	
	else if (age <=2) {
		printf("This person is a baby. \n");
	
	}
	
	else if (age <=12) {
		printf("This person is a child.\n");
	}
	
	
	else if (age<=18) {
		printf("This person is a teenager.\n");
	}
	
	else if (age<=25) {
		printf("This person is a younger.\n");
	}
	
	else if (age<=40) {
		printf("This person is an adult.\n");
	}
	
	else if (age<60) {
		printf("This person is a mid-ager.\n");
	}
	
	else {
		printf("This person is older.\n");
	}
	
}