#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int grade;
  int studentID;
  char *name;
}student;

// Helper funcitons
int compGrade(const void * a, const void * b) {
  student * studentA = (student *) a;
  student * studentB = (student *) b;
  return (studentA->grade - studentB->grade);
}

int compID(const void * a, const void * b) {
  student * studentA = (student *) a;
  student * studentB = (student *) b;
  return (studentA->studentID - studentB->studentID);
}

#define ARRAY_SIZE 10

student students[ARRAY_SIZE] = {
  {87,  10001, "Fred"},
  {28,  10002, "Tom"},
  {100, 10003, "Alistair"},
  {78,  10004, "Sasha"},
  {84,  10005, "Erin"},
  {98,  10006, "Belinda"},
  {75,  10007, "Leslie"},
  {70,  10008, "Candy"},
  {81,  10009, "Aretha"},
  {68,  10010, "Veronica"}
};

int main() {
   qsort(students, ARRAY_SIZE, sizeof(student), compGrade);
  for(int i = 0; i < ARRAY_SIZE; i++) {
    printf("In order this is student #%i with grade %i\n",i+1,students[i].grade);
  }
   qsort(students, ARRAY_SIZE, sizeof(student), compID);
  for(int i = 0; i < ARRAY_SIZE; i++) {
    printf("In order this is student #%i with studentID %i\n",i+1,students[i].studentID);
  }
  return 0;
}
