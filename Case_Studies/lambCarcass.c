#include <stdio.h>


int getLambCount();
double getAverageWeight();
double calculateTotalW(int lambCount, double avgWeight);
double calculateTissueW(double totalWeight, double ratio);
void displayResults(int lamb_Count, double avgWeight, double totalWeight, double meatWeight, double fatWeight, double boneWeight, double tendonWeight);

int main()
{
	int lambCount;
	double avgWeight;
	double totalWeight;
	double meatWeight, fatWeight, boneWeight, tendonWeight;

	
	const double MEAT_RATIO = 0.59;
	const double FAT_RATIO = 0.16;
	const double BONE_RATIO = 0.18;
	const double TENDON_RATIO = 0.06;
	
	lambCount= getLambCount();
	avgWeight= getAverageWeight();

	
	totalWeight = calculateTotalW(lambCount, avgWeight);
	
	meatWeight = calculateTissueW(totalWeight, MEAT_RATIO);
	fatWeight = calculateTissueW(totalWeight, FAT_RATIO);
	boneWeight = calculateTissueW(totalWeight, BONE_RATIO);
	tendonWeight = calculateTissueW(totalWeight, TENDON_RATIO);
	
	displayResults(lambCount, avgWeight, totalWeight, meatWeight, fatWeight, boneWeight, tendonWeight);
	
	return 0;	
}

int getLambCount() {
	int lambCount, iter;
	do{
	    printf("Enter the count of lambs: ");
	    iter=scanf("%d", &lambCount);	
	   	if(iter!=1 || lambCount <=0) {
	    		 printf("Invalid lamb count!\n");
	    		 if(iter!=1) {
	    		 while(getchar() != '\n') {
				 }	
				 }
	    		 
			}
	}while (iter!=1 || lambCount<=0);
	return lambCount;
}

double getAverageWeight() {
	double avgWeight;
	int iter;
		do {
	    printf("Enter the average weight of the lambs (kg): ");
	    iter=
		scanf("%lf", &avgWeight);
	    if(iter!=1 || avgWeight <=0) {
	    	printf("Invalid average weight!\n");
	    	 if(iter!=1) {
	    		 while(getchar() != '\n') {
				 }	
				 }
	    
		}	
	} while(iter!=1 || avgWeight<=0);
	return avgWeight;
}


double calculateTotalW(int lambCount, double avgWeight) {
	return lambCount*avgWeight;
}

double calculateTissueW(double totalWeight, double ratio) {
	return totalWeight*ratio;
}



void displayResults(int lambCount, double avgWeight, double totalWeight, 
                    double meatWeight, double fatWeight, double boneWeight, 
					double tendonWeight){
	
	printf("\n--- Carcass Weight Information ---\n");
	printf("Total Lamb Count: %d\n", lambCount);
	
	printf("Average Lamb Weight: %.2f kg \n", avgWeight);
	printf("---------------------------------\n");
	printf("TOTAL CARCASS WEIGHT: %.2f kg \n", totalWeight);
	printf("---------------------------------\n");
	printf("Total Weights by Tissue:\n");
	printf("  Meat Weight:   %.2f kg\n", meatWeight);
	printf("  Fat Weight:    %.2f kg\n", fatWeight);
	printf("  Bone Weight:   %.2f kg\n", boneWeight);
	printf("  Tendon Weight: %.2f kg\n", tendonWeight);
	printf("---------------------------------\n");
}