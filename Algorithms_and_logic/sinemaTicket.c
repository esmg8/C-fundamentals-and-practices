#include <stdio.h>

int main()
{
	int movieChoice, ticketCount, movieTime;
	double price = 0.0, total = 0.0;
	char student;
	
	printf("--- Sinema Ticket System ---\n");
	printf("Available Movie Options:\n");
	printf("1-Interstellar (200 TL)\n");
	printf("2-Inception (180 TL)\n");
	printf("3-The Dark Knight (220 TL)\n");
	printf("4-Tenet (150 TL)\n");
	
	printf("Enter the number of the movie you want to watch between 1-4:\n");
	scanf("%d", &movieChoice);
	
	switch (movieChoice) {
		case 1:
			price = 200;
			printf("You selected Interstellar.\n");
			break;
			
		case 2:
			price = 180;
			printf("You selected Inception.\n");
			break;
			
		case 3:
			price = 220;
			printf("You selected The Dark Knight.\n");
			break;
			
		case 4:
			price = 150;
			printf("You selected Tenet.\n");
			break;
			
		default:
			printf("Invalid number! Please enter between 1-4.\n");
			return 0;
			
}


   printf("Select Movie Time:\n");
   printf("1- 13.00\n");
   printf("2- 15.00\n");
   printf("3- 18.00\n");
   printf("4- 20.00\n");
   scanf("%d", &movieTime);
   
    printf("How many tickets do you want to buy?\n");
     scanf("%d", &ticketCount);
    
     total = price * ticketCount;
    
    printf("Are you a student? (y/n)");
    scanf(" %c", &student);
    
    
    if ((((student == 'y') || (student == 'Y')) && (movieTime == 1)) || (ticketCount > 3)) {
	    total = total * 0.8;
    	printf("Student discount applied (20%% off)\n");
	}
	
	printf("Total amount to pay: %.2f TL\n", total);
	printf("Enjoy your movie!");
	
	return 0;
			
	
}