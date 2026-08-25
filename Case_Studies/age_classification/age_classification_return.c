#include <stdio.h>

const char* identifying_age(int age);

int main()
{
	int age;
	char choice;
	
	do {
	
	printf("Enter the person's age: ");
	scanf("%d", &age);
	
	const char* result=identifying_age(age);
	printf("This person is a %s.\n", result);	
    printf("Do you want to enter another age? (Y/N)");
	scanf(" %c", &choice);
		
	} while(choice== 'Y' ||choice == 'y');
	

	return 0;	
}

const char* identifying_age(int age) {
	
    if (age<0) {
	    return "invalid age";
	}
	
	else if (age <=2) {
		return "baby";
	
	}
	
	else if (age <=12) {
		return "child";
	}
	
	else if (age<=18) {
		return "teenager";
	}
	
	else if (age<=25) {
		return "younger";
	}
	
	else if (age<=40) {
	    return "adult";
	}
	
	else if (age<60) {
	    return "mid-ager";
	}
	
	else {
		return "older";
	}
	
}