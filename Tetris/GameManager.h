#pragma once
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "Blocks.h"

class GameManager
{
	bool isGameOver;
	int width, height;
	std::unique_ptr<Block> currentBlock;
	std::vector<std::vector<bool>> fallenBlocks;

	void printBoard();
	std::unique_ptr<Block> getRandomBlock();
	void tryMoveDown();
	void handleInput();
	void handleCollision();
	void checkIfRowFull();
	void deleteRow(int n);
public:
	GameManager(int width = 10, int height = 15);
	~GameManager();

	void run();
};

