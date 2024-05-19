#include <stdio.h>
#include <conio.h>
#include "full.h"
void Student_input(student *s)
{
    printf("Enter roll number: ");
    scanf("%d", &s->roll_num);
    printf("Enter name: ");
    scanf("%s", &s->name);
    printf("Enter semester: ");
    scanf("%d", &s->sem);
    for (int i = 0; i < num_subjects; i++)
    {
        printf("Enter subject %d marks:\n", (i + 1));
        for (int j = 0; j < num_assessments; j++)
        {
            printf("Assessment %d: ", (j + 1));
            scanf("%d", &s->marks[i][j]);
        }
    }
    for (int i = 0; i < num_subjects; i++)
    {
        float sum = 0;
        for (int j = 0; j < num_assessments; j++)
        {
            sum += s->marks[i][j];
        }
        s->subjectAvg[i] = sum / num_assessments;
    }
}