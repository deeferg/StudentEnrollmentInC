/* PROGRAM:  student.h
   AUTHOR:   Devan J Ferguson
   DATE:     10/12/2017
   TOPIC:    Structs, pointers, and randomization
   PURPOSE:  Learning to build and manage data structures
   LEVEL OF DIFFICULTY:
   CHALLENGES:
   HOURS:
*/

typedef struct {
  int id;
  struct{
    char* firstName;
    char* lastName;
  } name;

}Student;


extern unsigned long long rdtsc();

extern int generateStudentID();

extern void initStudent(Student **st);

extern Student returnStudent(Student *st);

extern void printStudentRegisteredFor(Student *pStudent);

extern void printStudentWithID(Student **pStudent);
/*
extern Student* initStudents();
*/
