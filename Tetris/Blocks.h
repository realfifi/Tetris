#pragma once
#include <vector>
#include <array>
#include <iostream>
#include "Cell.h"

namespace Blocks {
	inline const int TOTAL_BLOCKS = 7;
}

class Block
{
protected:
	std::array<Cell, 4> currentCells;
	int currentRotation;

public:
	Block();
	virtual void rotateBlock(int n) = 0;
	virtual ~Block();

	Vector2d pos;

	const std::array<Cell, 4>& getCurrentCells() const;
	int getCurrentRotation() const;

	bool doesCollideFallen(const std::vector<std::vector<bool>>& fallenBlocks);
	bool isOnTheFloor(int height);
	bool doesCollideWall(int width);
};

class LBlock : public Block {
public:
	LBlock();
	void rotateBlock(int n) override;
};

class JBlock : public Block {
public:
	JBlock();
	void rotateBlock(int n) override;
};

class TBlock : public Block {
public:
	TBlock();
	void rotateBlock(int n) override;
};

class IBlock : public Block {
public:
	IBlock();
	void rotateBlock(int n) override;
};

class SBlock : public Block {
public:
	SBlock();
	void rotateBlock(int n) override;
};

class ZBlock : public Block {
public:
	ZBlock();
	void rotateBlock(int n) override;
};

class OBlock : public Block {
public:
	OBlock();
	void rotateBlock(int n) override;
};

