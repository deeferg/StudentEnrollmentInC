/* PROGRAM:  student.c
   AUTHOR:   Devan J Ferguson
   DATE:     10/12/2017
   TOPIC:    Structs, pointers, and randomization
   PURPOSE:  Learning to build and manage data structures
   LEVEL OF DIFFICULTY:
   CHALLENGES:
   HOURS:
*/
#include "student.h"
#include "course.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define NUM_OF_STUDENTS 12

/*Generates random number*/
unsigned long long rdtsc(){
    unsigned int lo,hi;

    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));

    return ((unsigned long long)hi << 32) | lo;
}
/*Generates student ID using random number generator*/
int generateStudentID(){

    int random = (rdtsc() % 100000);
    return random;
}
/*Intializes single student by generating ID*/
void initStudent(Student **st){

    Student *student = st;
    student->id = generateStudentID();

}
/*Return the single student */
Student returnStudent(Student *st){

    Student *getStudent = &st;
    return *getStudent;

}
/*Print statement for ID search*/
void printStudentRegisteredFor(Student *pStudent){
    printf("%s, %s is registered for:\n", pStudent->name.lastName, pStudent->name.firstName);
}
/*Print statement for in classes*/
void printStudentWithID(Student **pStudent){
    Student *student = pStudent;
    printf("%05d - %s, %s\n", student->id, student->name.lastName, student->name.firstName);
}
