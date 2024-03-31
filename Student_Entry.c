#include <stdio.h>
#include <conio.h>
char name[100][100];
int roll_num[100];
int sem[100];
int exam1[100][100], exam2[100][100], exam3[100][100];
int internal1[100], internal2[100], internal3[100];
int i, subjects;
float subjectAvg[100][3];
void Student_input(int n, int subjects)
{
    for (i = 0; i < n; i++)
    {
        printf("Enter student %d name: ", (i + 1));
        scanf("%s", &name[i]);
        printf("Enter student %d roll number: ", (i + 1));
        scanf("%d", &roll_num[i]);
        printf("Enter student %d Semester: ", (i + 1));
        scanf("%d", &sem[i]);
        for (int j = 0; j < subjects; j++)
        {
            printf("Enter %s's subject %d Assessment 1 marks: ", name[i], (j + 1));
            scanf("%d", &exam1[i][j]);
            subjectAvg[i][j] += exam1[i][j];

            printf("Enter %s's subject %d Assessment 2 marks: ", name[i], (j + 1));
            scanf("%d", &exam2[i][j]);
            subjectAvg[i][j] += exam2[i][j];

            printf("Enter %s's subject %d Assessment 3 marks: ", name[i], (j + 1));
            scanf("%d", &exam3[i][j]);
            subjectAvg[i][j] += exam3[i][j];

            subjectAvg[i][j] /= 3.0;
            printf("\n");
        }
        printf("\n");
    }

    printf("Displaying average marks in each subject\n");
    printf("%-15s %-8s %-8s %-12s %-12s %-12s\n", "Name", "Roll No.", "Sem", "Subject 1", "Subject 2", "Subject 3");
    for (i = 0; i < n; i++)
    {
        printf("%-15s %-8d %-8d %-12.2f %-12.2f %-12.2f\n", name[i], roll_num[i], sem[i], subjectAvg[i][0], subjectAvg[i][1], subjectAvg[i][2]);
    }
}