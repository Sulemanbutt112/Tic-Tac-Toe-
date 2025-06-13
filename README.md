Tic-Tac-Toe Game (C Language)
This repository features a complete Tic-Tac-Toe game built in C, offering two modes:

Human vs. Human: Classic two-player action on a 3x3 board.
Human vs. Computer: Challenge an AI that strategically aims for wins and blocks.
The game uses a clear console interface for mark selection, coordinate input, and board display, with built-in logic to detect wins and draws.

Features
Two Play Modes:
Human vs. Human (2 Players)
Human vs. Computer (AI opponent)
Intelligent AI: The computer opponent can check for winning moves and block player wins.
Console-Based Interface: Simple and intuitive text-based interaction.
Input Validation: Ensures players enter valid coordinates for their moves.
Win/Draw Detection: Accurately determines game outcomes.
How to Play
Run the Executable: After compiling (see "How to Compile and Run" below), execute the game from your terminal or command prompt.
Main Menu: Choose between "Human vs. Human" or "Human vs. Computer."
Select Marks: In the human vs. human mode, Player 1 chooses 'X' or 'O'. In human vs. computer, you choose your mark.
Choose Turn Order (Human vs. Computer): Decide if you want to go first or second.
Enter Coordinates: Input X and Y coordinates (0, 1, or 2) when prompted to place your mark on the board.
Game End: The game concludes when a player achieves three in a row (horizontally, vertically, or diagonally) or when all spaces are filled resulting in a draw.
Play Again: You'll be asked if you want to play another round.
How to Compile and Run
This project can be compiled using a standard C compiler like GCC or Clang.

Prerequisites
A C compiler (e.g., GCC, Clang) installed on your system.
Compilation Steps
Save the Code: Save all the provided C code into a single file, for example, tic_tac_toe.c.

Open Terminal/Command Prompt: Navigate to the directory where you saved tic_tac_toe.c.

Compile the code:

On Linux/macOS (using GCC/Clang):
Bash

gcc tic_tac_toe.c -o tic_tac_toe
or
Bash

clang tic_tac_toe.c -o tic_tac_toe
On Windows (using MinGW/GCC):
Bash

gcc tic_tac_toe.c -o tic_tac_toe.exe
Running the Game
After successful compilation, you can run the executable:

On Linux/macOS:
Bash

./tic_tac_toe
On Windows:
Bash

.\tic_tac_toe.exe
Technologies Used
C Language
