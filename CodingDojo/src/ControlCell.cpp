#include "ControlCell.h"
#include <iostream>
#include <algorithm>

namespace game
{

    ControlCell::ControlCell()
        : rangeCol_(0)
        , rangeRow_(0)
    {

    }

    void ControlCell::initialCell(int rangeRow, int rangeCol)
    {
        for (int count = 0; count < rangeRow * rangeCol; ++count)
        {
            Cell cell(false, 0);
            int positionX = count;
            int positionY = 0;
            while (positionX >= rangeCol)
            {
                positionX -= rangeCol;
                positionY += 1;
            }
            cellLocation location = { positionX, positionY };

            cell.setCellLocation(location);
            cells_.push_back(cell);
        }

        rangeRow_ = rangeRow;
        rangeCol_ = rangeCol;
    }

    void ControlCell::setCellLive(int posionX, int posionY)
    {
//         for each (game::Cell& cell in cells_)
//         {
//             if (cell.getCellLocation().posionX == posionX && cell.getCellLocation().posionY == posionY)
//             {
//                 cell.setCellStatus(true);
//             }
//         }
        for_each(cells_.begin(), cells_.end(), [posionX, posionY](game::Cell& cell) {
            if (cell.getCellLocation().posionX == posionX && cell.getCellLocation().posionY == posionY)
            {
                cell.setCellStatus(true);
            }});
    }

    void ControlCell::setCellDead(int posionX, int posionY)
    {
        for_each(cells_.begin(), cells_.end(), [posionX, posionY](game::Cell& cell) {
            if (cell.getCellLocation().posionX == posionX && cell.getCellLocation().posionY == posionY)
            {
                cell.setCellStatus(false);
            }});
    }

    int ControlCell::getLiveNeighbours(Cell cell)
    {
        int neighbours = 0;
        std::vector<game::Cell> cells = getNeighbourCells(cell);
        for each (Cell neighbourCell in cells)
        {
            if (neighbourCell.getCellStatus())
            {
                neighbours++;
            }
        }

        return neighbours;
    }

    std::vector<game::Cell> ControlCell::getNeighbourCells(Cell cell)
    {
        std::vector<game::Cell> cells;
        for each (game::Cell neighbourCell in cells_)
        {
            if (abs(cell.getCellLocation().posionX - neighbourCell.getCellLocation().posionX) <= 1
                && abs(cell.getCellLocation().posionY - neighbourCell.getCellLocation().posionY) <= 1
                && !(cell.getCellLocation().posionX == neighbourCell.getCellLocation().posionX
                    && cell.getCellLocation().posionY == neighbourCell.getCellLocation().posionY))
            {
                cells.push_back(neighbourCell);
            }
        }

        return cells;
    }

    void ControlCell::printCellStatus()
    {
        for (int row = 0; row < rangeRow_; row++)
        {
            for (int col = 0; col < rangeCol_; col++)
            {
                if (cells_[row * rangeCol_ + col].getCellStatus())
                {
                    std::cout << "  *";
                }
                else
                {
                    std::cout << "  .";
                }
            }
            std::cout << std::endl;
        }
    }

    void ControlCell::nextGeneration(void)
    {
        for_each(cells_.begin(), cells_.end(), [this](Cell& cell)
        {
            int neighbours = getLiveNeighbours(cell);
            if (cell.getCellStatus())
            {
                if (neighbours < 2)
                {
                    cell.setNextGenerationStatus(false);
                }
                else if (neighbours > 3)
                {
                    cell.setNextGenerationStatus(false);
                }
                else
                {
                    cell.setNextGenerationStatus(cell.getCellStatus());
                }
            }
            else
            {
                if (3 == neighbours)
                {
                    cell.setNextGenerationStatus(true);
                }
                else
                {
                    cell.setNextGenerationStatus(cell.getCellStatus());
                }
            }
        });
    }
    
    void ControlCell::updateToNextGeneration()
    {
        for_each (cells_.begin(), cells_.end(), [] (Cell& cell)
        {
            cell.updateToNextGeneration();
        });
    }

}