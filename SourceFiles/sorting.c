/* PROGRAM:  sorting.c
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

/*Assort the students in the courses*/
void enrollInCourses(Course **pCourse, Student ** pStudent){

    Course *pCourser = pCourse;

    pCourser->ppRegistered = realloc(pCourser->ppRegistered,(pCourser->numStudentsRegistered+1)*sizeof(Student*));

    int students = pCourser->numStudentsRegistered;

    pCourser->numStudentsRegistered++;

    pCourser->ppRegistered[students] = pStudent;

}

/*Put the student in the waitlist in the course struct*/
void appendStudentToWaitlist(Course **pCourse, Student ** pStudent){

    Course *pCourser = pCourse;

    pCourser->ppWaitlisted = realloc(pCourser->ppWaitlisted,(pCourser->numStudentsWaitlisted+1)*sizeof(Student*));

    int students = pCourser->numStudentsWaitlisted;

    pCourser->numStudentsWaitlisted++;

    pCourser->ppWaitlisted[students] = pStudent;

}
/*Check through the course pointer to discover whether or not the student is on the course list*/
bool isStudentOnRegList(Course *pCourse, Student *pStudent){
    int i;

    for(i=0;i<pCourse->numStudentsRegistered; i++){
      if(pCourse->ppRegistered[i] == pStudent)
        return 1;
      else
        return 0;
  }
}
/*Same check as registration list, except looking through the waitlist*/
bool isStudentOnWaitlist(Course *pCourse, Student *pStudent){
    int i;
    for(i=0;i<pCourse->numStudentsWaitlisted; i++){
      if(pCourse->ppWaitlisted[i] == pStudent)
        return 1;
      else
        return 0;
    }
}
