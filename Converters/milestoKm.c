#include <stdio.h>

#define MILES_TO_KM 1.609

int main(void)
{
	double  mile;
	double  km;
	
	// this is one line comment
	
	/* I will get miles from user,
	   then I will evaluate the km's.
	   finally display data to the user */
	   
	   printf("Enter your miles value:");
	   scanf("%lf",&mile);
	   
	   km=mile*MILES_TO_KM;
	   
	   printf("The km value is %f \n",km);
	   
	   return 0;
}