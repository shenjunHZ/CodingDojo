/*
*Your task is to write a program to calculate the next
*generation of Conway's game of life, given any starting
*position.
*
*You start with a two dimensional grid of cells, where
*each cell is either alive or dead. The grid is finite,
*and no life can exist off the edges. When calculating
*the next generation of the grid, follow these four rules:
*
*1. Any live cell with fewer than two live neighbours
*dies, as if caused by underpopulation.
*2. Any live cell with more than three live neighbours
*dies, as if by overcrowding.
*3. Any live cell with two or three live neighbours
*lives on to the next generation.
*4. Any dead cell with exactly three live neighbours
*becomes a live cell.
*
*Examples: * indicates live cell, . indicates dead cell
*
*Example input: (4 x 8 grid)
4 8
........
....*...
...**...
........

*Example output:
4 8
........
...**...
...**...
........

*/

#include "ControlCell.h"

#include <iostream>

constexpr int TOTAL_RUN_TIMES = 5;

int main(int argc, char* argv[])
{
    using namespace game;
    ControlCell controlCell;
//     controlCell.initialCell(4, 8); // 4*8 grid
//     controlCell.setCellLive(4, 1);
//     controlCell.setCellLive(3, 2);
//     controlCell.setCellLive(4, 2);
    //�������ߡ���ÿ4���غϡ������������½���һ����Ȼϸ������ǲ�ͬ��ϸ���ˣ������ܱ���ԭ������̬��
     controlCell.initialCell(10, 10);
     controlCell.setCellLive(4, 1);
     controlCell.setCellLive(4, 2);
     controlCell.setCellLive(4, 3);
     controlCell.setCellLive(4, 2);
     controlCell.setCellLive(3, 3);
     controlCell.setCellLive(2, 2);

     controlCell.printCellStatus();
     for (int times = 0; times < TOTAL_RUN_TIMES; times++)
     { 
         controlCell.nextGeneration();
         controlCell.updateToNextGeneration();
         std::cout << "== == == == == == == == == == == == == == == == == == == == == =" << std::endl;
         controlCell.printCellStatus();
     }

    system("pause");
    return 0;
}