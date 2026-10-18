# Cpt4 (Crypt Version 4.0) 🔐

A secure command-line tool written in C to encrypt and decrypt strings using a dynamic character-shifting cipher.

## ✨ Features
- Uses dynamic memory (`malloc`/`free`) safely.
- **Spy Mode:** Automatically converts spaces (` `) into underscores (`_`) during encryption.

## 🚀 How to Run

```bash
# Compile the program
gcc cpt4.c -o cpt4

# Encrypt a message (using a shift step between 1 and 8)
./cpt4 enc "Hello World" 2

# Decrypt the message back
./cpt4 dec "Fcjjm_Umpjb" 2
```

## 👤 Author
- **bereket-at** (Built on Sun, Oct 18, 2026)
