/* PROGRAM:  course.h
   AUTHOR:   Devan J Ferguson
   DATE:     10/12/2017
   TOPIC:    Structs, pointers, and randomization
   PURPOSE:  Learning to build and manage data structures
   LEVEL OF DIFFICULTY:
   CHALLENGES:
   HOURS:
*/

typedef struct Course__{
  char* pName;
  char* pDescription;
  char *pCourseCode;/*2 letters and 3 random digits 'CS194'*/
  int maxStudents;
  int numStudentsWaitlisted;
  int numStudentsRegistered;
  Student **ppWaitlisted;
  Student **ppRegistered;

}Course;

extern char* generateCourseCode();

extern void initCourse(Course ** course);

extern void printCourse(Course  **pCourse);
