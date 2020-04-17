#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H


class MSTextController {
MinesweeperBoard & board;
MSBoardTextView & view;
public:
    MSTextController(MinesweeperBoard & board , MSBoardTextView & view);

    void play();

};


#endif //SAPER_MSTEXTCONTROLLER_H