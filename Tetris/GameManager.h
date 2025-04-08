#pragma once
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "Blocks.h"

class GameManager
{
	bool isGameOver;
	int score;
	int width, height;
	std::unique_ptr<Block> currentBlock, nextBlock;
	std::vector<std::vector<bool>> fallenBlocks;

	void printBoard();
	std::unique_ptr<Block> getRandomBlock();
	void tryMoveDown();
	void handleInput();
	void handleCollision();
	void checkIfRowFull();
	void deleteRow(int row);
	void placeBlock();
	void checkIfGameOver();
public:
	GameManager(int width = 10, int height = 20);
	~GameManager();

	void run();
};

