#include <stdio.h>

int main() {
	int number, tens, ones;
	do {
	printf("Enter two digits number:\n");
	scanf("%d", &number);
	if(number<10 ||number>99) printf("Invalid number!\n");
	}while(number<10|| number>99);
	
	tens=number/10;
	ones=number%10;
	
	switch (tens) {
		case 1:
			printf("on");
			break;
		case 2:
			printf("yirmi");
		    break;
		case 3:
			printf("otuz");
			break;
		case 4:
			printf("kirk");
			break;
		case 5:
			printf("elli");
			break;
		case 6:
			printf("altmis");
			break;
		case 7:
			printf("yetmis");
			break;
		case 8:
			printf("seksen");
			break;
		default:
			printf("doksan");
			break;
	}
	
	switch (ones) {
		case 1:
			printf("bir");
			break;
		case 2:
			printf("iki");
		    break;
		case 3:
			printf("uc");
			break;
		case 4:
			printf("dort");
			break;
		case 5:
			printf("bes");
			break;
		case 6:
			printf("alti");
			break;
		case 7:
			printf("yedi");
			break;
		case 8:
			printf("sekiz");
			break;
		case 9:
			printf("dokuz");
			break;
		default:
			break;
	}
	
    printf("\n");

	return 0;
}