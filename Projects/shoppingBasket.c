#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCT_SIZE 20
#define BASKET_SIZE 5

typedef struct {
	int id;
	char name[30];
	double price;
	char unit;
}Product; 

typedef struct {
	int productId;
	int quantity;
}BasketItem;


Product products[PRODUCT_SIZE];
BasketItem basket[BASKET_SIZE];
int nextProductId=1;
int productCount=0;
int basketCount=0;

void addProduct(void);
void listProducts(void);
void deleteProduct(void);
void addToBasket(void);
void deleteFromBasket(void);
void listBasket(void);
void calculateTotal(void);
void menu(void);


void addProduct() {
	Product product;
	
	if(productCount>=PRODUCT_SIZE) {
		printf("No space for a new product!\n");
		return;
	}
	
	product.id=nextProductId;
	nextProductId++;
	printf("Enter product name:\n");
	scanf("%s", product.name);
	
	printf("Enter product price:\n");
	scanf("%lf", &product.price);
	
    do {
   	printf("Enter product unit (K: kilogram, C: count):\n");
	scanf(" %c", &product.unit);
    
	if(product.unit!= 'K' && product.unit!= 'C'){
		printf("Invalid unit! Please enter K or C!\n");
	}		
	}while(product.unit != 'K' && product.unit != 'C');
	
	products[productCount]=product;
	productCount++;	
	
	printf("\nProduct added successfully!\n");
	printf("Product ID: %d\n", product.id);
}


void listProducts() {
	int i;
	
	if(productCount==0) {
		printf("\nNo products available.\n");
		return;
	}
	
	printf("\n==== PRODUCTS ====\n");
	for(i =0;i<productCount;i++){
	printf("Product ID: %d\n", products[i].id);
	printf("Product Name: %s\n", products[i].name);
	printf("Price: %.2f\n", products[i].price);
	
	if(products[i].unit== 'K') printf("Unit: Kilogram\n");
	else printf("Unit: Count\n");
	
	printf("--------------------\n");
	}
}


void deleteProduct() {
	int productId;
	int i,j;
	
	if(productCount==0) {
		printf("\nNo products available to delete.\n");
		return;
	}
	
	listProducts();
	
	printf("Enter product ID to delete:\n");
	scanf("%d", &productId);
	
	for(i=0;i<productCount;i++) {
		if(products[i].id==productId) {
			for(j=i;j<productCount-1;j++) {
				products[j]=products[j+1];
			}
			productCount--;
			
			printf("Product deleted successfully.\n");
			return;
		}
	}
	printf("Product not found.\n");	
}


void addToBasket(void) {
	int productId;
	int quantity;
	int i;
	
	if(productCount==0) {
		printf("\nThere are no products available.\n");
		return;
	}
	
	listProducts();
	printf("Enter product ID:\n");
	scanf("%d", &productId);
	
	for(i=0;i<productCount;i++) {
		if(products[i].id==productId) {
			break;
		}
	}
	if(i==productCount) {
		printf("\nProduct not found!\n");
		return;
	}
	
	printf("Enter quantity:\n");
	scanf("%d", &quantity);
	
	if(quantity<=0) {
		printf("Quantity must be greater than zero.\n");
		return;
	}
	
	for(i=0;i<basketCount;i++) {
		if(basket[i].productId==productId) {
			basket[i].quantity+=quantity;
			printf("\nProduct quantity updated in basket!\n");
			return;
		}
	}
	
	if(basketCount>=BASKET_SIZE){
		printf("\nBasket is full!\n");
		return;
	}
	
	basket[basketCount].productId=productId;
	basket[basketCount].quantity=quantity;
	
	basketCount++;
	printf("Product added to basket successfully!\n");
}

void listBasket(void) {
	int i, j, found;
	
	if(basketCount==0) {
		printf("Basket is empty!\n");
		return;
	}
	printf("==== BASKET ====\n");
	for(i=0;i<basketCount;i++) {
		found=0;
		for(j=0;j<productCount;j++) {
			if(products[j].id==basket[i].productId) {
				printf("\nProduct: %s\n", products[j].name);
                printf("Quantity: %d\n", basket[i].quantity);
                printf("Unit Price: %.2f TL\n", products[j].price);

                printf("Subtotal: %.2f TL\n",
                       products[j].price * basket[i].quantity);

                found = 1;
                break;
			} 
		}
		if(!found) {
			printf("Product ID %d could not be found.\n",
                   basket[i].productId);
		}
		printf("---------------------\n");
	}
}

void deleteFromBasket(void) {
	int productId;
    int i;
    int j;

    if (basketCount == 0)
    {
        printf("\nBasket is empty.\n");
        return;
    }

    listBasket();

    printf("\nEnter product ID to remove from basket: ");
    scanf("%d", &productId);

	for (i = 0; i < basketCount; i++)
    {
        if (basket[i].productId == productId)
        {
            /*
                Shift basket items to the left.
            */
            for (j = i; j < basketCount - 1; j++)
            {
                basket[j] = basket[j + 1];
            }

            basketCount--;

            printf("\nProduct removed from basket!\n");
            return;
        }
    }

    printf("\nProduct is not in the basket.\n");
}
	
	
void calculateTotal(void)
{
    int i;
    int j;
    double total = 0;

    if (basketCount == 0)
    {
        printf("\nBasket is empty.\n");
        return;
    }
 for (i = 0; i < basketCount; i++)
    {
        for (j = 0; j < productCount; j++)
        {
            if (basket[i].productId == products[j].id)
            {
                total += products[j].price * basket[i].quantity;
                break;
            }
        }
    }

    printf("\n============================\n");
    printf("Total Basket Price: %.2f TL\n", total);
    printf("============================\n");
}


void menu(void)
{
    int choice;
 do
    {
        printf("\n\n========== SHOPPING BASKET ==========\n");
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Delete product\n");
        printf("4. Add item to basket\n");
        printf("5. Delete item from basket\n");
        printf("6. List basket\n");
        printf("7. Calculate total\n");
        printf("8. Exit\n");
        printf("=====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
 switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                listProducts();
                break;

            case 3:
                deleteProduct();
                break;

            case 4:
                addToBasket();
                break;
				
			case 5:
                deleteFromBasket();
                break;

            case 6:
                listBasket();
                break;

            case 7:
                calculateTotal();
                break;

            case 8:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
   } while (choice != 8);
}


int main(void)
{
    menu();

    return 0;
}



