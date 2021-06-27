#include "../header.h"

void add_teacher()
{
    teacher tch;
    printf("Enter Teacher's Username, First name, Last name & Password: (Spearate thorugh space) \n");
    fflush(stdout);
    scanf("%s", tch.username);
    scanf("%s", tch.firstname);
    scanf("%s", tch.lastname);
    scanf("%s", tch.password);
    FILE *fp = fopen("txt/teacher.txt", "a");
    fwrite(&tch, sizeof(teacher), 1, fp);
    fflush(fp);
    fclose(fp);
}

void add_student()
{
    student std;
    printf("\nStudent's Username , First name, Last name & password:(Separate thorugh space) \n");
    fflush(stdout);
    scanf("%s", std.username);
    scanf("%s", std.firstname);
    scanf("%s", std.lastname);
    scanf("%s", std.password);
    FILE *fp = fopen("txt/student.txt", "a");
    fwrite(&std, sizeof(student), 1, fp);
    fflush(fp);
    fclose(fp);
}

//Show all the teachers information
void show_teacher()
{
    FILE *fp;
    teacher teach;
    fp = fopen("txt/teacher.txt", "r");
    printf("Username\tFirst Name\tLast Name\tPassword\n");
    printf("________\t_________\n\n");
    while (fread(&teach, sizeof(teacher), 1, fp))
    {
        printf("%s \t", teach.username);
        printf("%20s", teach.firstname);
        printf("%20s", teach.lastname);
        printf("%20s", teach.password);
        printf("\n");
    }
    fclose(fp);
}

//show all the students informations
void show_students()
{
    FILE *fp;
    student stud;
    fp = fopen("txt/student.txt", "r");
    printf("Username \t First name \t Last name \t Password\n\n");
    while (fread(&stud, sizeof(student), 1, fp))
    {
        printf("%s \t", stud.username);
        printf("%s\t", stud.firstname);
        printf("%s\t", stud.lastname);
        printf("%s\t\n", stud.password);
    }
    fclose(fp);
}

//Assing Courses
void add_courses()
{
    courses crs;
    printf("Teacher's Username and Course name:\n");
    fflush(stdout);
    scanf("%s %s", crs.teacher_username, crs.course_name);
    FILE *fp = fopen("txt/courses.txt", "a");
    fwrite(&crs, sizeof(courses), 1, fp);
    fflush(fp);
    fclose(fp);
}

void view_all_courses()
{
    courses crs;
    FILE *fp;
    fp = fopen("txt/courses.txt", "r");
    while (fread(&crs, sizeof(courses), 1, fp))
    {
        printf("%s\t", crs.teacher_username);
        printf("%s \n", crs.course_name);
    }
    fclose(fp);
}

//Update teacher's information
void update_teacher()
{
    teacher tc;
    printf("Please enter the username of the teacher you want to update: ");
    scanf("%s", tc.username);
    FILE *fp;
    teacher tch;
    fp = fopen("txt/teacher.txt", "r");
    int teacherFound = 0;
    while (fread(&tch, sizeof(teacher), 1, fp))
    {
        if (!strcmp(tc.username, tch.username))
        {
            teacherFound++;
            printf("Frist name, Lastname and password (Please separate through space): ");
            scanf("%s %s %s", tch.firstname, tch.lastname, tch.password);
            fwrite(&tch, sizeof(teacher), 1, fp);
            fflush(fp);
        }
    }
    if (!teacherFound)
    {
        printf("\n\n___ NO TEACHER WITH THIS USERNAME ___\n\n");
    }
    fclose(fp);
}