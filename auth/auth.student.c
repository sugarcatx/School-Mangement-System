#include "../header.h"

void student_authentication()
{

    student std;
    printf("Username and Password:\n\n");
    scanf("%s", std.username);
    scanf("%s", std.password);

    FILE *fp;
    student stud;
    fp = fopen("txt/student.txt", "r");
    //checking user user_id, password does exist in the file or not
    int getCredTrue = 0;
    while (fread(&stud, sizeof(std), 1, fp))
    {
        if (!strcmp(stud.username, std.username) && !strcmp(stud.password, std.password))
        {
            FILE *mks;
            marks mkx;
            mks = fopen("txt/marks.txt", "r");
            while (fread(&mkx, sizeof(marks), 1, mks))
            {
                printf("%s\t %d \n", mkx.subject, mkx.marks[0]);
            }
        }
    }
}
