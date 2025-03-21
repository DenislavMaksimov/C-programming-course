#ifndef PROCESSES_H
#define PROCESSES_H
#define MAX_PROCESSES 5
#define MAX_PROCESSES_NAME_LENGTH 30

typedef struct {
    int id;
    char name[MAX_PROCESSES_NAME_LENGTH + 1];
} Process;

extern Process processes[MAX_PROCESSES];
extern int processcount;
int createnewpr(const char *name);
void stoppr(int id);
void listpr(void);


#endif 
