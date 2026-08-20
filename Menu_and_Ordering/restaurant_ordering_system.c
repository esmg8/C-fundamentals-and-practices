#include <stdio.h>

typedef struct {
	char name[30];
	int price;
} menuItem;

menuItem foods[4] = {
	{"Pizza", 200},
	{"Hamburger", 180},
	{"Pasta", 150},
	{"Sushi", 200}
};


menuItem drinks[4] = {
	{"Diet Coke", 40},
	{"Ayran", 20},
	{"Soda", 15},
	{"Water", 10}
};


menuItem desserts[4] = {
	{"Chocolate Cake", 80},
	{"Ice Cream", 50},
	{"Cheesecake", 100},
	{"Kunefe", 125}
};


void printMenu(const char* title, menuItem items[], int size) {
	printf("\n--- %s ---\n", title);
	for(int i=0;i<size;i++) {
		printf("Option %d - %s: %d TL\n", i+1, items[i].name, items[i].price);
	}	
}

int main() {
	int choice, option, quantity;
	int total=0;
	char answer;
	
	do{
		do{
			printf("\n--- Main Menu ---\n");
			printf("1: Food\n2: Drinks\n3: Desserts\n");
			printf("Enter your choice (1-3):\n");
			scanf("%d",&choice);
			
			if(choice<1 || choice>3) printf("Invalid choice!\n");
		} while(choice<1 || choice>3); 
		
	menuItem* selectedCategory=NULL;
	int categorySize=4;
	
	if(choice==1) {
		printMenu("Food", foods, categorySize);
		selectedCategory=foods;
	}else if(choice==2) {
		printMenu("Drinks", drinks, categorySize);
		selectedCategory=drinks;
	} else {
		printMenu("Desserts", desserts, categorySize);
		selectedCategory=desserts;
	}
		
		
	do{
		printf("Enter option number (1-%d)", categorySize);
		scanf("%d", &option);
		if(option<1 || option> categorySize) printf("Invalid option!\n");
	}while(option<1 || option> categorySize);
		
		
-   do {
    printf("How many portions/items?: ");
    scanf("%d", &quantity);

    if(quantity <= 0)
        printf("Quantity must be greater than 0!\n");

} while(quantity <= 0);
	
	int itemCost =selectedCategory[option-1].price * quantity;
	total+=itemCost;
	
	printf("Added: %d * %s (%d TL)\n", quantity, selectedCategory[option-1].name, itemCost);
	printf("\nDo you want to add another item? (Y/N)");
	scanf(" %c", &answer);
	}while(answer== 'Y' || answer== 'y');
	
	printf("\n=======================\n");
	printf("Total Amount Due: %d TL \n", total);
	printf("Thank you for choosing us!\n");
	printf("==========================\n");
	
	return 0;
}