#ifndef UNTITLED18_MSBOARDTEXTVIEW_H
#define UNTITLED18_MSBOARDTEXTVIEW_H


class MSBoardTextView {
    MinesweeperBoard &board;
public:
    int height;
    int width;
    MSBoardTextView(MinesweeperBoard & board )                ;
    void display() const;
};


#endif //UNTITLED18_MSBOARDTEXTVIEW_H
