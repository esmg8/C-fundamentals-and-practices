#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define LATE_CHG 2.0
#define USE_CHG 1.1
#define DEMAND_CHG 35.0


void help(void) {
	printf("===========================\n");
	printf("= Demand Charge is $35    =\n");
	printf("= Use charge is your      =\n");
	printf("= consumption of water    =\n");
	printf("= quarterly. Each meter   =\n");
	printf("= reading cost $1.1       =\n");
	printf("= if you have a debt from =\n");
	printf("= then a #2 late charfe   =\n");
	printf("= added to the bill       =\n");
	getch();	
}

int main(void) {
	int previous, current; // meter readings between last two quarters
	char unpaid; // is there any unpaid bill? "Y" or "N"
	double lateCharge, useCharge, bill;
	
	help();
	
	printf("Enter meter readings (previous current):\n");
	scanf("%d%d", &previous, &current);
	if(previous>current) {
		printf("Previous meter must be less or equal to current meter!");
		exit(0);
	}
	
	fflush(stdin);
	printf("Is there any unpaid bills? (Y/N):\n");
	scanf("%c", &unpaid);
	
	useCharge = (current-previous)*USE_CHG;
	if(toupper(unpaid)=='Y') lateCharge=LATE_CHG;
	else lateCharge=0;
	
	
	bill = DEMAND_CHG + useCharge + lateCharge;
	
	printf("Use charge = %.2f\n", useCharge);
	printf("Late charge = %.2f\n", lateCharge);
	printf("-------------------\n");
	printf("Bill total = %.2f\n", bill);
	
	return 0;
}



