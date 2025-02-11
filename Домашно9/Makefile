all: taskmanager.exe

taskmanager.exe: processes.o taskmanager.o
	gcc -o taskmanager.exe processes.o taskmanager.o

processes.o: processes.c processes.h
	gcc -c processes.c

taskmanager.o: taskmanager.c processes.h
	gcc -c taskmanager.c

clean:
	rm -f *.o taskmanager.exe
	