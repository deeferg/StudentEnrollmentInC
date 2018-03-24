/* PROGRAM:  sorting.h
   AUTHOR:   Devan J Ferguson
   DATE:     10/12/2017
   TOPIC:    Structs, pointers, and randomization
   PURPOSE:  Learning to build and manage data structures
   LEVEL OF DIFFICULTY:
   CHALLENGES:
   HOURS:
*/
#include <stdbool.h>

extern void appendStudentToWaitlist(Course **ppCourse, Student ** pStudent);

extern void enrollInCourses(Course **ppCourse, Student ** pStudent);

extern bool isStudentOnRegList(Course *pCourse, Student * pStudent);

extern bool isStudentOnWaitlist(Course *pCourse, Student * pStudent);
