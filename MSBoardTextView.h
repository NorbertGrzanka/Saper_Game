#ifndef UNTITLED18_MSBOARDTEXTVIEW_H
#define UNTITLED18_MSBOARDTEXTVIEW_H


class MSBoardTextView {
    MinesweeperBoard &board;
private:
    int height;
    int width;
public:
  
    MSBoardTextView(MinesweeperBoard & board )                ;
    void display() const;
};


#endif //UNTITLED18_MSBOARDTEXTVIEW_H
