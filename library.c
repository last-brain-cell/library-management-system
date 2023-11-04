#include "library.h"
#include "logsystem.h"
#include <stdio.h>
#include <string.h>

void insert_book(struct Library *library, struct LogSystem *log_system, struct Book book) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot insert more books.\n");
        add_log(log_system, "Attempted to insert a book into a full library.");
        return;
    }

    library->books[library->num_books++] = book;
    char activity[200];
    sprintf(activity, "Book %d has been inserted into the library.", book.id);
    add_log(log_system, activity);
}

void check_out_book(struct Library *library, struct LogSystem *log_system, int book_id) {
    char activity[200];
    if (library->num_books == 0) {
        printf("Library is Empty, Enter books to check out a book.");
        add_log(log_system, "Attempted to checkout a book when the Library was empty.");
    }

    for (int i = 0; i < library->num_books; i++) {
        if (library->books[i].id == book_id) {
            library->books[i].available = false;
            sprintf(activity, "Book %d has been checked out.", book_id);
            add_log(log_system, activity);
            return;
        }
    }
    add_log(log_system, "Attempted to check in a book not found in the library.");
}

void return_book(struct Library *library, struct LogSystem *log_system, int book_id) {
    for (int i = 0; i < library->num_books; i++) {
        if (library->books[i].id == book_id) {
            if (library->books[i].available) {
                add_log(log_system, "Attempted to return a book that is already available in the library. Book was not available");
            } else {
                library->books[i].available = true;
                char activity[200];
                sprintf(activity, "Book %d has been returned.", book_id);
                add_log(log_system, activity);
            }
            return;
        }
    }
    add_log(log_system, "Attempted to return a book not found in the library.");
}

void display_book(struct Book *book) {
    printf("--------------------------------------\n");
    printf("Book ID: %d\n", book->id);
    printf("Book Name: %s\n", book->name);
    printf("Book Author: %s\n", book->author);
    printf("Book Pages: %d\n", book->pages);
    printf("--------------------------------------\n");
}

void display_library(struct Library *library, struct LogSystem *log_system) {
    printf("--------------------------------------\n");
    printf("\tLIBRARY\n");
    for (int i = 0; i < library->num_books; i++) {
        display_book(&library->books[i]);
    }
    add_log(log_system, "Displayed all the books in the Library.");
}

void check_availability(struct Library *library, struct LogSystem *log_system, int book_id) {
    char activity[200];
    for (int i = 0; i < library->num_books; i++) {
        struct Book book = library->books[i];
        if (book.id == book_id) {
            if (book.available) {
                sprintf(activity, "Availability of Book %d was checked. Book is available", book_id);
                add_log(log_system, activity);
            } else {
                sprintf(activity, "Availability of Book %d was checked. Book is not available", book_id);
                add_log(log_system, activity);
            }
            return;
        }
    }
    add_log(log_system, "Attempted to check the availability of a book not found in the library.");
}
