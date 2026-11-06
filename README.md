
<h1 align="center">✦ Bank Management System ✦</h1>

<p align="center">
  <strong>A console-based banking simulator written in C.</strong><br />
  <sub>Academic project · Structured programming · Binary file storage</sub>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-A77BC4?style=flat-square&labelColor=241B2D&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Interface-Console-8E63AC?style=flat-square&labelColor=241B2D" alt="Console application" />
  <img src="https://img.shields.io/badge/Storage-Binary%20Files-A77BC4?style=flat-square&labelColor=241B2D" alt="Binary file storage" />
  <img src="https://img.shields.io/badge/Project-Academic-8E63AC?style=flat-square&labelColor=241B2D" alt="Academic project" />
</p>

<p align="center">
  <a href="#-overview">Overview</a> ·
  <a href="#-features">Features</a> ·
  <a href="#-technologies--concepts">Tech Stack</a> ·
  <a href="#-getting-started">Getting Started</a> ·
  <a href="#-limitations--future-improvements">Limitations</a>
</p>

---

## ✦ Overview

**Bank Management System** is a menu-driven C program that simulates basic account-management operations. It was built as an academic project to practice C structures, control flow, functions, and persistence using local binary files.

The application runs in a terminal and does **not** connect to a real bank or payment service.

## ◈ Features

| Area | Functionality |
| --- | --- |
| **Account registration** | Register with an account number, phone number, and password |
| **Authentication** | Log in with the registered phone number and password |
| **Balance inquiry** | View the current account balance |
| **Deposit** | Add an entered amount to the account balance |
| **Withdrawal** | Withdraw an entered amount, with an insufficient-funds check |
| **Password change** | Update the account password |
| **Local persistence** | Read and write account records in binary `.dat` files |

## 🛠 Technologies & Concepts

<p>
  <img src="https://skillicons.dev/icons?i=c&theme=dark" alt="C programming language" height="42" />
</p>

- **Language:** C
- **Development environment:** Code::Blocks / GCC
- **Standard headers:** `stdio.h`, `stdlib.h`, `string.h`
- **Core concepts:** structures, functions, loops, conditions, `switch`, strings, and binary file I/O

## ⌘ Getting Started

### Requirements

- A C compiler such as GCC (or Code::Blocks with a configured compiler)
- **Windows is recommended:** parts of the current source use the Windows-specific `cls` command for clearing the console

### Compile and run

Open a terminal in the directory containing `main.c`.

```bash
gcc main.c -o bank-management-system.exe
```

Run it in Windows PowerShell:

```powershell
.\bank-management-system.exe
```

Alternatively, open `main.c` in **Code::Blocks**, then build and run it.

### How to use

1. Start the application and choose **Register an account**.
2. Enter an account number, phone number, and password.
3. Start the application again and choose **Login to account**.
4. After logging in, check the balance, deposit, withdraw, or change the password.
5. The application saves account data in a `.dat` file named after the registered phone number.

Use fictional account details only.

## ▣ Project Structure

```text
bank-management-system-c/
├── main.c         # Application source
├── README.md      # Project documentation
└── .gitignore     # Ignore generated files
```

## ✧ What I Practiced

- Modeling user records with a `struct`
- Implementing a menu-driven command-line interface
- Applying control flow to account actions
- Reading and writing binary account files with `fread` and `fwrite`
- Handling a basic insufficient-balance condition

## ⚠ Limitations & Future Improvements

This is an **educational simulation, not secure banking software**. Passwords are stored in local account files without encryption. Input checking is limited, and the current transaction logic is not safe against all invalid amounts or malformed input. The program also uses Windows-oriented console clearing.

Potential improvements include:

- Stronger numeric and string input validation
- Rejection of negative and invalid transaction amounts
- Safer credential handling and storage
- Better file I/O error handling and automated tests
- A more portable and modular implementation

---

<p align="center">
  <a href="https://github.com/saimumfahad-dev">GitHub Profile</a> ·
  <a href="https://github.com/saimumfahad-dev/crime-investigation-portal-java">Java Project</a> ·
  <a href="https://www.linkedin.com/in/md-saimum-islam-fahad/">LinkedIn</a>
  <br />
  <sub>✦ Code · Build · Learn ✦</sub>
</p>
