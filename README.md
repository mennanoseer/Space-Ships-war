# Space Shooter Wars: A 2D Multiplayer Game in OpenGL

## Overview
Space Shooter Wars is a 2D space-themed multiplayer game developed using OpenGL and C. The game features two players battling each other in a fast-paced, action-packed environment, controlling their respective spaceships, avoiding enemy fire, and attempting to deplete their opponent's life bar by shooting lasers. The game includes a start menu, instructions, and game-over screens, along with the ability to control the spaceships' movement, shooting mechanics, and health status.

## Features
- **Multiplayer Gameplay**: Control two spaceships, each controlled by a different player, on the same screen.
- **Laser Shooting Mechanism**: Players can fire lasers in different directions to attack their opponents.
- **Health Bars**: Each player's health decreases with each laser hit.
- **Start Screen**: A menu with options to start the game, view instructions, or quit.
- **Instructions Screen**: Provides control instructions for both players.
- **Game Over Screen**: Displays a game-over message indicating the winner and a prompt to return to the menu.
- **Interactive Buttons**: Hover and click-based button interactions in the start and instructions screens.

## Controls
- **Player 1**:
  - Move Up: `W`
  - Move Down: `S`
  - Move Left: `A`
  - Move Right: `D`
  - Shoot: `C` (Press and hold to change shooting direction)
  
- **Player 2**:
  - Move Up: `I`
  - Move Down: `K`
  - Move Left: `J`
  - Move Right: `L`
  - Shoot: `M` (Press and hold to change shooting direction)

## Instructions
- Press **Enter** to start the game from the intro screen.
- The objective is to shoot and reduce the opponent's life to zero.
- Each time a player gets shot, their health decreases by 5 points.
- After the game ends, the winner is displayed, and you can return to the main menu.

## Setup
1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/space-shooter-wars.git
    cd space-shooter-wars
    ```

2. Make sure you have OpenGL and GLUT installed on your system.

3. Compile the project:
    ```bash
    g++ -o main Main.cpp screen_utils.cpp shape_utils.cpp spaceship_functions.cpp  game_logic.cpp input_handler.cpp  text_utils.cpp -lglut -lGL -lGLU
    ```

4. Run the game:
    ```bash
    ./main
    ```

## Dependencies
- OpenGL
- GLUT (OpenGL Utility Toolkit)

## Credits
- **Menna Noseer** (120210164)
- **Youssef Elamir** (120210179)
- **Abdelrahman Galhom** (120210209)
- **Instructor**: Eng Yasser Roheim
