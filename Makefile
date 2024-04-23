output: gradecard.c Calculate_grade.c Student_Entry.c
	gcc -o output gradecard.c Calculate_grade.c Student_Entry.c
clean:
	rm -f output		