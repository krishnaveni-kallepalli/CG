#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_EMPLOYEES 100
struct employee
{
        char name[100];
        char ID[5];
        char designation[20];
        char status[10];
        char activity[10];
};
struct employee emps[MAX_EMPLOYEES];
int nEmp=0;
void addEmployee()
{
        if(nEmp < MAX_EMPLOYEES)
        {
        struct employee emp;
        printf("Enter name:");
        fgets(emp.name,sizeof(emp.name),stdin);
        emp.name[strcspn(emp.name,"\n")] = '\0';

        printf("Enter empID:");
        fgets(emp.ID,sizeof(emp.ID),stdin);
        emp.ID[strcspn(emp.ID,"\n")] = '\0';

	printf("Enter Designation:");
	fgets(emp.designation, sizeof(emp.designation), stdin);
	emp.designation[strcspn(emp.designation,"\n")] = '\0';

	printf("Enter Status(Active/Resigned):");
	fgets(emp.status, sizeof(emp.status), stdin);
	emp.status[strcspn(emp.status,"\n")] = '\0';

	printf("Enter Activity(Bench/Client):");
	fgets(emp.activity, sizeof(emp.activity), stdin);
	emp.activity[strcspn(emp.activity,"\n")] = '\0';
        	
	emps[nEmp++] = emp;
        printf("Employee added successfully.\n");
        }
        else printf("Employee cannot be added.\n");

}

void searchEmployee()
{
        char searchID[5];
        printf("Enter ID to search:");
        fgets(searchID,sizeof(searchID),stdin);
        searchID[strcspn(searchID,"\n")] = '\0';
        int found = 0,i;
        for(i=0;i<nEmp;i++)
        {
                if(strcmp(emps[i].ID,searchID)==0)
                {
                        printf("Employee Found..\n");
                        printf("Name:%s\n",emps[i].name);
                        printf("ID:%s\n",emps[i].ID);
                        printf("Role:%s\n",emps[i].designation);
                        printf("Status:%s\n",emps[i].status);
                        printf("Activity:%s\n",emps[i].activity);
                        found = 1;
                        break;
                }
        }
        if(found == 0) printf("Employee not found..!\n");
}


void printEmployee()
{
        int i;
        for(i=0;i<nEmp;i++)
        {
                printf("Employee Found..\n");
                printf("Name:%s\n",emps[i].name);
                printf("ID:%s\n",emps[i].ID);
		printf("Role:%s\n",emps[i].designation);
                printf("Status:%s\n",emps[i].status);
                printf("Activity:%s\n",emps[i].activity);
        }
}

void disp()
{
        printf("\nEmployee Management System Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Print Employee Details\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("5. Write data to excel sheet\n");
        printf("Enter your choice: ");
}

void writeExcel()
{
        char filename[100];
        scanf(" %s", filename);
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
        {
                printf("Error opening file %s for writing.\n", filename);
                return;
        }
        fprintf(fp, "ID,Name,Designation,Status,Activity\n");
        int i;
        for(i=0;i<nEmp;i++)
        {
                printf("Employee Found..\n");
                printf("Name:%s\n",emps[i].name);
                printf("Name:%s\n",emps[i].ID);
                printf("Name:%s\n",emps[i].designation);
                printf("Name:%s\n",emps[i].status);
                printf("Name:%s\n",emps[i].activity);
        }
        fclose(fp);
        printf("Employee data has been written to %s.\n", filename);

}


int main()
{
        int choice;
        do {
        disp();
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
                case 1:
                addEmployee();
                break;
                case 2:
                printEmployee();
                break;
                case 3:
                searchEmployee();
                break;
                case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
                case 5:
                writeExcel();
                break;
                default:printf("Invalid choice\n");
        }
        }while(choice!=4);

        return 0;
}
