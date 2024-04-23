#define num_subjects 3
#define num_assessments 3
typedef struct
{
    char grades[num_subjects];
    char name[100];
    int roll_num;
    int sem;
    int marks[num_subjects][num_assessments];
    float subjectAvg[num_subjects];
} student;
extern int num_students;
void Student_input(student *s);
void Cal_grade(student *s, int num_students);