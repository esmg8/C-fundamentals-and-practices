#include <stdio.h>
#include <stdlib.h>

 struct movie{
	int id;
	char name[50];
	char genre;
};

typedef struct movie Movie;


int main() {
	Movie *movie1;
	movie1=malloc(sizeof(Movie));
	
	if(movie1==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	printf("Enter movie ID:\n");
	scanf("%d", &movie1->id);
	getchar();
	printf("Enter movie name:\n");
	fgets(movie1->name, 50, stdin);
	printf("Enter movie's genre (only a letter: a-action or d-drama):\n");
	scanf(" %c", &movie1->genre);
	
	printf("==== MOVIE INFORMATION ====\n");
	printf("- ID: %d\n- %s- %c\n", movie1->id, movie1->name, movie1->genre);
	
	free(movie1);
	
	
	return 0;
}

