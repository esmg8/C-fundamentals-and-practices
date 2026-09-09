#include <stdio.h>
#include <string.h>

#define M_WEIGHT 0.3
#define P_WEIGHT 0.2
#define F_WEIGHT 0.5

typedef struct{
	char name[30];
	int midterm,project, final;
	float average;
	
}Student;

float calculateAverage(Student student);
char *calculateLetterGrade(float average);
void getGrades(Student *student);


int main() {
	int number;
	do {
	printf("How many students do you want to enter?\n");
	scanf("%d", &number);
	if(number<=0) printf("Invalid number!\n");
	}while(number<=0);

	
	
	int c;
	while((c=getchar())!= '\n'&& c!=EOF);
	
    Student students[number];
	
	for(int i=0;i<number;i++) {
		getGrades(&students[i]);
		students[i].average=calculateAverage(students[i]);
	}
	printf("==== STUDENT RESULT ====\n");
	for(int i=0;i<number;i++){
		printf("Student's name: %s\n", students[i].name);
		printf("The average = %.2f\n", students[i].average);
        printf("Letter grade: %s\n\n", calculateLetterGrade(students[i].average));
	}

	float classAverage, highestAvg=students[0].average, lowestAvg=students[0].average;
	float sum=0;
	for(int i=0;i<number;i++){
		sum+=students[i].average;
	}
	classAverage=sum/number;
	printf("Class average= %.2f\n", classAverage);
	for(int i=1;i<number;i++){
		if(students[i].average>highestAvg) highestAvg=students[i].average;
		if(students[i].average<lowestAvg) lowestAvg=students[i].average;
	}
	printf("Highest average: %.2f\n", highestAvg);
	printf("Lowest average: %.2f\n", lowestAvg);
	
	
	return 0;
}

float calculateAverage(Student student) {
	return student.midterm * M_WEIGHT + student.project*P_WEIGHT +student.final*F_WEIGHT;
}

char *calculateLetterGrade(float average) {
		if(average <50) {
		return "FF";
	} else if(average<60) {
	    return "DD";
	} else if(average<70) {
		return "CC";
	}else if(average<86) {
		return "BB";
	} else{
		return "AA";
	} 
}


void getGrades(Student *student) {
	
		printf("Enter student's name:\n");
		fgets(student->name, 30, stdin);
		student->name[strcspn(student->name, "\n")] = '\0';
		do{
	printf("Please enter your midterm, project and final score:\n");
	scanf("%d%d%d", &student->midterm, &student->project, &student->final);
	int e;
	while((e=getchar())!= '\n'&& e!=EOF);
	
	if(student->midterm<0||student->midterm>100|| student->project<0||student->project>100|| student->final<0||student->final>100) printf("Results must be between 0 and 100!\n");
    }while(student->midterm<0||student->midterm>100|| student->project<0||student->project>100|| student->final<0||student->final>100);
	
}








