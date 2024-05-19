#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "full.h"
#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

void get_student_data(char *line, char *fields[], int *num_fields, char *token)
{
    *num_fields = 0;
    while (token != NULL)
    {
        fields[*num_fields] = token;
        (*num_fields)++;
        token = strtok(NULL, ",");
    }
}

void searching(student *s)
{
    FILE *file = fopen("students.csv", "r");
    if (file == NULL)
    {
        perror("Error opening the .csv file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int num_fields;
    int line_number = 0;
    char name_to_search[100];

    printf("Enter the student name to be searched: ");
    scanf("%s", &name_to_search);

    // Read each line from the file
    while (fgets(line, sizeof(line), file))
    {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
        }

        // Compare name in file to search name & fetch data if match is found
        char *token = strtok(line, ",");
        if (strcmp(token, name_to_search) == 0)
        {
            get_student_data(line, fields, &num_fields, token);
            break;
        }

        line_number++;
    }

    // Print the fields
    char *field_names[] = {"Name", "Roll No.", "Semester", "Subject 1", "Grade", "Subject 2", "Grade", "Subject 3", "Grade"};
    for (int i = 0; i < num_fields; i++)
    {
        printf("%s: %s\n", field_names[i], fields[i]);
    }

    // Close the file
    fclose(file);
}
