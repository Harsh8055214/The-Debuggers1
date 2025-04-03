# The-Debuggers
# Simple Pong Game

## Description
This is a simple Pong game implemented in C++ using the SFML library. The game features two paddles and a ball, where players can compete against an AI or another player.

## Features
- Classic Pong gameplay
- Single-player mode against AI
- Score tracking system
- Smooth paddle and ball movement
- Simple UI with SFML graphics

## Controls
- **Player 1 (Left Paddle):** `W` (Up), `S` (Down)
- **Player 2 / AI (Right Paddle):** `Up Arrow` (Up), `Down Arrow` (Down)

## Compilation and Execution
### Windows
Ensure SFML is installed before compiling.

#### Compile using g++:
```sh
g++ -o pong main.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

#### Run the game:
```sh
./pong
```

## How to Play
1. The game starts with a ball in the center.
2. Use the assigned keys to move paddles up and down.
3. The ball bounces off the walls and paddles.
4. If the ball passes a paddle, the opponent scores a point.
5. The game continues until a player reaches the target score.

## Functionality Overview
### `draw()`
Renders the game elements on the screen.

### `update()`
Updates the position of the ball and paddles, checks for collisions, and updates the score.

### `handleInput()`
Handles keyboard inputs for player movement.

### `checkCollision()`
Detects collisions between the ball and paddles or walls and adjusts movement accordingly.

### `resetBall()`
Resets the ball position after a point is scored.

### `run()`
The main game loop that continuously updates, renders, and checks for user input.

## Future Improvements
- Add a main menu and settings
- Implement sound effects for paddle hits and scoring
- Enhance AI difficulty levels
- Improve visuals with better graphics

## Group Members
- Member 1 Name:-Thakor Bhavunkumar ID:-202401113
- Member 2 Name:-Kodavla Harshkumar ID:-202401121
- Member 3 Name:-Panchal Harsh      ID:-202401134


## License
This project is open-source. Feel free to modify and distribute it!
