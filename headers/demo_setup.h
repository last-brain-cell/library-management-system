#ifndef DEMO_SETUP_H
#define DEMO_SETUP_H

#include "library.h"

typedef struct {
    char book_names[MAX_BOOKS];
    char authors[MAX_BOOKS];
} DemoData;

extern DemoData demoData;

void add_demo_data(struct UserDB *users, struct Library *library, struct LogSystem *log_system, struct Book book);
void run_demo();

#endif //DEMO_SETUP_H
