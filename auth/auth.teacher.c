#include "../header.h"

int validate_input_for_teacher()
{
    // this function will return 1 if user given user_id and password is found otherwise return 0
    printf("Username and Password (Please separate through space): ");
    fflush(stdout);
    teacher teach;
    scanf("%s", teach.username);
    scanf("%s", teach.password);

    FILE *fp;
    teacher tch;
    fp = fopen("txt/teacher.txt", "r");

    //checking user user_id, password does exist in the file or not
    while (fread(&tch, sizeof(teacher), 1, fp))
    {
        if (!strcmp(teach.username, tch.username) && !strcmp(teach.password, tch.password))
        {
            fclose(fp);
            return 1;
        }
    }

    return 0;
}

void teacher_panel_opearation()
{
    // teacher_panel_opearation
    if (!validate_input_for_teacher())
    {
        printf("Sorry! Wrong user user_id or password\n");
        return;
    }

    while (1)
    {
        printf("\n 1. Provide Class Test Marks \n 2. Find studnets by First Name\n 3. Count Students\n 0. Exit\n");
        printf("What do you want to do?: ");
        int opr;
        scanf("%d", &opr);
        if (!opr)
            return;
        else if (opr == 1)
            provide_mark();
        else if (opr == 2)
            find_student();
        else if (opr == 3)
            count_students();
        else
            printf("Invalid Input");
    }
}
