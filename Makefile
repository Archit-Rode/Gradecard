output: gradecard.c Calculate_grade.c Student_Entry.c Search.c
	gcc -o output gradecard.c Calculate_grade.c Student_Entry.c Search.c
clean:
	rm -f output		