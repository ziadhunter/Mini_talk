# 🗣️ Mini_talk

A minimal inter-process communication (IPC) project in C using UNIX signals — built as part of the 42 Network curriculum.

---

## 📌 Overview

**Mini_talk** is a small messaging system that allows a client to send strings to a server **one bit at a time**, using only UNIX signals (`SIGUSR1` and `SIGUSR2`). It showcases low-level programming, signal handling, and bitwise manipulation.

---

## 🧠 Learning Objectives

- Signals and inter-process communication (IPC)
- Bitwise operations and binary encoding
- UNIX system calls (`kill`, `signal`, `pause`, etc.)
- Synchronous client-server behavior
- Writing robust and safe C code

---

## 📁 Project Structure

- `server.c` – Receives and reconstructs the message from the client
- `client.c` – Encodes and sends the string to the server
- `libft/` – (Optional) Custom library functions (if used)
- `Makefile` – Build instructions

---

## 🔧 Building the Project

```bash
git clone https://github.com/ziadhunter/Mini_talk.git
cd Mini_talk
make
