output: gradecard.o
	gcc gradecard.o -o output

gradecard.o: gradecard.c Calculate_grade.o Student_Entry.o
	gcc -c gradecard.c

Calculate_grade.o: Calculate_grade.c
	gcc -c Calculate_grade.c

Student_Entry.o: Student_Entry.c
	gcc -c Student_Entry.c

clean:
	rm *.o

clean2:
	rm output