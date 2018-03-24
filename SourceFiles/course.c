/* PROGRAM:  course.c
   AUTHOR:   Devan J Ferguson
   DATE:     10/12/2017
   TOPIC:    Structs, pointers, and randomization
   PURPOSE:  Learning to build and manage data structures
   LEVEL OF DIFFICULTY:
   CHALLENGES:
   HOURS:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "student.h"
#include "course.h"
#include "sorting.h"
#define NUM_OF_COURSES 3

/*Generate random course code with 3 digits*/
char* generateCourseCode(){
    int random = (rdtsc() % 1000);
    char* courseStr;
    sprintf(&courseStr ,"CS%03d", random);
    return courseStr;

}
/*Initializes a single course, generates the ID and the number of students that are allowed.
Everything else set to null or 0*/
void initCourse(Course **course){

    Course *courser = course;

    courser->pCourseCode = generateCourseCode();
    courser->maxStudents = ((rdtsc()%4)+4);
    courser->ppRegistered = NULL;
    courser->ppWaitlisted = NULL;
    courser->numStudentsRegistered = 0;
    courser->numStudentsWaitlisted = 0;

  }
/*Print Course by pointer function and Students as well*/
void printCourse(Course  **pCourse){
    Course *course = pCourse;
    printf("%s - %s\n%s\nRegistered Students(%d/%d)\n", &course->pCourseCode, course->pName, course->pDescription, course->numStudentsRegistered, course->maxStudents);
    int i;
    for(i = 0; i < course[i].numStudentsRegistered; i++){
      printStudentWithID(course->ppRegistered[i]);
    }

}
