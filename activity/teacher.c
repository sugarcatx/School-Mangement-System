#include "../header.h"

//Set class test mark
void provide_mark()
{
    marks mark;
    printf("The username of the student: ");
    scanf("%s", mark.username);
    student stud;
    FILE *fp = fopen("txt/student.txt", "r");
    int username_verified = 0;
    while (fread(&stud, sizeof(student), 1, fp))
    {
        if (!strcmp(mark.username, stud.username))
        {
            username_verified = 1;
        }
    }

    //if the username is available
    if (username_verified > 0)
    {
        printf("Suject: ");
        scanf("%s", mark.subject);
        printf("Mark: ");
        scanf("%d", mark.marks);
        FILE *marksfile = fopen("txt/marks.txt", "a");
        fwrite(&mark, sizeof(marks), 1, marksfile);
        fflush(marksfile);
        fclose(marksfile);
    }
    else
    {
        printf("\n _______ USERNAME NOT FOUND _______ \n");
    }

    fclose(fp);
}

//Find students by first name

void find_student()
{
    char fname[100];
    printf("First name to search: ");
    scanf("%s", &fname);
    FILE *fp;
    student stud;
    fp = fopen("txt/student.txt", "r");
    int studentFounds = 0;
    while (fread(&stud, sizeof(student), 1, fp))
    {
        if (!strcmp(stud.firstname, fname))
        {
            studentFounds++;
            printf("\nUsername: %s \t", stud.username);
            printf("Firstname: %s \t", stud.firstname);
            printf("Lastname: %s \t", stud.lastname);
            printf("\n__________________________________\n\n");
        }
    }
    if (studentFounds > 0)
    {
        printf("\n %d Students found\n\n", studentFounds);
    }
    else
    {
        printf("No students found\n\n");
    }
    fclose(fp);
}

//Count the number of students
void count_students()
{
    FILE *fp;
    student stud;
    fp = fopen("txt/student.txt", "r");
    int studentFounds = 0;
    while (fread(&stud, sizeof(student), 1, fp))
    {
        studentFounds++;
    }
    printf("\n\n\t\tTotal %d students\n\n", studentFounds);
}