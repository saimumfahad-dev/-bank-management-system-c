
<h1 align="center">Bank Management System</h1>

<p align="center">
  <strong>A console-based banking simulator built with C.</strong><br />
  An academic project exploring account management, transactions, and persistent file storage.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-0F766E?style=flat-square&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Interface-CLI-17252A?style=flat-square" alt="Command line" />
  <img src="https://img.shields.io/badge/Storage-Binary%20Files-0F766E?style=flat-square" alt="Binary files" />
  <img src="https://img.shields.io/badge/Type-Academic%20Project-263238?style=flat-square" alt="Academic project" />
</p>

<p align="center">
  <a href="#overview">Overview</a> ·
  <a href="#features">Features</a> ·
  <a href="#getting-started">Getting Started</a> ·
  <a href="#project-structure">Source</a>
</p>

---

## Overview

**Bank Management System** is a menu-driven C application that simulates basic banking operations. It was developed as an academic programming project to practice structured programming, user-defined structures, account workflows, and binary file handling.

The program runs locally in the terminal. It is designed for learning, not real financial transactions.

## Features

| Area | Implemented functionality |
| --- | --- |
| Account setup | Register using an account number, phone number, and password |
| Account access | Log in using the registered phone number and password |
| Balance | View the current account balance |
| Transactions | Deposit and withdraw funds, with insufficient-balance checking |
| Account settings | Change the account password |
| Persistence | Save and load account data locally using binary `.dat` files |

## Technologies & Concepts

<p>
  <img src="https://skillicons.dev/icons?i=c&theme=dark" alt="C programming language" height="44" />
</p>

- **Language:** C
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`
- **IDE used:** Code::Blocks
- **Concepts:** structures, functions, conditional logic, loops, switch statements, string operations, and binary file I/O

## Getting Started

### Requirements

- A C compiler such as GCC, or Code::Blocks configured with a C compiler
- A terminal or command prompt

### Build and run with GCC

Open a terminal in the folder containing `main.c`.

**Windows:**

```bash
gcc main.c -o bank-management-system.exe
.\bank-management-system.exe
```

**Linux/macOS:**

```bash
gcc main.c -o bank-management-system
./bank-management-system
```

Alternatively, open `main.c` in Code::Blocks and build and run the program there.

### Basic usage

1. Run the application and choose **Register an account**.
2. Enter the requested account number, phone number, and password.
3. Restart or return to the login option and sign in using the registered details.
4. Use the account menu to check the balance, deposit, withdraw, or update the password.

The program stores account information in local `.dat` files so account data can persist between runs. Keep those runtime files out of your public repository.

## Project Structure

```text
bank-management-system-c/
├── main.c          # Main application source
├── README.md       # Project documentation
└── .gitignore      # Files excluded from Git
```

## What I Practiced

- Modeling account information using C structures
- Building menu-driven flows with conditions and loops
- Working with user input and basic transaction checks
- Reading and writing persistent binary files
- Organizing and documenting an academic C project

## Limitations & Next Steps

This project uses local files and a console interface. It does **not** provide production-grade authentication, encryption, transaction auditing, or secure banking infrastructure. Do not use real account credentials or financial data.

Potential future improvements include stronger input validation, more modular source files, better error handling, and automated tests.

---

<p align="center">
  <a href="https://github.com/saimumfahad-dev">GitHub Profile</a> ·
  <a href="https://www.linkedin.com/in/md-saimum-islam-fahad/">LinkedIn</a>
  <br />
  <sub>Built for learning · Code · Build · Learn</sub>
</p>
