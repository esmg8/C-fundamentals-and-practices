#include <stdio.h>

int main()
{
	double investment, rate, interest;
	double one_year_amount;
	int iter;
	
	do {
	printf("Enter your investment amount: $");
	iter=scanf("%lf", &investment);
	
	if(iter!=1||investment <=0) {
		printf("Invalid investment amount!\n");
		if(iter!=1) {
			while(getchar()!='\n') {
			}
		}
	} 
	else if (investment <= 100000){
		rate = 0.02;
	}
	else if (investment <= 1000000){
		rate = 0.025;
	}
	else {
		rate = 0.03;
	}
		
	}while(iter!=1||investment<=0);
	
	
	interest = investment*rate;
	one_year_amount=investment+interest;
	
	printf("\n----------------------\n");
	printf("Investment Amount: $%.2f\n", investment);
	printf("Interest Rate: %.1f%%\n", rate*100);
	printf("One Year Interest: $%.2f\n", interest);
	printf("Total amount: %.2f\n", one_year_amount);
	
	
	if (investment <= 100000) {
		printf("Message: Consider investing more to get a higher interest value.\n");
	}
	
	else if(investment <= 1000000) {
		printf("Message: Great! Your investment is growing steadily.\n");
	}
	
	else {
		printf("Message: Excellent! You have a high-value investment.\n");
	}
	
	printf("------------------------\n");
	
}