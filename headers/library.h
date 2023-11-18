#ifndef LIBRARY_H
#define LIBRARY_H

#include "logsystem.h"

#define MAX_BOOKS 100

struct Book {
    int id;
    char name[100];
    char author[100];
    int pages;
    bool available;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};

void insert_book(struct Library *library, struct LogSystem *log_system, struct Book book);
void check_out_book(struct Library *library, struct LogSystem *log_system, int book_id);
void return_book(struct Library *library, struct LogSystem *log_system, int book_id);
void display_library(struct Library *library, struct LogSystem *log_system);
void check_availability(struct Library *library, struct LogSystem *log_system, int book_id);

#endif