#include "Blocks.h"

Block::Block() : currentRotation(0) { }
Block::~Block() { }

bool Block::doesCollide(const std::vector<std::vector<bool>>& fallenBlocks) {
    for (const auto& e : currentCells) {
        Vector2d realCellPos = pos + e.pos;
        int x = realCellPos.getX();
        int y = realCellPos.getY();

        if (x < 0 || x >= fallenBlocks[0].size() || y < 0 || y >= fallenBlocks.size())
            continue;

        if (fallenBlocks[y][x])
            return true;
    }
    return false;
}

bool Block::isOnTheFloor(int height) {
    for (const auto& e : currentCells) {
        int y = pos.getY() + e.pos.getY();
        
        if (y == height) 
            return true;
    }
    return false;
}

const std::array<Cell, 4>& Block::getCurrentCells() const {
    return currentCells;
}

int Block::getCurrentRotation() const {
    return currentRotation;
}


LBlock::LBlock() {
    rotateBlock(0);
}

JBlock::JBlock() {
    rotateBlock(0);
}


TBlock::TBlock() {
    rotateBlock(0);
}


IBlock::IBlock() {
    rotateBlock(0);
}


SBlock::SBlock() {
    rotateBlock(0);
}


ZBlock::ZBlock() {
    rotateBlock(0);
}

OBlock::OBlock() {
    rotateBlock(0);
}



void LBlock::rotateBlock(int n) {
    std::array<std::array<Cell, 4>, 4> rotations{
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(1, 2), Cell(0, 2) },
        std::array<Cell, 4>{ Cell(0, 1), Cell(1, 1), Cell(2, 1), Cell(2, 2) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(1, 2), Cell(2, 0) },
        std::array<Cell, 4>{ Cell(0, 0), Cell(0, 1), Cell(1, 1), Cell(2, 1) }
    };
    currentRotation = n;
    currentCells = rotations[n % 4];
}

void JBlock::rotateBlock(int n) {
    std::array<std::array<Cell, 4>, 4> rotations{
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(1, 2), Cell(0, 0) },
        std::array<Cell, 4>{ Cell(0, 1), Cell(1, 1), Cell(2, 1), Cell(0, 2) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(1, 2), Cell(2, 2) },
        std::array<Cell, 4>{ Cell(0, 1), Cell(1, 1), Cell(2, 1), Cell(2, 0) }
    };
    currentRotation = n;
    currentCells = rotations[n % 4];
}

void TBlock::rotateBlock(int n) {
    std::array<std::array<Cell, 4>, 4> rotations{
        std::array<Cell, 4>{ Cell(1, 0), Cell(0, 1), Cell(1, 1), Cell(2, 1) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(2, 1), Cell(1, 2) },
        std::array<Cell, 4>{ Cell(0, 1), Cell(1, 1), Cell(2, 1), Cell(1, 2) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(0, 1), Cell(1, 1), Cell(1, 2) }
    };
    currentRotation = n;
    currentCells = rotations[n % 4];
}

void IBlock::rotateBlock(int n) {
    std::array<std::array<Cell, 4>, 4> rotations{
        std::array<Cell, 4>{ Cell(0, 1), Cell(1, 1), Cell(2, 1), Cell(3, 1) },
        std::array<Cell, 4>{ Cell(2, 0), Cell(2, 1), Cell(2, 2), Cell(2, 3) },
        std::array<Cell, 4>{ Cell(0, 2), Cell(1, 2), Cell(2, 2), Cell(3, 2) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(1, 2), Cell(1, 3) }
    };
    currentRotation = n;
    currentCells = rotations[n % 4];
}

void SBlock::rotateBlock(int n) {
    std::array<std::array<Cell, 4>, 4> rotations{
        std::array<Cell, 4>{ Cell(1, 0), Cell(2, 0), Cell(0, 1), Cell(1, 1) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(1, 1), Cell(2, 1), Cell(2, 2) },
        std::array<Cell, 4>{ Cell(1, 1), Cell(2, 1), Cell(0, 2), Cell(1, 2) },
        std::array<Cell, 4>{ Cell(0, 0), Cell(0, 1), Cell(1, 1), Cell(1, 2) }
    };
    currentRotation = n;
    currentCells = rotations[n % 4];
}

void ZBlock::rotateBlock(int n) {
    std::array<std::array<Cell, 4>, 4> rotations{
        std::array<Cell, 4>{ Cell(0, 0), Cell(1, 0), Cell(1, 1), Cell(2, 1) },
        std::array<Cell, 4>{ Cell(2, 0), Cell(1, 1), Cell(2, 1), Cell(1, 2) },
        std::array<Cell, 4>{ Cell(0, 1), Cell(1, 1), Cell(1, 2), Cell(2, 2) },
        std::array<Cell, 4>{ Cell(1, 0), Cell(0, 1), Cell(1, 1), Cell(0, 2) }
    };
    currentRotation = n;
    currentCells = rotations[n % 4];
}

void OBlock::rotateBlock(int n) {
    std::array<Cell, 4> rotation{
        Cell(1, 1), Cell(1, 2), Cell(2, 1), Cell(2, 2)
    };
    currentRotation = n;
    currentCells = rotation;
}
