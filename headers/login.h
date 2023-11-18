#ifndef LOGIN_H
#define LOGIN_H

#include "logsystem.h"

#define MAX_USERS 20
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct UserDB {
    struct User users[MAX_USERS];
    int num_users;
};

bool signUp(struct UserDB *users, const char *username, const char *password);
bool login(struct UserDB *users, const char *username, const char *password);
int auth(struct UserDB users);

#endif //LOGIN_H
