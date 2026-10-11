# Rock-Paper-Scissors

A C++ console-based Rock-Paper-Scissors game featuring modular code, custom data types, score tracking, and color-coded round results.

## Features

- **Interactive Gameplay:** Play against the computer by choosing Rock, Paper, or Scissors.
- **Multiple Rounds:** Choose between 1 and 10 rounds per game.
- **Score Tracking:** Keep track of player wins, computer wins, and draws.
- **Round Results:** Display each player's choice and the winner of every round.
- **Final Summary:** View the overall game statistics and final winner.
- **Console Color Feedback:** Change console colors based on round outcomes.
- **Replay Option:** Start another game without restarting the program.

## Concepts Used

- C++ enums and structs
- Functions and modular programming
- Pass-by-reference
- Conditional statements and switch statements
- Loops and input range checking
- Pseudo-random number generation using `rand()` and `srand()`
- Console formatting and Windows system commands

## Technologies

- **Language:** C++
- **Standard Libraries:** `<iostream>`, `<cstdlib>`, `<ctime>`, `<string>`

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/hady-shkaier/rock-paper-scissors.git
cd rock-paper-scissors
```

### 2. Compile the source code

Using g++ (MinGW-w64 on Windows):

```bash
g++ main.cpp -o rock-paper-scissors.exe
```

### 3. Run the game

```bash
.\rock-paper-scissors.exe
```

**Note:** This game is designed for Windows because it uses Windows-specific console commands for screen clearing and color changes.

## Author

* **HaDy** - [hady-shkaier](https://github.com/hady-shkaier)
