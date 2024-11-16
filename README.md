# TinyLock

# Classic Ciphers in C++

This C++ project showcases the implementation of two iconic cryptographic algorithms: **Caesar Cipher** and **Vigenère Cipher**. Designed as a lightweight command-line tool, it allows users to encrypt and decrypt text using these classic encryption techniques, offering an intuitive and interactive experience.

## ✨ Features

### 🔐 Caesar Cipher
- A straightforward substitution cipher that shifts each letter of the plaintext by a fixed number of positions.
- Includes both **encryption** and **decryption** modes with customizable shift values.

### 🔑 Vigenère Cipher
- A more sophisticated polyalphabetic cipher that utilizes a keyword for variable letter shifting.
- Offers enhanced security by varying shifts based on the provided key.

### 🖥️ User-Friendly Interface
- A streamlined command-line menu guides users through selecting encryption methods and actions.

### 🎨 Enhanced Visuals
- Integrates ASCII art to enhance user interaction and add a unique, nostalgic touch to the experience.

### 🌐 Cross-Platform Compatibility
- Supports both **Windows** and **Unix-like systems**, with platform-specific commands for clearing the terminal.

## 🚀 Getting Started

### Prerequisites
- A C++ compiler with support for **C++11** or later (e.g., `g++`).
- Optionally, a C++17 compiler for enhanced features.

### Compilation

To compile the program using `g++`:

```bash
g++ -std=c++11 -o classic_ciphers main.cpp
