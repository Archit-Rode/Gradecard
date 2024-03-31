#include <stdio.h>
#include <conio.h>
#include "Student_Entry.c"
void Cal_grade(int num_students)
{
    printf("%-15s %-8s %-8s %-12s %-12s %-12s\n", "Name", "Roll No.", "Sem", "Subject 1", "Subject 2", "Subject 3");
    for (i = 0; i < num_students; i++)
    {
        char grades[3];
        for (int j = 0; j < 3; j++)
        {
            if (subjectAvg[i][j] >= 90)
                grades[j] = 'S';
            else if (subjectAvg[i][j] >= 80)
                grades[j] = 'A';
            else if (subjectAvg[i][j] >= 70)
                grades[j] = 'B';
            else if (subjectAvg[i][j] >= 60)
                grades[j] = 'C';
            else if (subjectAvg[i][j] >= 50)
                grades[j] = 'D';
            else if (subjectAvg[i][j] >= 40)
                grades[j] = 'E';
            else
                grades[j] = 'F';
        }
        printf("%-15s %-8d %-8d %-12c %-12c %-12c\n", name[i], roll_num[i], sem[i], grades[0], grades[1], grades[2]);
    }
}