#include <stdio.h>
#include <conio.h>
#include "full.h"
void Cal_grade(student *s, int num_students)
{
    for (int i = 0; i < num_subjects; i++)
    {
        float average = s->subjectAvg[i];
        if (average >= 90)
            s->grades[i] = 'S';
        else if (average >= 80)
            s->grades[i] = 'A';
        else if (average >= 70)
            s->grades[i] = 'B';
        else if (average >= 60)
            s->grades[i] = 'C';
        else if (average >= 50)
            s->grades[i] = 'D';
        else if (average >= 40)
            s->grades[i] = 'E';
        else
            s->grades[i] = 'F';
    }
    printf("| %-20s | %-10d | %-9d |", s->name, s->roll_num, s->sem);
    for (int j = 0; j < num_subjects; j++)
    {
        // printf(" %-7d |", j + 1);              // Subject number
        printf(" %-9.2f |", s->subjectAvg[j]); // Average marks for the subject
        printf(" %-6c |", s->grades[j]);       // Grade for the subject
    }
}