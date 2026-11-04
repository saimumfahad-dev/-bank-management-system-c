#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct user {
    char phone[50];
    char account[50];
    char password[50];
    double balance;
} user;

int saveAccount(char fileName[], user *usr) {
    FILE *fp = fopen(fileName, "wb");
    int saved;

    if (fp == NULL) {
        return 0;
    }

    saved = fwrite(usr, sizeof(user), 1, fp) == 1;
    if (fclose(fp) != 0) {
        saved = 0;
    }
    return saved;
}

int validPhone(char phone[]) {
    int i;
    for (i = 0; phone[i] != '\0'; i++) {
        if (!isdigit((unsigned char)phone[i])) {
            return 0;
        }
    }
    return i > 0 && i <= 45;
}

int main() {
    user usr;
    FILE *fp;
    char fileName[60], phone[50], password[50], oldPassword[50];
    int opt, choice;
    char cont = 'y';
    double amount, oldBalance;

    printf("\nBank Management System");
    printf("\n_________________________");
    printf("\n1. Register an account");
    printf("\n2. Login to account");
    printf("\n\nYour choice: ");

    if (scanf("%d", &opt) != 1) {
        printf("\nInvalid option.\n");
        return 1;
    }

    if (opt == 1) {
        printf("Enter your account number: ");
        if (scanf("%49s", usr.account) != 1) return 1;
        printf("Enter your phone number: ");
        if (scanf("%45s", usr.phone) != 1) return 1;
        if (!validPhone(usr.phone)) {
            printf("\nPhone number must contain digits only.\n");
            return 1;
        }
        printf("Enter your password: ");
        if (scanf("%49s", usr.password) != 1) return 1;
        usr.balance = 0;

        snprintf(fileName, sizeof(fileName), "%s.dat", usr.phone);
        fp = fopen(fileName, "rb");
        if (fp != NULL) {
            fclose(fp);
            printf("\nAn account with this phone number already exists.\n");
            return 1;
        }

        if (saveAccount(fileName, &usr)) {
            printf("\nAccount successfully registered.\n");
        } else {
            printf("\nError saving account.\n");
            return 1;
        }
    } else if (opt == 2) {
        printf("\nPhone number: ");
        if (scanf("%45s", phone) != 1) return 1;
        if (!validPhone(phone)) {
            printf("\nInvalid phone number.\n");
            return 1;
        }
        printf("Password: ");
        if (scanf("%49s", password) != 1) return 1;

        snprintf(fileName, sizeof(fileName), "%s.dat", phone);
        fp = fopen(fileName, "rb");
        if (fp == NULL) {
            printf("\nAccount not registered.\n");
            return 1;
        }
        if (fread(&usr, sizeof(user), 1, fp) != 1) {
            fclose(fp);
            printf("\nCould not read account data.\n");
            return 1;
        }
        fclose(fp);

        if (strcmp(password, usr.password) != 0) {
            printf("\nInvalid password.\n");
            return 1;
        }

        printf("\nWelcome %s\n", usr.phone);
        while (cont == 'y' || cont == 'Y') {
            printf("\n1. Balance inquiry");
            printf("\n2. Deposit");
            printf("\n3. Withdraw");
            printf("\n4. Change password");
            printf("\n5. Exit");
            printf("\n\nYour choice: ");

            if (scanf("%d", &choice) != 1) {
                printf("\nInvalid option.\n");
                return 1;
            }

            switch (choice) {
                case 1:
                    printf("\nYour current balance is TK %.2f\n", usr.balance);
                    break;
                case 2:
                    printf("\nEnter the amount: ");
                    if (scanf("%lf", &amount) != 1 || !isfinite(amount) || amount <= 0) {
                        printf("\nEnter a valid positive amount.\n");
                        break;
                    }
                    oldBalance = usr.balance;
                    if (!isfinite(oldBalance + amount)) {
                        printf("\nAmount is too large.\n");
                        break;
                    }
                    usr.balance += amount;
                    if (!saveAccount(fileName, &usr)) {
                        usr.balance = oldBalance;
                        printf("\nCould not save the deposit.\n");
                    } else {
                        printf("\nSuccessfully deposited TK %.2f.\n", amount);
                    }
                    break;
                case 3:
                    printf("\nEnter the amount: ");
                    if (scanf("%lf", &amount) != 1 || !isfinite(amount) || amount <= 0) {
                        printf("\nEnter a valid positive amount.\n");
                        break;
                    }
                    if (amount > usr.balance) {
                        printf("\nInsufficient balance.\n");
                        break;
                    }
                    oldBalance = usr.balance;
                    usr.balance -= amount;
                    if (!saveAccount(fileName, &usr)) {
                        usr.balance = oldBalance;
                        printf("\nCould not save the withdrawal.\n");
                    } else {
                        printf("\nSuccessfully withdrawn TK %.2f.\n", amount);
                    }
                    break;
                case 4:
                    printf("\nEnter a new password: ");
                    if (scanf("%49s", password) != 1) return 1;
                    strcpy(oldPassword, usr.password);
                    strcpy(usr.password, password);
                    if (!saveAccount(fileName, &usr)) {
                        strcpy(usr.password, oldPassword);
                        printf("\nCould not save the password change.\n");
                    } else {
                        printf("\nPassword changed successfully.\n");
                    }
                    break;
                case 5:
                    printf("\nThank you for choosing our bank.\n");
                    return 0;
                default:
                    printf("\nInvalid option.\n");
                    break;
            }

            printf("\nDo you want to continue? [y/n]: ");
            if (scanf(" %c", &cont) != 1) return 1;
        }
    } else {
        printf("\nInvalid option.\n");
        return 1;
    }
    return 0;
}
