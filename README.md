# 🕹️ Simple Console Pong Game

A console-based pong-style game written in C++ using Windows-specific libraries. Players control a paddle to bounce a ball and earn points. A power-up appears randomly to reward extra lives!

---

## 🎮 How to Play

- Use **LEFT** and **RIGHT** arrow keys to move the paddle.
- Press **P** to pause the game.
- Press **ESC** to exit the game.
- Catch the falling `+` power-up for extra lives!
- Ball speed increases over time, and paddle size shrinks after every 10 points!

---

## 🧠 Features

- Paddle and ball collision
- Score and high score tracking
- Falling power-up for extra lives
- Pause/resume functionality
- Game over and restart screen
- Simple console graphics using ASCII characters

---

## 🧩 Functions Overview

### `main()`
- Initializes the game settings.
- Loads high score and shows start screen.
- Contains the main game loop:
  - Handles input
  - Updates ball and power-up positions
  - Manages collisions and lives
  - Renders the game state
  - Ends when lives run out

---

### `gotoxy(int x, int y)`
- Moves the cursor to (x, y) on the console screen.
- Used for drawing borders, paddle, ball, power-up, and score.

---

### `hideCursor()`
- Hides the blinking cursor for a cleaner display during gameplay.

---

### `drawBorders()`
- Draws the game box using `#` characters.
- Defines the playable area (42 columns x 25 rows).

---

### `setColor(int color)`
- Changes console text color.
- Used to differentiate text and game elements.

---

### `drawBoard(...)`
- Draws all active game elements:
  - Borders
  - Paddle (`=`)
  - Ball (`O`)
  - Power-up (`+`)
  - Score, high score, and lives

---

### `loadHighScore()`
- Reads the saved high score from `highscore.txt`.

---

### `saveHighScore(int score)`
- Updates the high score in `highscore.txt` if the current score is higher.

---

### `showStartScreen()`
- Displays the welcome screen and instructions.
- Waits for a key press to start the game.

---

## 👥 Group Members

- 👤 [Your Name Here]
- 👤 [Teammate 1]
- 👤 [Teammate 2]
- 👤 [Teammate 3]

---

## 📁 Files

- `pong_game.cpp` - Source code
- `highscore.txt` - Stores highest score across sessions
- `README.md` - Documentation

---

## 🧱 Requirements

- Windows OS (uses `<windows.h>`)
- C++ Compiler (e.g., g++, Visual Studio)

---

## 🧪 To Compile and Run

```bash
g++ pong_game.cpp -o pong_game
./pong_game
