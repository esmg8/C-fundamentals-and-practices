#include <stdio.h>

#define MOVIE_COUNT 5
#define SESSION_COUNT 3

// Movie information
typedef struct {
	char name[30];
	int price;
} Movie;

// Sessions
const char sessions[SESSION_COUNT][10] = {
"2.00 pm",
"5.00 pm",
"8.00 pm" 
};

void displayMovies(const Movie *movies, int count);
void displaySessions(void);
int getValidatedInput(int min, int max, const char *promt);
void printTicket(const Movie *movie, int sessionIndex);

int main(void) {
	Movie movies[MOVIE_COUNT] = {
	{"Interstellar", 250},
	{"The Prestige", 300},
	{"The Dark Knight", 275},
	{"Tenet", 175},
	{"Inception", 200}
	};
	
	printf("=== CINEMA RESERVATION SYSTEM ===\n\n");
	displayMovies(movies, MOVIE_COUNT);
	
	// Movie choice (1-5)
	int movieChoice= getValidatedInput(1, MOVIE_COUNT, "Enter the movie number:  ");
	int movieIndex= movieChoice -1;
	
	printf("\nSelected: %s \n\n", movies[movieIndex].name);
	
	// Session choice (1-3)
	displaySessions();
	int sessionChoice = getValidatedInput(1, SESSION_COUNT, "Please choose a session time: ");
	int sessionIndex= sessionChoice -1;
	
	// Ticket Summary
	printTicket(&movies[movieIndex], sessionIndex);
	
	return 0;
}

// The list of movies (with pointer)
void displayMovies(const Movie *movies, int count) {
	printf("--- MOVIES ---\n");
	for(int i=0;i<count;i++) {
		printf("%d- %16s: %d TL \n", i+1, (movies+i)->name, (movies+i)->price);
	}
	printf("----------------\n");
}


// The list of sessions
void displaySessions(void) {
	printf("--- SESSIONS ---\n");
	for(int i=0;i<SESSION_COUNT;i++) {
		printf("%d - %s\n", i+1, sessions[i]);
	}
	printf("-----------------\n");
}


// The function of login verification
int getValidatedInput(int min, int max, const char *prompt) {
	int value;
	do{
		printf("%s", prompt);
		if(scanf("%d", &value)!=1) {
			while(getchar()!='\n');
			printf("Invalid input! Please enter a number.\n");
			continue;
		}
	if(value<min || value>max) printf("Invalid choice! Enter a value between %d and %d.\n", min,max);
	}while(value<min || value>max);
	return value;
}

// The function of printing ticket
void printTicket(const Movie *movie, int sessionIndex) {
	printf("\n========================\n");
	printf("       TICKET SUMMARY     \n");
	printf("==========================\n");
	printf("Movie:    %s\n", movie->name);
	printf("Session:  %s\n", sessions[sessionIndex]);
	printf("Fee:      %d\n", movie->price);
	printf("==========================\n");
	printf("Enjoy watching!\n");
}
      