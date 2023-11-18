#include "../headers/logsystem.h"
#include <stdio.h>
#include <string.h>

void add_log(struct LogSystem *log_system, char *activity) {
    strcpy(log_system->logs[log_system->num_logs++].activity, activity);
}

void display_logs(struct LogSystem *log_system) {
    printf("--------------------------------------\n");

    printf("\tActivity Logs\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < log_system->num_logs; i++) {
        printf("%s\n", log_system->logs[i].activity);
    }
}
