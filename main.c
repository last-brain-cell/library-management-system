#include <stdio.h>
#include <string.h>
#include "headers/library.h"
#include "headers/logsystem.h"
#include "headers/login.h"

int main() {
    struct Library library;
    library.num_books = 0;

    struct LogSystem log_system;
    log_system.num_logs = 0;

    struct UserDB users;
    users.num_users = 0;

    int book_ids = 1;

    signUp(&users, "Naad", "1234");
    signUp(&users, "user2", "password2");
    signUp(&users, "user3", "password3");

    int flag;
    auth: flag = auth(users);

    printf("--------------------------------------\n");
    printf("\tLIBRARY MANAGEMENT\n");
    printf("--------------------------------------\n");
    printf("\n1: Check in book\n2: Return book\n3: Display logs\n4: Insert Book into Library\n5: Check Availability of a Book\n6: Display Library\n7: Sign Out\n0: Exit\n\n");
    printf("--------------------------------------\n");

    while (1) {
        int command;
        printf("Enter Command: ");
        scanf("%d", &command);

        switch (command) {
            case 1: {
                printf("\nEnter book ID to check out: ");
                int book_id;
                scanf("%d", &book_id);
                check_out_book(&library, &log_system, book_id);
                break;
            }
            case 2: {
                printf("\nEnter book ID to return: ");
                int book_id;
                scanf("%d", &book_id);
                return_book(&library, &log_system, book_id);
                break;
            }
            case 3: {
                display_logs(&log_system);
                break;
            }
            case 4: {
                char book_name[100];
                char author[100];
                int pages;
                getchar();  // Consume the newline character left in the buffer
                printf("\nEnter book name: ");
                fgets(book_name, sizeof(book_name), stdin);
                printf("\nEnter book author: ");
                fgets(author, sizeof(author), stdin);
                printf("\nEnter number of pages: ");
                scanf("%d", &pages);

                struct Book book;
                book.id = book_ids;
                strcpy(book.name, book_name);
                strcpy(book.author, author);
                book.pages = pages;
                book.available = true;
                insert_book(&library, &log_system, book);
                book_ids++;

                break;
            }
            case 5: {
                printf("\nEnter book ID to check availability: ");
                int book_id;
                scanf("%d", &book_id);
                check_availability(&library, &log_system, book_id);
                break;
            }
            case 6: {
                display_library(&library, &log_system);
                break;
            }
            case 7: {
                goto auth;
            }
            case 0:
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }
        printf("\n--------------------------------------\n");
    }

    end: return 0;
}