#include <stdio.h>

#define CBEGIN 10
#define CEND -5
#define CSTEP 5


int main()
{
	//Celcius to fahrenheit
	//fahrenheit = 1.8 * celcius + 32.0
	//beginning values: 10, 5, 0, -5 celcius
	
	int celcius;
	double fahrenheit;
	
	for(celcius = CBEGIN;
	    celcius >= CEND;
		celcius-=CSTEP){
			fahrenheit = 1.8 *celcius + 32.0;
			printf("%6c%3d%8c%7.2f\n", ' ', celcius, ' ', fahrenheit);
		}
		
		
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}