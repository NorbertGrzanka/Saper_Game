#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#ifndef UNTITLED18_MSTEXTCONTROLLER_H
#define UNTITLED18_MSTEXTCONTROLLER_H


class MSTextController {
MinesweeperBoard & board;
MSBoardTextView & view;
public:
    MSTextController(MinesweeperBoard & board , MSBoardTextView & view);

    void play();

};


#endif //UNTITLED18_MSTEXTCONTROLLER_H