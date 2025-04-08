# Console Tetris Game in C++

A simple implementation of the classic Tetris game written in C++. This project provides a playable version of Tetris with real-time gameplay, block rotation, scoring, and instant drop functionality. It is built for console-based gameplay using `conio.h` for handling user input.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)

## Installation

To install and run the project locally, follow these steps:

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/realfifi/Tetris.git
    ```
   
2. Navigate into the project directory:
    ```bash
    cd Tetris
    ```

3. Ensure you have a C++11 (or higher) compatible compiler and `conio.h` available.

   - **Note:** This project uses `conio.h`, which is a legacy library commonly used in DOS-based compilers. It is not available on all modern systems. If you're using a Unix-based system (Linux/macOS), `conio.h` might not be available. You can use alternatives like `ncurses` on Linux to achieve similar functionality.
   
4. Build the project:
    ```bash
    g++ -o tetris main.cpp
    ```

5. Run the game:
    ```bash
    ./tetris
    ```

## Usage

Once you've installed the project, you can start playing the Tetris game.

### Controls:
- **A/D*: Move the blocks left and right.
- **W**: Rotate the current block.
- **S**: Instantly drop the block.
- **Q**: Quit the game.

### Features:
- **Real-time gameplay** with responsive controls.
- **Block rotation** and multiple shapes to play with.
- **Score tracking** with a high score leaderboard.
- **Instant drop** for blocks with the `S` key.
- **Game over** condition triggered when a block can't spawn at the top of the screen.
- **Sliding blocks** ability to slide blocks for a spare moment.

## Contributing

Contributions are welcome! If you would like to contribute to the development of this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and test them.
4. Commit your changes (`git commit -m 'Add new feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Open a pull request on GitHub.

Please ensure that your changes do not break any existing functionality and add appropriate tests if necessary.
