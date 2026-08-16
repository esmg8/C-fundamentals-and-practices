#include <stdio.h>

#define DOLLAR_VALUE 100
#define QUARTER_VALUE 25
#define DIME_VALUE 10
#define NICKEL_VALUE 5 
#define PENNY_VALUE 1

int main(void)
{
	char initials [10];
	int dollars, quarters, dimes, nickels, pennies;
	int totalCents, totalDollars, leftoverCents;
	
	printf("Enter customer's initials (e.g., E.K.): ");
	scanf("%s", initials);
	
	printf("Enter number of dollars: ");
	scanf("%d", &dollars);
	
	printf("Enter number of quarters: ");
	scanf("%d", &quarters);
	
	printf("Enter number of dimes: ");
	scanf("%d", &dimes);
	
	printf("Enter number of nickles: ");
	scanf("%d", &nickels);
	
	printf("Enter number of pennies: ");
	scanf("%d", &pennies);
	
	totalCents = dollars * DOLLAR_VALUE
	           + quarters * QUARTER_VALUE
	           + dimes * DIME_VALUE
	           + nickels * NICKEL_VALUE
	           + pennies * PENNY_VALUE;
	           
	totalDollars = totalCents / 100;
	leftoverCents = totalCents % 100;
	
	printf("\n-----CREDIT SLIP-----\n");
	printf("Customer: %s\n", initials); 
	printf("Total amount: $%d.%02d\n", totalDollars, leftoverCents);
	printf("------------------------\n");
	
	return 0;
}
