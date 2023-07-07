#include <stdio.h>
#include <string.h>
#define MAX 100

struct student_record
{
    char name[20], date_birth[20];
    int id, enrol;
    struct date
    {
        int day, month, year;
    }d; // inner structure variable declaration is compulsory.
};

int main()
{
    int n, i;
    struct student_record rec[MAX];

    scanf("%d",&n);
    fflush(stdin);
    for(i=0; i<n; i++)
    {
        fgets(rec[i].name, 20, stdin);
        scanf("%d %d",&rec[i].id, &rec[i].enrol);
        scanf("%d %d %d",&rec[i].d.day, &rec[i].d.month, &rec[i].d.year);
        fflush(stdin);
        fgets(rec[i].date_birth, 20, stdin);
        // fflush(stdin);
    }

    for(i=0; i<n; i++)
    {
        printf("Name: %s\n",rec[i].name);
        printf("SAP ID: %d\nEnrollment Number: %d\n",rec[i].id,rec[i].enrol);
        printf("Date of registration: %d/%d/%d\n",rec[i].d.day, rec[i].d.month, rec[i].d.year);
        printf("Date of birth: %s\n",rec[i].date_birth);
    }

    return 0;
}