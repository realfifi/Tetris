#include "GameManager.h"

GameManager::GameManager(int width, int height)
	: width(width), height(height), isGameOver(false), currentBlock(nullptr), fallenBlocks(height, std::vector(width, false)), score(0)
{
	srand(time(NULL));
}

void GameManager::run() {
	using namespace std::chrono;

	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();

	auto last = high_resolution_clock::now();

	while (!isGameOver) {
		auto now = high_resolution_clock::now();
		system("cls");
		handleInput();
		if (now - last >= milliseconds(300)) {
			tryMoveDown();
			last = now;
		}
		printBoard();
		Sleep(16);
	}
}

void GameManager::checkIfGameOver() {
	if (currentBlock->doesCollideFallen(fallenBlocks) && currentBlock->pos.getY() <= 1)
		isGameOver = true;
}

void GameManager::placeBlock() {
	handleCollision();
	checkIfRowFull();
	currentBlock = std::move(nextBlock);
	nextBlock = getRandomBlock();
	checkIfGameOver();
	score += 10;
}

void GameManager::deleteRow(int row) {
	for (int i = row; i > 0; --i) {
		fallenBlocks[i] = std::move(fallenBlocks[i - 1]);
	}

	fallenBlocks[0] = std::vector<bool>(width, false);
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

	if (currentBlock->isOnTheFloor(height) || currentBlock->doesCollideFallen(fallenBlocks)) {
		currentBlock->pos.setY(currentBlock->pos.getY() - 1);
		placeBlock();
		return;
	}
}

void GameManager::handleInput() {
	if (_kbhit()) {
		char ch = _getch();
		switch (ch) {
		case 'a':

			currentBlock->pos.setX(currentBlock->pos.getX() - 1);

			if (currentBlock->doesCollideFallen(fallenBlocks) || currentBlock->doesCollideWall(width)) {
				currentBlock->pos.setX(currentBlock->pos.getX() + 1);
			}
			break;
		case 'd':

			currentBlock->pos.setX(currentBlock->pos.getX() + 1);

			if (currentBlock->doesCollideFallen(fallenBlocks) || currentBlock->doesCollideWall(width)) {
				currentBlock->pos.setX(currentBlock->pos.getX() - 1);
			}
			break;
		case 'w':

			currentBlock->rotateBlock(currentBlock->getCurrentRotation() + 1);

			if (currentBlock->isOnTheFloor(height) || currentBlock->doesCollideFallen(fallenBlocks) || currentBlock->doesCollideWall(width)) {
				currentBlock->rotateBlock(currentBlock->getCurrentRotation() - 1);
			}
			break;
		case 's':

			while (true) {
				currentBlock->pos.setY(currentBlock->pos.getY() + 1);
				if (currentBlock->isOnTheFloor(height) || currentBlock->doesCollideFallen(fallenBlocks)) {
					currentBlock->pos.setY(currentBlock->pos.getY() - 1);
					break;
				}
			}

			placeBlock();

			break;
		case 'q':
			isGameOver = true;
			break;
		default: break;
		}
	}
}

std::unique_ptr<Block> GameManager::getRandomBlock() {
	int type = rand() % Blocks::TOTAL_BLOCKS;
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
				std::cout << "*";
			std::cout << "\n";
			continue;
		}
		for (int j = -1; j < width + 1; ++j) {
			if (j == -1 || j == width)
				std::cout << "*";
			else if (fallenBlocks[i][j]) {
				std::cout << "@";
			}
			else {
				bool flag = false;
				for (const auto& e : currentBlock->getCurrentCells()) {
					Vector2d realCellPos = currentBlock->pos + e.pos;
					int x = realCellPos.getX();
					int y = realCellPos.getY();

					if (y == i and x == j) {
						flag = true;
						std::cout << "#";
					}
				}
				if (!flag) std::cout << " ";
			}
		}
		std::cout << "\n";
	}

	std::cout << "Score [" << score << "]\n";
	std::cout << "Next block: \n";

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			bool flag = false;
			for (const auto& e : nextBlock->getCurrentCells()) {
				if (e.pos.getY() == i and e.pos.getX() == j) {
					flag = true;
					std::cout << "#";
				}
			}
			if (!flag) std::cout << " ";
		}
		std::cout << "\n";
	}
}

GameManager::~GameManager() {

}