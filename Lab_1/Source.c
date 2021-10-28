#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE 1024
#define MAX_SIZE 128


typedef struct _students {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int points;
}Students;



int countStudents(char* fileName);
Students* allocateAndRead(char* fileName, int studentCount);
int printStructure(Students* chumps, int counter);


int main() {

	Students* cnT = NULL;

	int t = countStudents("Students.txt");
	printf("Number of students is: %d\n\n", t);
	cnT = allocateAndRead("Students.txt", t);

	printStructure(cnT, t);

	return 0;
}

int countStudents(char* fileName) {

	FILE* fp = NULL;

	int count = 0;
	char buff[MAX_LINE] = { '\0' };
	
	if (!(fp = fopen(fileName, "r"))) {
		printf("Can't open memory pal\n");
		return -1;
	}

	while (!feof(fp))
	{
		fgets(buff, MAX_LINE, fp);
		count++;
	}
	fclose(fp);
	return count;
}
	
Students* allocateAndRead(char* fileName, int studentCount) {
	
	FILE* fp = NULL;
	int counter = 0;
	Students* p = NULL;

	if (!(fp = fopen(fileName, "r"))) {
		printf("Guess what no can do allocate pointer \n");
		return NULL;
	}

	if (!(p = (Students*)malloc(studentCount * sizeof(Students)))) {
		printf("Didnt open strucure cunt\n");
		return NULL;
	}

	while (!feof(fp) && counter < studentCount) {
		fscanf(fp, " %s %s %d", p[counter].name, p[counter].surname, &p[counter].points);
		counter++;
	}
	fclose(fp);
	return p;
}

int printStructure(Students* chumps, int counter) {

	int count = 0;
	Students* Sp = chumps;
	int rel_points = 0;
	int abs_points = 0;

	while (count < counter) {
		printf("Name: %s Surname: %s Absolute Value: %d points Relative Value: %f percent\n-------------------------\n", Sp[count].name, Sp[count].surname, Sp[count].points, ((double)Sp[count].points/100)*100);
		count++;
	}
	free(Sp);
	return 0;
}
