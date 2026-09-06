#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//PI value
#define PI 3.14


int main ()
{
	double d1,d2,thickness,density;
	double count,oneFlatWasherWeight,totalShippingWeight;
	
	printf("Enter outer diameter:");
	scanf("%lf",&d2);
	printf("Enter inner diameter:");
	scanf("%lf",&d1);
	
	
	if(d1>d2)
	{
		printf("Your inner diameter is greater than outer diameter\n");
		system("pause");
		exit(0);
	   }
	printf("Enter thickness:");
	scanf("%lf", &thickness);
	
	printf("Enter density:");
	scanf("%lf", &density);
	
	
	printf("Enter count of Flat Washers:");
	scanf("%lf", &count);
	
	oneFlatWasherWeight= (PI*pow((d2/2),2)-PI*pow((d1/2),2))*
	                      thickness*density;
	                      
	totalShippingWeight=count*oneFlatWasherWeight;
	
	printf("Total weight of shippment is %10.4f\n",totalShippingWeight);
	return 0;    	
} 
