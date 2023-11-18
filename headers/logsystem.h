#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#define MAX_LOGS 1000

struct Log {
    char activity[200];
};

struct LogSystem {
    struct Log logs[MAX_LOGS];
    int num_logs;
};

void add_log(struct LogSystem *log_system, char *activity);
void display_logs(struct LogSystem *log_system);

#endif
