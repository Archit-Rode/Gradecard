#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "full.h"
// number of subjects has been taken as 3
int num_students;
int main()
{
    int choice;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    FILE *file = fopen("students.csv", "a+");
    if (file == NULL)
    {
        printf("Error opening student data file");
        perror("fopen");
        return 1;
    }
    student *s = (student *)malloc(num_students * sizeof(student));
    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
    while (choice != 4)
    {
        printf("1.Adding student details\n");
        printf("2.Calculating Grades\n");
        printf("3.To search for a student's grades\n");
        printf("4.To exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < num_students; i++)
            {
                Student_input(&s[i]);
                printf("\n");
            }
            break;
        case 2:
            printf("| %-20s | %-10s | %-9s |", "Name", "Roll No", "Sem");
            for (int i = 0; i < num_subjects; i++)
            {
                printf(" %-7s %d |", "Subject", (i + 1));
                // printf(" %-7s |", "Average");
                printf(" %-6s |", "Grade");
            }
            printf("\n");
            for (int i = 0; i < num_students; i++)
            {
                Cal_grade(&s[i], num_students);
                printf("\n");
            }
            break;
        case 3:
            // for (int i = 0; i < num_students; i++)
            // {
            searching(s);
            printf("\n");
            // }
            break;
        case 4:
            printf("Exiting program.\n");
            // exit(0);
            //  for (int i = 0; i < num_students; i++)
            //  {
            //      fprintf(file, "%s,%d,%.2f,%.2f,%.2f\n", s[i].name, s[i].roll_num, s[i].subjectAvg[0], s[i].subjectAvg[1], s[i].subjectAvg[2]);
            //  }
            //  fclose(file);

            // free(s);
            // return 0;
            break;
        default:
            printf("Enter a valid choice.\n");
        }
    }
    for (int i = 0; i < num_students; i++)
    {
        fprintf(file, "%s,%d,%d,%.2f,%c,%.2f,%c,%.2f,%c\n", s[i].name, s[i].roll_num, s[i].sem, s[i].subjectAvg[0], s[i].grades[0], s[i].subjectAvg[1], s[i].grades[1], s[i].subjectAvg[2], s[i].grades[2]);
    }
    fclose(file);

    free(s);
    return 0;
    // FILE file = fopen("test2.csv", "w");

    // fputs("hello", file);
    // free(s);
    // return 0;
}