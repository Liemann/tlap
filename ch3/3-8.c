#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

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
  int q1 = students[ARRAY_SIZE/4].grade;
  int q2 = students[ARRAY_SIZE/2].grade;
  int q3 = students[3*ARRAY_SIZE/4].grade;

  printf("To be better than 25%% of students you need a grade higher than or equal to: %i\n",q1);
  printf("To be better than 50%% of students you need a grade higher than or equal to: %i\n",q2);
  printf("To be better than 75%% of students you need a grade higher than or equal to: %i\n",q3);
  return 0;
}
