# Hungry Snake Game

A classic console-based **Snake Game** written in C++ by **Asad Ullah (L1F23BSCS0225 - B-11)**.

## 📋 Overview

This game is a simple implementation of the Snake game, where the player controls a snake to eat food that randomly appears on the screen. With each food item consumed, the snake grows in size, and the score increases. The game ends when the snake collides with itself.

## 🕹️ Controls

| Key | Action     |
|-----|------------|
| `W` | Move Up    |
| `S` | Move Down  |
| `A` | Move Left  |
| `D` | Move Right |
| `X` | Exit Game  |

## ⚙️ Features

- Adjustable speed levels: Slow, Medium, Fast
- Wrapping around edges (snake appears from the opposite side)
- Real-time input using `conio.h` and `_kbhit()`, `_getch()`
- Console graphics using ASCII characters
- Food randomly generated
- Growing snake tail
- Scoring system

## 🧱 Requirements

- Windows OS (uses `<windows.h>` and `<conio.h>`)
- A C++ compiler like **g++**, **MSVC**, or **Dev-C++**

## 🚀 How to Run

1. Copy the code into a `.cpp` file (e.g., `snake_game.cpp`)
2. Compile using a C++ compiler:
   ```bash
   g++ snake_game.cpp -o snake_game
