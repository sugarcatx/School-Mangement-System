#include "header.h"

int main()
{
	printf("1. ADMIN \n 2. TEACHER \n 3. STUDENT \n");
	int cas;
	scanf("%d", &cas);
	// according to user input call function

	if (cas == 1)
	{
		dashboard_admin();
	}
	else if (cas == 2)
	{
		teacher_panel_opearation();
	}
	else
	{
		student_authentication();
	}

	return 0;
}
