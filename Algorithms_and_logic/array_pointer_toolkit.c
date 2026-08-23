#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int *array, int size);
void displayArray(int *array, int size);
int findMax(int *array, int size);
int findMin(int *array, int size);
int calculateSum(int *array, int size);
double calculateAverage(int *array, int size);
void reverseArray(int *array, int size);
void swap(int *x, int *y);
void swapElements(int *array, int index1, int index2);
void pointerDemo(void);
void pointerToPointerDemo(void);
int isEven(int number);
void displayEvenNumbers(int *array, int size);
void displayOddNumbers(int *array, int size);
int isPrime(int number);
void displayPrimeNumbers(int *array, int size);
void stringDemo(void);
void reverseString(char *str);
void displayMenu(void);

int main()
{
    int array[MAX_SIZE];
    int size;
    int choice;

    do
    {
        printf("How many elements do you want to enter (1-%d)? ", MAX_SIZE);
        scanf("%d", &size);

        if (size < 1 || size > MAX_SIZE)
        {
            printf("Invalid size. Please try again.\n");
        }

    } while (size < 1 || size > MAX_SIZE);

    inputArray(array, size);

    do
    {
        displayMenu();

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nArray: ");
                displayArray(array, size);
                printf("\n");
                break;

            case 2:
                printf("\n--- Array Statistics ---\n");
                printf("Maximum: %d\n", findMax(array, size));
                printf("Minimum: %d\n", findMin(array, size));
                printf("Sum: %d\n", calculateSum(array, size));
                printf("Average: %.2f\n", calculateAverage(array, size));
                break;

            case 3:
                reverseArray(array, size);

                printf("\nArray after reverse: ");
                displayArray(array, size);
                printf("\n");
                break;

            case 4:
            {
                int index1;
                int index2;

                printf("\nEnter first index: ");
                scanf("%d", &index1);

                printf("Enter second index: ");
                scanf("%d", &index2);

                if (index1 >= 0 && index1 < size &&
                    index2 >= 0 && index2 < size)
                {
                    swapElements(array, index1, index2);

                    printf("Array after swap: ");
                    displayArray(array, size);
                    printf("\n");
                }
                else
                {
                    printf("Invalid index!\n");
                }

                break;
            }

            case 5:
                printf("\n--- Even / Odd Analysis ---\n");

                displayEvenNumbers(array, size);
                displayOddNumbers(array, size);

                break;

            case 6:
                printf("\n--- Prime Number Analysis ---\n");

                displayPrimeNumbers(array, size);

                break;

            case 7:
                stringDemo();
                break;

            case 8:
                pointerDemo();
                break;

            case 9:
                pointerToPointerDemo();
                break;

            case 0:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid option. Please choose again.\n");
        }

    } while (choice != 0);

    return 0;
}


void inputArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}


void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }
}


int findMax(int *array, int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (*(array + i) > max)
        {
            max = *(array + i);
        }
    }

    return max;
}


int findMin(int *array, int size)
{
    int min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (*(array + i) < min)
        {
            min = *(array + i);
        }
    }

    return min;
}


int calculateSum(int *array, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }

    return sum;
}


double calculateAverage(int *array, int size)
{
    return (double)calculateSum(array, size) / size;
}


void reverseArray(int *array, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        swap(&array[start], &array[end]);

        start++;
        end--;
    }
}


void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}


void swapElements(int *array, int index1, int index2)
{
    swap(&array[index1], &array[index2]);
}


void pointerDemo(void)
{
    int value = 20;
    int *p = &value;

    printf("\n--- Pointer Demonstration ---\n");

    printf("Value of value: %d\n", value);
    printf("Address of value: %p\n", (void *)&value);
    printf("Value stored in p: %p\n", (void *)p);
    printf("Value pointed by p: %d\n", *p);

    *p = 99;

    printf("\nAfter changing *p to 99:\n");
    printf("Value of value: %d\n", value);
    printf("Value through pointer: %d\n", *p);
}


void pointerToPointerDemo(void)
{
    int value = 100;

    int *p = &value;
    int **pp = &p;

    printf("\n--- Pointer to Pointer Demonstration ---\n");

    printf("Value: %d\n", value);
    printf("Value using *p: %d\n", *p);
    printf("Value using **pp: %d\n", **pp);

    printf("\nAddress of value: %p\n", (void *)&value);
    printf("Value stored in p: %p\n", (void *)p);
    printf("Address of p: %p\n", (void *)&p);
    printf("Value stored in pp: %p\n", (void *)pp);

    **pp = 500;

    printf("\nAfter changing **pp to 500:\n");
    printf("Value: %d\n", value);
    printf("Value using *p: %d\n", *p);
    printf("Value using **pp: %d\n", **pp);
}


int isEven(int number)
{
    return number % 2 == 0;
}


void displayEvenNumbers(int *array, int size)
{
    printf("Even numbers: ");

    for (int i = 0; i < size; i++)
    {
        if (isEven(*(array + i)))
        {
            printf("%d ", *(array + i));
        }
    }

    printf("\n");
}


void displayOddNumbers(int *array, int size)
{
    printf("Odd numbers: ");

    for (int i = 0; i < size; i++)
    {
        if (!isEven(*(array + i)))
        {
            printf("%d ", *(array + i));
        }
    }

    printf("\n");
}


int isPrime(int number)
{
    if (number < 2)
    {
        return 0;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


void displayPrimeNumbers(int *array, int size)
{
    int found = 0;

    printf("Prime numbers: ");

    for (int i = 0; i < size; i++)
    {
        if (isPrime(*(array + i)))
        {
            printf("%d ", *(array + i));
            found = 1;
        }
    }

    if (!found)
    {
        printf("None");
    }

    printf("\n");
}


void stringDemo(void)
{
    char text[100];
    int length = 0;

    printf("\n--- String Operations ---\n");

    printf("Enter a string: ");

    getchar();

    fgets(text, sizeof(text), stdin);

    while (text[length] != '\0')
    {
        if (text[length] == '\n')
        {
            text[length] = '\0';
            break;
        }

        length++;
    }

    printf("Original: %s\n", text);
    printf("Length: %d\n", length);

    reverseString(text);

    printf("Reversed: %s\n", text);
}


void reverseString(char *str)
{
    int length = 0;

    while (*(str + length) != '\0')
    {
        length++;
    }

    for (int i = 0; i < length / 2; i++)
    {
        char temp = *(str + i);

        *(str + i) = *(str + length - 1 - i);
        *(str + length - 1 - i) = temp;
    }
}


void displayMenu(void)
{
    printf("\n========================================\n");
    printf("         ARRAY & POINTER TOOLKIT\n");
    printf("========================================\n");
    printf("1. Display Array\n");
    printf("2. Array Statistics\n");
    printf("3. Reverse Array\n");
    printf("4. Swap Elements\n");
    printf("5. Even / Odd Analysis\n");
    printf("6. Prime Number Analysis\n");
    printf("7. String Operations\n");
    printf("8. Pointer Demonstration\n");
    printf("9. Pointer to Pointer Demonstration\n");
    printf("0. Exit\n");
    printf("========================================\n");
}