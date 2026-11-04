
# Bank Management System in C

A console-based banking application developed in C as an academic programming project.

The application demonstrates structured programming, user-defined structures, conditional statements, and binary file handling.

## Features

- Account registration with account number, phone number, and password
- Login authentication using phone number and password
- Account balance inquiry
- Deposit money into an account
- Withdraw money with insufficient-balance checking
- Change account password
- Save account information locally using binary files

## Technologies Used

- **Language:** C
- **Libraries:** stdio.h, stdlib.h, string.h
- **Concepts:** Structures, file handling, conditional statements, loops, and switch-case

## How to Run

### Requirements

- GCC compiler or Code::Blocks IDE
- Windows operating system recommended

### Using GCC

Compile the program:

~~~bash
gcc main.c -o bank-management-system.exe
~~~

Run it:

~~~powershell
.\bank-management-system.exe
~~~

Alternatively, open `main.c` in Code::Blocks and build and run the program.

## How to Use

1. Launch the application.
2. Select **Register an account**.
3. Enter your account number, phone number, and password.
4. Restart the application and select **Login to account**.
5. Access the banking menu to:
   - Check your balance
   - Deposit money
   - Withdraw money
   - Change your password
   - Exit

## Data Storage

Account information is stored in local binary `.dat` files named after registered phone numbers.

These files contain account information, including passwords and balances, and should not be uploaded to a public repository.

## Known Limitations

- Passwords are stored without encryption or hashing.
- Negative transaction amounts are not currently rejected.
- Input validation and file error handling are limited.
- Some screen-clearing commands are Windows-specific.

**Note:** This project is intended for educational purposes only and should not be used for real banking operations.

## Author

**Md Saimum Islam Fahad**

Computer Science & Engineering Undergraduate  
North South University

[LinkedIn](https://www.linkedin.com/in/md-saimum-islam-fahad/)
