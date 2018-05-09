#pragma once

namespace game
{
    typedef struct cellLocation
    {
        int posionX;
        int posionY;

    }cellLocation;

    class Cell
    {
    public:
        Cell() = default;
        Cell(bool cellLiveStatus, int liveNeighbours);
        bool getCellStatus(void);
        int getLiveNeighbour(void);
        cellLocation getCellLocation(void);

        void setCellLocation(cellLocation location);
        void setLiveNeighbours(int neighbours);
        void setCellStatus(bool status);

        void delOneNeighbour(void);
        void addOneNeighbour(void);
        void updateToNextGeneration();
        void setNextGenerationStatus(bool status);

    private:
        int liveNeighbours_;
        bool cellLiveStatus_;
        bool cellNextStatus_;
        cellLocation cellLocation_;
    };
}