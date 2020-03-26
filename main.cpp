#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

int main()
{
    MinesweeperBoard board (20, 10, GameMode::EASY);
    MSBoardTextView view ( board );
    view.display();
    board.revealField(0,5);
    view.display();
}

