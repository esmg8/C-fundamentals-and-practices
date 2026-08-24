#include <stdio.h>
#include <string.h>
 
#define M_WEIGHT 0.3
#define P_WEIGHT 0.2
#define F_WEIGHT 0.5
#define STUDENT_COUNT 3


typedef struct {
	char name[20];
	int midterm, popquiz, final;
	
}Student;


float calculateAverage(int midterm, int popquiz, int final);
void initializeStudent(Student *student, char name[], int midterm, int popquiz, int final);


int main()
{
	Student student[STUDENT_COUNT];
	
	initializeStudent(&student[0], "Ahmet Basarili", 45, 78, 65);
    initializeStudent(&student[1], "Kaya Dalgic", 65, 65, 80);
    initializeStudent(&student[2], "Aysegul Var", 57, 48, 75);
	
	
	//Calculate weighted averages
	for(int i=0;i<STUDENT_COUNT;i++) {
		printf("%s's weighted average: %6.2f\n", student[i].name, calculateAverage(student[i].midterm, student[i].popquiz, student[i].final));
	}
	
	return 0;		 
}


float calculateAverage(int midterm, int popquiz, int final) {
	float average= midterm*M_WEIGHT + popquiz* P_WEIGHT + final*F_WEIGHT;
	return average;
}


void initializeStudent(Student *student, char name[], int midterm, int popquiz, int final) {
	strcpy(student->name, name);
	student->midterm=midterm;
	student->popquiz=popquiz;
	student->final=final;
	
	
}

