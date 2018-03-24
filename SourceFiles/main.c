/* PROGRAM:  main.c
   AUTHOR:   Devan J Ferguson
   DATE:     10/12/2017
   TOPIC:    Structs, pointers, and randomization
   PURPOSE:  Learning to build and manage data structures
   LEVEL OF DIFFICULTY: max level!
   CHALLENGES: Lots
   HOURS: 2 Months
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "student.h"
#include "course.h"
#include "sorting.h"
#define NUM_OF_STUDENTS 12
#define NUM_OF_COURSES 3

int main(void){
    int k;
    int i;
    int j;

    Student students[] =  {
                          {0, "Joe", "Cocker"},
                          {0, "Rick", "Astley"},
                          {0, "Waylon", "Jennings"},
                          {0, "Dunk", "Tall"},
                          {0, "Arthur", "Pennytree"},
                          {0, "Aegon", "Targaryen"},
                          {0, "Anthony", "Green"},
                          {0, "Chris", "Beck"},
                          {0, "Arya", "Stark"},
                          {0, "Margery", "Tyrell"},
                          {0, "Auston", "Matthews"},
                          {0, "Erin", "Snider"}
                        };

    Course courses[] =  {
                        {"Perl Programming", "Learn the fundamentals of programming scripts and be able to install Perl modules."},
                        {"Python Programming", "Learn the fundamentals of programming scripts and be able to install Python modules."},
                        {"Ruby Programming", "Learn the fundamentals of programming scripts and be able to install Ruby modules."}
                      };


    Student *pStudents = malloc(12 * sizeof(Student));
    Course *pCourses = malloc(3 * sizeof(Course));
    int nStudents = sizeof(students)/sizeof(Student);
    int nCourses = sizeof(courses)/sizeof(Course);
/*Initializing the Student Array*/
    for(i=0; i<nStudents; i++){

      pStudents[i] = students[i];

      initStudent(&pStudents[i]);
    }

/*Initializing the courses array*/
    for(i = 0; i < nCourses; i++){

      pCourses[i] = courses[i];

      initCourse(&pCourses[i]);
    }
/*Loop through students placing them randomly in courses*/
      for(i = 0; i < 2; i++){
        for(k = 0; k < 12; k++){

            while(1){
              int iCourse = rdtsc()%3;

              if (isStudentOnRegList(&pCourses[iCourse], &pStudents[k]))
                continue;

              else if (isStudentOnWaitlist(&pCourses[iCourse], &pStudents[k]))
                continue;

              else if (pCourses[iCourse].numStudentsRegistered < pCourses[iCourse].maxStudents){
                enrollInCourses(&pCourses[iCourse], &pStudents[k]);
                break;
              }
              else{
                appendStudentToWaitlist(&pCourses[iCourse], &pStudents[k]);
                break;
            }
          }
        }
      }


/*Print out course Lists with Registered and Waiting Listed Students*/
      for(i = 0; i < 3; i++){
        printf("%s - %s\n%s\nRegistered Students(%d/%d)\n", &pCourses[i].pCourseCode, pCourses[i].pName, pCourses[i].pDescription, pCourses[i].numStudentsRegistered, pCourses[i].maxStudents);
          for(k = 0; k < pCourses[i].numStudentsRegistered; k++){
            printf("%05d - %s, %s\n", pCourses[i].ppRegistered[k]->id, (pCourses[i].ppRegistered[k]->name.lastName), (pCourses[i].ppRegistered[k]->name.firstName));
        }
        printf("Waiting List (%d):\n", pCourses[i].numStudentsWaitlisted);
          for(k = 0; k < pCourses[i].numStudentsWaitlisted; k++){
            printf("%05d - %s, %s\n", pCourses[i].ppWaitlisted[k]->id, (pCourses[i].ppWaitlisted[k]->name.lastName), (pCourses[i].ppWaitlisted[k]->name.firstName));
        }

      }


    int studentId = 1;
    while(studentId != 0){
    printf("Enter a student ID:");
    scanf("%d", &studentId);

/* Loop through the students, find the matching ID, then loop through classes and print where the classes contain the matching student*/
    for(k = 0; k < NUM_OF_STUDENTS; k++){
      if(pStudents[k].id == studentId){
        printf("%s, %s is registered for:\n", pStudents[k].name.lastName, pStudents[k].name.firstName);
          for(j = 0; j < 3; j++){
            for(i = 0; i < pCourses[j].numStudentsRegistered; i++){
              if(&pStudents[k] == pCourses[j].ppRegistered[i]){
                printf("%s - %s\n", &pCourses[j].pCourseCode, pCourses[j].pName);
          }
        }
      }
    }
  }
}

    free(pCourses);
    free(pStudents);

    return 0;

  }
