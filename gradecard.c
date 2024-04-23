#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "full.h"
int num_students;
int main()
{
    int choice;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    student *s = (student *)malloc(num_students * sizeof(student));
    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    while (choice != 3)
    {
        printf("1.Adding student details\n");
        printf("2.Calculating Grades\n");
        printf("3.To exit\n");
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
            printf("| %-20s | %-10s |", "Name", "Roll No");
            for (int i = 0; i < num_subjects; i++)
            {
                printf(" %-7s |", "Subject");
                printf(" %-7s |", "Average");
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
            break;
        case 4:
            printf("Exiting program.\n");
            free(s);
            return 0;
        default:
            printf("Enter a valid choice.\n");
        }
    }
    free(s);
    return 0;
}