#include <stdio.h>
#include <stdlib.h>

enum Genre {
	ACTION,
	DRAMA,
	SCI_FI,
	COMEDY
};

 struct movie{
	int id;
	char name[50];
	enum Genre genre;
};

typedef struct movie Movie;




int main() {
	Movie *movie1;
	movie1=malloc(sizeof(Movie));
	int choice;
	
	char *genreNames[] = {
    "Action",
    "Drama",
    "Sci-Fi",
    "Comedy"
};
	
	if(movie1==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	printf("Enter movie ID:\n");
	scanf("%d", &movie1->id);
	getchar();
	printf("Enter movie name:\n");
	fgets(movie1->name, 50, stdin);
	
	do{
		printf("0-Action\n1-Drama\n2-Sci-Fi\n3-Comedy\n");
	printf("Choose movie's genre: \n");
	scanf("%d", &choice);
	if(choice<0||choice>3) printf("Invalid number!\n");
	}while(choice<0||choice>3);
	
	movie1->genre=choice;
	
	printf("==== MOVIE INFORMATION ====\n");
	printf("- ID: %d\n- %s", movie1->id, movie1->name);
	printf("- Genre: %s\n", genreNames[movie1->genre]);
	
	free(movie1);
	
	
	return 0;
}

