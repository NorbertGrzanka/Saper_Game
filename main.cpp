#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));
    MinesweeperBoard board(5, 5, GameMode::EASY);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);

    ctrl.play();
}
