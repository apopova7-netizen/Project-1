Project1: main.o
	gcc main.o  -o Project1

main_project_student1.o: main.c
	gcc -c main.c -o main.o

clean:
	rm Project1 *.o