#include <stdio.h>
#include <string.h>

int main() {
	char message[100];
	char copy[100];
	char partial[100];
	int number;
	char secondMessage[100];
	
	printf("Enter a message:\n");
	fgets(message, 100, stdin);
	printf("%s\n", message);
	
	int length= strlen(message);
	printf("The length of the sentence: %d\n", length);
	
	strcpy(copy, message);
	printf("%s\n", copy);
	
	printf("How many number do you want to copy?\n");
	scanf("%d", &number);
	getchar();
	
	strncpy(partial, message, number);
	partial[number] = '\0';
	printf("%s\n", partial);
	
	printf("Enter the second message you want to add:\n");
	fgets(secondMessage, 100, stdin);
	
	message[strlen(message)-1]='\0';
	secondMessage[strlen(secondMessage) - 1] = '\0';
	strcat(message, secondMessage);
	printf("%s\n", message);


	return 0;
}