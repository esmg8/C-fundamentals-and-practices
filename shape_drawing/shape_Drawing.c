#include <stdio.h>

void menu(void);
void drawCircle(void);
void drawIntersectingLines(void);
void drawBaseLine(void);
void drawParallelLines(void);
void drawPerson(void);
void drawHouse(void);


int main() {
	int choice;
	do {
		
	
	do {
	menu();
	
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		if(choice<0 ||choice>6) printf("Invalid number!\n");	
	}while(choice<0 ||choice>6);
	
	switch(choice) {
		case 1: 
		       drawCircle();
		       break;
		case 2: 
		       drawIntersectingLines();
		       break;
		case 3:
		       drawBaseLine();
		       break;
		case 4:
		       drawParallelLines();
			   break;
		case 5: 
		       drawPerson();
		       break;
		case 6:
			   drawHouse();
			   break;
		       
		default:
		       printf("Exiting...\n");
			   break;      
	}
}while(choice!=0);
	

	return 0;
}


void menu(void) {
    printf("==== SHAPE DRAWING PROGRAM ====\n");
	printf("1. Draw a circle\n");
	printf("2. Draw intersecting lines\n");
	printf("3. Draw a base line\n");
	printf("4. Draw parallel lines\n");
	printf("5. Draw a person\n");
	printf("6. Draw a house\n");
	printf("0. Exit\n");
}

void drawCircle(void) {
	printf("    -    \n");
	printf("  -   -  \n");
	printf(" -     - \n");
	printf("  -   -  \n");
	printf("    -    \n");
}

void drawIntersectingLines(void)
{
    printf("     -     \n");
    printf("   -   -   \n");
    printf("  -     -  \n");
    printf(" -       - \n");
    printf("-         -\n");
}

void drawBaseLine(void)
{
    printf(" ---------\n");
}


void drawParallelLines(void)
{
    printf("|         |\n");
    printf("|         |\n");
    printf("|         |\n");
    printf("|         |\n");
}


void drawPerson(void){
	drawCircle();
	drawIntersectingLines();
    drawBaseLine();
    drawIntersectingLines();
}

void drawHouse(void) {
	drawIntersectingLines();
	drawBaseLine();
	drawParallelLines();
	drawBaseLine();
}


