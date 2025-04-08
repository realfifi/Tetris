#include "GameManager.h"

GameManager::GameManager(int width, int height)
	: width(width), height(height), isGameOver(false), currentBlock(nullptr), fallenBlocks(height, std::vector(width, false))
{
	srand(time(NULL));
}

void GameManager::run() {
	currentBlock = getRandomBlock();
	while (!isGameOver) {
		system("cls");
		handleInput();
		tryMoveDown();
		printBoard();
		Sleep(300);
	}
}

void GameManager::deleteRow(int n) {
	for (int i = 1; i < n; ++i) {
		fallenBlocks[i] = fallenBlocks[i - 1];
	}
}

void GameManager::checkIfRowFull() {
	for (int i = 0; i < height; ++i) {
		bool full = true;
		for (int j = 0; j < width; ++j) {
			if (!fallenBlocks[i][j]) {
				full = false;
				break;
			}
		}
		if (full) {
			deleteRow(i);
			i--;
		}
	}
}

void GameManager::handleCollision() {
	for (const auto& e : currentBlock->getCurrentCells()) {
		Vector2d realCellPos = currentBlock->pos + e.pos;
		int x = realCellPos.getX();
		int y = realCellPos.getY();
			
		if (x >= 0 && x < width && y >= 0 && y < height)
			fallenBlocks[y][x] = true;
	}
}

void GameManager::tryMoveDown() {
	currentBlock->pos.setY(currentBlock->pos.getY() + 1);
	if (currentBlock->isOnTheFloor(height) || currentBlock->doesCollide(fallenBlocks)) {
		currentBlock->pos.setY(currentBlock->pos.getY() - 1);
		handleCollision();
		checkIfRowFull();
		currentBlock = getRandomBlock();
		return;
	}
}

void GameManager::handleInput() {
	if (_kbhit()) {
		char ch = _getch();
		switch (ch) {
		case 'a':
			currentBlock->pos.setX(currentBlock->pos.getX() - 1);
			break;
		case 'd':
			currentBlock->pos.setX(currentBlock->pos.getX() + 1);
			break;
		case 'w':
			currentBlock->rotateBlock(currentBlock->getCurrentRotation() + 1);
			break;
		default: break;
		}
	}
}

std::unique_ptr<Block> GameManager::getRandomBlock() {
	int type = 3;//rand() % Blocks::TOTAL_BLOCKS;
	switch (type) {
		case 0: return std::make_unique<LBlock>();
		case 1: return std::make_unique<JBlock>();
		case 2: return std::make_unique<TBlock>();
		case 3: return std::make_unique<IBlock>();
		case 4: return std::make_unique<SBlock>();
		case 5: return std::make_unique<ZBlock>();
		case 6: return std::make_unique<OBlock>();
	}
	return nullptr;
}

void GameManager::printBoard() {
	for (int i = -1; i < height + 1; ++i) {
		// Display the borders
		if (i == -1 || i == height) {
			for (int j = -1; j < width + 1; ++j)
				std::cout << "#";
			std::cout << "\n";
			continue;
		}
		for (int j = -1; j < width + 1; ++j) {
			if (j == -1 || j == width)
				std::cout << "#";
			else if (fallenBlocks[i][j]) {
				std::cout << "0";
			}
			else {
				bool flag = false;
				for (const auto& e : currentBlock->getCurrentCells()) {
					Vector2d realCellPos = currentBlock->pos + e.pos;
					int x = realCellPos.getX();
					int y = realCellPos.getY();

					if (y == i and x == j) {
						flag = true;
						std::cout << "O";
					}
				}
				if (!flag) std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}

GameManager::~GameManager() {

}