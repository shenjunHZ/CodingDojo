#pragma once

#include "cell.h"
#include <vector>

namespace game
{
    class ControlCell
    {
    public:
        ControlCell();
        void initialCell(int rangeRow, int rangeCol);
        void setCellLive(int posionX, int posionY);
        void setCellDead(int posionX, int posionY);
        std::vector<game::Cell> getNeighbourCells(Cell cell);
        int getLiveNeighbours(Cell cell);
        void nextGeneration(void);
        void updateToNextGeneration();

        void printCellStatus();

    private:
        std::vector<Cell> cells_;
        int rangeRow_;
        int rangeCol_;
    };
}