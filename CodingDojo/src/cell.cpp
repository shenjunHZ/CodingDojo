#include "cell.h"

namespace game
{

    Cell::Cell(bool cellLiveStatus, int liveNeighbours)
        : cellLiveStatus_(cellLiveStatus)
        , liveNeighbours_(liveNeighbours)
        , cellNextStatus_(false)
    {

    }

    bool Cell::getCellStatus(void)
    {
        return cellLiveStatus_;
    }

    int Cell::getLiveNeighbour(void)
    {
        return liveNeighbours_;
    }

    game::cellLocation Cell::getCellLocation(void)
    {
        return cellLocation_;
    }

    void Cell::setCellLocation(cellLocation location)
    {
        cellLocation_ = location;
    }

    void Cell::setLiveNeighbours(int neighbours)
    {
        liveNeighbours_ = neighbours;
    }

    void Cell::setCellStatus(bool status)
    {
        cellLiveStatus_ = status;
    }

    void Cell::delOneNeighbour(void)
    {
        if (liveNeighbours_ > 0)
        {
            liveNeighbours_--;
        }
    }

    void Cell::addOneNeighbour(void)
    {
        liveNeighbours_++;
    }

    void Cell::updateToNextGeneration()
    {
        cellLiveStatus_ = cellNextStatus_;
    }

    void Cell::setNextGenerationStatus(bool status)
    {
        cellNextStatus_ = status;
    }

}