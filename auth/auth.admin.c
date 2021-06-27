#include "../header.h"

void dashboard_admin()
{
    char username[1000], password[1000];
    printf("Username and Password: ");
    scanf("%s %s", &username, &password);

    //If username and password match, do nothing.
    //Else revoke the access inside the function
    if (!strcmp("root", username) && !strcmp("empty", password))
    {
        fflush(stdout);
    }
    else
    {
        return;
    }

    while (1)
    {
        int operation;

        printf("\n\n");
        printf("1. Add Teacher\n");
        printf("2. Add Student\n");
        printf("3. View Teachers\n");
        printf("4. View Students\n");
        printf("5. Assign Courses\n");
        printf("6. View All Courses\n");
        printf("7. Update Teacher's Information\n");
        printf("0. Exit\n");
        printf("\nPlease select what you want to do: ");

        scanf("%d", &operation);
        if (!operation)
            return;
        if (operation == 1)
            add_teacher();
        else if (operation == 2)
            add_student();
        else if (operation == 3)
            show_teacher();
        else if (operation == 4)
            show_students();
        else if (operation == 5)
            add_courses();
        else if (operation == 6)
            view_all_courses();
        else if (operation == 7)
            update_teacher();

        else
            Log("Invalid Input");
    }
}
