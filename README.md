Bank Management System in C
A console-based bank account management program developed in C as an academic programming project. It demonstrates structured programming, user-defined structures, menu-driven interactions, and binary file handling.
Features
- Register an account using an account number, phone number, and password.
- Log in using the registered phone number and password.
- Check the current account balance.
- Deposit money into an account.
- Withdraw money, with a check for insufficient funds.
- Change the account password.
- Save account information locally between program runs using binary .dat files.
Technologies and concepts
- Language: C
- Libraries: stdio.h, string.h, stdlib.h
- Concepts: struct, file I/O, conditionals, loops, switch statements, and basic string operations
- Interface: Command-line / console
Getting started
Requirements
A C compiler such as GCC, or an IDE such as Code::Blocks with a configured C compiler.
Compile and run
On Windows with GCC:
gcc main.c -o bank-management-system.exe
Then run bank-management-system.exe from the project folder.

Alternatively, open main.c in Code::Blocks and build and run it as a C console program.
How to use
1. Start the program and choose Register an account to create an account.
2. Enter an account number, phone number, and password.
3. Run the program again and choose Login to account.
4. After logging in, choose balance inquiry, deposit, withdrawal, password change, or exit from the menu.
Data storage
Each registered account is written to a binary file named after the phone number, for example 01700000000.dat, in the current working directory. The file stores account details and the current balance.

Do not commit generated .dat files: they may contain account identifiers and plaintext passwords. Use fictional details only when testing.
Known limitations
This project was created for learning purposes and is not suitable for real banking operations.
- Passwords are stored without hashing or encryption.
- Input lengths and numeric values are not fully validated; negative amounts can lead to incorrect transactions.
- Registration can overwrite an existing account file with the same phone number.
- File read/write operations and errors are not consistently checked.
- Some screen-clearing calls use cls, making parts of the interface Windows-specific.
- The program uses binary structures and is not a networked, multi-user banking system.
Possible improvements
- Validate user input and reject zero or negative transaction amounts.
- Prevent duplicate account registration.
- Improve file error handling and portability.
- Separate the program into smaller functions.
- Replace plaintext password storage with a more secure authentication approach.
Purpose
An academic demonstration of C programming fundamentals and local file-based data management.
