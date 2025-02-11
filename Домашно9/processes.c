#include <stdio.h>
#include "processes.h"
#include <string.h>

Process processes[MAX_PROCESSES];
int processcount = 0;
static int nextprid(void) {
    static int current_id = 1;
    if (current_id > 0) {
        return current_id++;
    }
    return 0; 
}

void listpr(void) {
    if (processcount == 0) {
        printf("No running processes.\n");
    } else {
        for (int i = 0; i < processcount; i++) {
            printf("Process ID: %d, Name: %s\n", processes[i].id, processes[i].name);
        }
    }
}

int createnewpr(const char *name) {
    if (processcount >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return 0;
    }

    int id = nextprid();
    if (id == 0) {
        printf("Error: Process ID range exhausted.\n");
        return 0;
    }

    Process new_process = {id, ""};
    strncpy(new_process.name, name, MAX_PROCESSES_NAME_LENGTH);
    new_process.name[MAX_PROCESSES_NAME_LENGTH] = '\0';

    processes[processcount++] = new_process;
    return id;
}

void stoppr(int id) {
    int index = -1;
    for (int i = 0; i < processcount; i++) {
        if (processes[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: No process found with ID %d.\n", id);
        return;
    }

    for (int i = index; i < processcount - 1; i++) {
        processes[i] = processes[i + 1];
    }

    processcount--;
}

