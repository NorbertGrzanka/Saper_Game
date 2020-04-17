#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H



class MSBoardTextView {
    MinesweeperBoard &board;

private:
    int height;
    int width;
public:

    MSBoardTextView(MinesweeperBoard & board );
    void display() const;
};




#endif //SAPER_MSBOARDTEXTVIEW_H
