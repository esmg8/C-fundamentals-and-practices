#include <stdio.h>

#define MONTHS 12
#define SENTINEL 0


int main()
{
	int i;
	int sighting; //montly seen bald eagle count
	int seen; //bald eagle sighting count
	int seenAllYear=0; //one year sightings
	
	for(i=1;i<=MONTHS;i++)
	{
		sighting = 0;
		//get first data count for the next month
		printf("Enter your sighting count (enter the 0 to stop):\n");
		scanf("%d", &seen);
		while (seen != SENTINEL)
		{
			sighting +=seen;
	      	printf("Enter your sighting count (enter the 0 to stop):\n");
		    scanf("%d", &seen);
		}
		printf("The month %d summing is %d\n", 
		        i, sighting);
		
		
		seenAllYear+=sighting;
	}
	printf("The total sum of the sightings in one year is %d\n",
	       seenAllYear);
	
	
	
	
}