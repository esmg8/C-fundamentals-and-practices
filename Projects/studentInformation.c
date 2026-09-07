#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for gender 
typedef enum {
	MALE, 
	FEMALE	
} Gender;

// Structure for student information
typedef struct {
	char name[20];
	char surname[20];
	int age;
	Gender gender;
	char department[50];
}Student;

// Gets student information from the user
void getStudentInfo(Student *student) {
	int genderChoice;
	
printf("\nEnter name:\n");
scanf("%19s", student->name);

printf("Enter surname:\n");
scanf("%19s", student->surname);

printf("Enter age:\n");
scanf("%d", &student->age);

printf("Enter gender (0 = Male, 1 = Female):\n");
scanf("%d", &genderChoice);

if(genderChoice == 0) student->gender= MALE;
else student->gender = FEMALE;

printf("Enter department:\n");
scanf(" %49[^\n]", student->department);	
		
}

// Displays student information
void displayStudent(Student student) {
printf("\n==== STUDENT INFORMATION ====\n");
printf("==== Name: %s %s\n", student.name, student.surname);
printf("==== Age: %d\n", student.age);

if(student.gender==MALE) printf("==== Gender: Male\n");
else printf("==== Gender: Female\n");

printf("==== Department: %s\n", student.department);	
}

int main() {
	// Normal structure variable
	Student student1;
	// Dynamically allocated structure 
	Student *student2;
	
	student2= (Student*)malloc(sizeof(Student));
	if(student2==NULL){
		printf("Memory allocation failed.!!\n");
		return 1;
	}
	
	printf("==== STUDENT 1 ====\n");
	getStudentInfo(&student1);
	
	printf("==== STUDENT 2 ====\n");
	getStudentInfo(student2);
	
	printf("\n\n==== STUDENT 1 ====\n");
	displayStudent(student1);
	
	printf("\n==== STUDENT 2 ====\n");
	displayStudent(*student2);
	
	// Free dynamically allocated memory
	free(student2);
	
	return 0;
}
