#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getValues(int *data, int size);
void menu(int *choice);
double average(int *data, int size);
double standardDeviation(int *data, int size);
void bins(int *data, int size);
void outliers(int *data, int size);

int main() {
	int size, choice;
	
	do {
	printf("Enter the count of number:\n");
	scanf("%d", &size);
	if(size<=0) printf("Invalid number!\n");
	}while(size<=0);
	

	
	int *data;
	data=malloc(sizeof(int) *size);
	
	if(data==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	getValues(data, size);
	
	do {
    	menu(&choice);
		switch (choice) {
			case 1:
				printf("Average: %.2f\n", average(data, size));
				break;
			case 2:
				printf("Standard deviation: %.2f\n", standardDeviation(data, size));
				break;
			case 3:
				bins(data, size);
			    break;
			case 4:
				outliers(data, size);
				break;
			case 5:
				printf("Exiting...\n");
				break;
		}	
	}while(choice!=5);
	
	free(data);

	return 0;
}

void getValues(int *data, int size) {
	for(int i=0;i<size;i++) {
		do {
			printf("Enter %d. number:\n", i+1);
		scanf("%d", &data[i]);
		if(data[i]<0 || data[i]>100) {
			printf("Invalid number try again!\n");
		}
		}while(data[i]<0 || data[i]>100);
	}
	
}

void menu(int *choice) {
	printf("==== DATA ANALYSIS MENU ====\n");
	printf("1. Average of the data\n");
	printf("2. Standard deviation\n");
	printf("3. Count of numbers in bins\n");
	printf("4. Find outliers\n");
	printf("5. Exit\n");
	
	do {
	printf("Enter your choice:\n");
	scanf("%d", choice);
	if(*choice<1 || *choice>5) printf("Invalid choice!\n");
	}while(*choice<1 || *choice>5);

}

double average(int *data, int size) {
	double sum=0;
	
	for(int i=0;i<size;i++) {
		sum+=data[i];
	}
	
	return sum/size;
}

double standardDeviation(int *data, int size) {
	double mean=average(data, size);
	double sum=0;
	for(int i=0;i<size;i++) {
		sum+=pow(data[i]-mean, 2);
	}
	return sqrt(sum/size);
}

void bins(int *data, int size) {
	int bins[10]={0};
	int count100=0;
	for(int i=0;i<size;i++) {
		if(data[i]==100) count100++;
		else bins[data[i]/10]++;
	}
	
	for(int i=0;i<10;i++) {
		printf("%d-%d: %d\n", i*10, i*10+9, bins[i]);
	}
	printf("100: %d\n", count100);

}

void outliers(int *data, int size) {
	double mean=average(data, size);
	double sd=standardDeviation(data, size);
	
	double lower= mean-(3*sd);
	double upper=mean+ (3*sd);
	int found=0;
	
	for(int i=0;i<size;i++) {
		if(data[i]<lower || data[i]>upper) {
		printf("Outlier: %d\n", data[i]);
		found=1;	
		}
	}
	if(found==0) printf("No outliers found!\n");
}





