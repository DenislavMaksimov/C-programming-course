#ifndef PROCESSES
#define PROCESSES

#define MAX_PROCESSES 5
#define PROCESS_NAME_LENGTH 30

struct processes{
    int id;
    char name[PROCESS_NAME_LENGTH]
}
    
extern Process processes[MAX_PROCESSES];
extern int processcount;

int createnewprocess(const char* name);
void stopprocess(int id);
void printprocesses();

#endif
