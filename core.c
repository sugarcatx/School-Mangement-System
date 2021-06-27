#include "header.h"

typedef struct teacher
{
    char username[100], firstname[100], lastname[100], password[100];

} teacher;

// marks_of_student of a student in a course no x is marks_of_student[x];
typedef struct student
{
    char username[1000], firstname[100], lastname[100], password[100];

} student;

typedef struct marks
{
    char username[1000];
    char subject[100];
    int marks[10];
} marks;

typedef struct courses
{
    char teacher_username[100];
    char course_name[100];
} courses;

void Log(char msg[])
{
    printf("%s", msg);
}

char *formatter(int space, char *theword)
{
    int len = strlen(theword);
    char *stheword = (char *)malloc((space + 1) * sizeof(char *));
    for (int i = 0; i < space; i++)
    {
        if (i < len)
            stheword[i] = theword[i];
        else
            stheword[i] = ' ';
    }
    stheword[space] = '\0';
    return stheword;
}