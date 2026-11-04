#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user {
    char phone[50];
    char account[50];
    char password[50];
    double balance;
} user;

int main() {
    user usr;
    FILE *fp;
    char fileName[50], phone[50], password[50];
    int opt, choice;
    char cont = 'y';
    double amount;

    printf("\nLog in Screen");
    printf("\n_________________________");
    printf("\n\n1. Register an account");
    printf("\n2. Login to account");

    printf("\n\nYour choice: ");
    scanf("%d", &opt);

    if (opt == 1) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("Enter your account number: \t");
        scanf("%s", usr.account);
        printf("Enter your phone number: \t");
        scanf("%s", usr.phone);
        printf("Enter your password: \t\t");
        scanf("%s", usr.password);
        usr.balance = 0;

        strcpy(fileName, usr.phone);
        fp = fopen(strcat(fileName, ".dat"), "wb");

        if (fp == NULL) {
            printf("\nError creating account file!");
            return 1;
        }

        if (fwrite(&usr, sizeof(user), 1, fp) == 1) {
            printf("\n\nAccount successfully registered");
        } else {
            printf("\n\nSomething went wrong, please try again");
        }
        fclose(fp);
    }

    else if (opt == 2) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\nPhone number: \t");
        scanf("%s", phone);
        printf("Password: \t");
        scanf("%s", password);

        strcpy(fileName, phone);
        fp = fopen(strcat(fileName, ".dat"), "rb");

        if (fp == NULL) {
            printf("\nAccount number not registered");
        } else {
            fread(&usr, sizeof(user), 1, fp);
            fclose(fp);

            if (!strcmp(password, usr.password)) {
                printf("\n\tWelcome %s", usr.phone);

                while (cont == 'y') {
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif

                    printf("\n\n Press 1 to Balance Inquiry");
                    printf("\n Press 2 to Deposit");
                    printf("\n Press 3 to Withdraw");
                    printf("\n Press 4 to Change password");
                    printf("\n Press 5 to Exit");

                    printf("\n\nYour choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            system("cls");
                            printf("\nYour Current Balance is TK. %.2lf", usr.balance);
                            break;

                        case 2:
                            system("cls");
                            printf("\nEnter the Amount: ");
                            scanf("%lf", &amount);
                            usr.balance += amount;

                            fp = fopen(fileName, "wb");
                            fwrite(&usr, sizeof(user), 1, fp);
                            fclose(fp);
                            printf("\nSuccessfully Deposited");
                            break;

                        case 3:
                            system("cls");
                            printf("\nEnter the Amount: ");
                            scanf("%lf", &amount);
                            if (amount > usr.balance) {
                                printf("\nInsufficient Balance");
                            } else {
                                usr.balance -= amount;
                                fp = fopen(fileName, "wb");
                                fwrite(&usr, sizeof(user), 1, fp);
                                fclose(fp);
                                printf("\nYou have Withdrawn TK. %.2lf successfully", amount);
                            }
                            break;

                        case 4:
                            system("cls");
                            printf("\nPlease enter a new password: \t");
                            scanf("%s", password);
                            strcpy(usr.password, password);
                            fp = fopen(fileName, "wb");
                            fwrite(&usr, sizeof(user), 1, fp);
                            fclose(fp);
                            printf("\nPassword Changed Successfully");
                            break;

                        case 5:

                            #ifdef _WIN32
                                system("cls");
                            #else
                                system("clear");
                            #endif
                            printf("Thank you for choosing our bank");
                            return 0;

                        default:
                            printf("\nInvalid Option");
                            break;
                    }

                    printf("\n\nDo you want to continue the transaction? [y/n]: ");
                    scanf(" %c", &cont);
                }
            } else {
                printf("\nInvalid password");
            }
        }
    }

    return 0;
}
