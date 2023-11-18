#include "../headers/login.h"
#include <stdio.h>
#include <string.h>

bool signUp(struct UserDB *users, const char *username, const char *password) {
    if (users->num_users < MAX_USERS) {
        struct User newUser;
        strncpy(newUser.username, username, MAX_USERNAME_LENGTH - 1);
        newUser.username[MAX_USERNAME_LENGTH - 1] = '\0'; // Ensure null-terminated
        strncpy(newUser.password, password, MAX_PASSWORD_LENGTH - 1);
        newUser.password[MAX_PASSWORD_LENGTH - 1] = '\0'; // Ensure null-terminated

        users->users[users->num_users++] = newUser;
        return true;
    } else {
        return false;
    }
}


bool login(struct UserDB *users, const char *username, const char *password) {
    for (int i = 0; i < users->num_users; ++i) {
        if (strcmp(users->users[i].username, username) == 0 &&
            strcmp(users->users[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}


int auth(struct UserDB users){
    auth:
    printf("\n--------------------------------------\n");
    printf("\tUSER AUTHENTICATION\n");
    printf("--------------------------------------\n");
    printf("\n1: Sign up\n2: Log in\n0: Exit\n\n");
    printf("--------------------------------------\n");

    int authCommand;
    printf("Enter Command: ");
    scanf("%d", &authCommand);

    switch (authCommand) {
        case 1: {
            char newUsername[MAX_USERNAME_LENGTH];
            char newPassword[MAX_PASSWORD_LENGTH];

            printf("\nEnter new username: ");
            scanf("%s", newUsername);
            printf("\nEnter new password: ");
            scanf("%s", newPassword);

            if (signUp(&users, newUsername, newPassword)) {
                printf("Sign up successful!\n");
            } else {
                printf("User database is full. Cannot sign up.\n");
            }
            break;
        }
        case 2: {
            char enteredUsername[MAX_USERNAME_LENGTH];
            char enteredPassword[MAX_PASSWORD_LENGTH];

            printf("\nEnter username: ");
            scanf("%s", enteredUsername);
            printf("\nEnter password: ");
            scanf("%s", enteredPassword);

            if (login(&users, enteredUsername, enteredPassword)) {
                printf("Login successful!\n");
            } else {
                printf("Incorrect username or password. Please try again.\n");
                goto auth;
            }
            break;
        }
        case 0:
            return 0;
        default:
            printf("Invalid command. Please try again.\n");
    }
    return -1;
}
