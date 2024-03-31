#include <stdio.h>
#include <conio.h>
#include "Calculate_grade.c"
void main()
{
    int num_students, choice;
    int num_subjects = 3;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

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
            Student_input(num_students, num_subjects);
            printf("\n");
            break;
        case 2:
            Cal_grade(num_students);
            printf("\n");
            break;
        case 3:
            break;
        default:
            printf("Enter a valid choice.\n");
        }
    }
}