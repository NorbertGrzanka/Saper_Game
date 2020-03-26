#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>



MSBoardTextView::MSBoardTextView(MinesweeperBoard & boardd ) : board(boardd)
{
    height=board.getBoardHeight();
    width=board.getBoardWidth();
}

void MSBoardTextView::display() const {
    for ( int i=0; i<height ; i++){
        for(int j=0; j<width ; j++){
            std::cout<<board.getFieldInfo(i,j)<<std::endl;
        }
    }
}
