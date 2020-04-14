#include <iostream>
#include "MinesweeperBoard.h"
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode ) {
    condition = START;
    this->height = height;
    this->width = width;
    int SizeMin = 0;
    SizeMin = width * height;
    float percent = 0;



    if (mode == EASY) {
        percent = 0.1;
    } else if (mode == NORMAL) {
        percent = 0.2;
    } else if (mode == HARD) {
        percent = 0.3;
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            board[i][j].hasFlag = false;
            board[i][j].hasMine = false;
            board[j][i].isRevealed = false;
        }
    }
    if (mode == DEBUG) {
        condition = RUNNING;
        for (int i = 0; i < width; i++) {
            board[0][i].hasMine = true;
            for (int j = 0; j < height; j++) {
                if (j == i)
                    board[j][i].hasMine = true;
                board[2 * j][0].hasMine = true;
            }
        }
    }
    mines = SizeMin * percent;
    int mine_amount = mines;
    while (mine_amount > 0) {
        int a = rand() % height;
        int b = rand() % width;
        if (!board[a][b].hasMine) {
            board[a][b].hasMine = rand() % 2;
            if (board[a][b].hasMine)
                mine_amount--;
        }
    }
}
int MinesweeperBoard::getBoardWidth() const
{
    return width;
}
int MinesweeperBoard::getBoardHeight() const
{
    return height;
}
int MinesweeperBoard::getMineCount() const {
    return mines;
}

bool MinesweeperBoard::hasFlag(int x,int y) const
{
    if (OutOf(x, y) or board[x][y].isRevealed or !board[x][y].hasFlag)
        return false;
    return board[y][x].hasFlag;
}

bool MinesweeperBoard::OutOf(int x, int y) const {
    return x > width or x < 0 or y > height or y < 0;
}

int MinesweeperBoard::countMines(int x, int y) const {
    int ile = 0;
    if ((!board[y][x].isRevealed) or OutOf(x, y))
        return -1;
    else
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (MinesweeperBoard::board[y - 1 + i][x + j - 1].hasMine && !OutOf(x - 1 + j, y - 1 + i))
        
                    ile ++;
            }
        }
    return ile;
}
/*int MinesweeperBoard::countMines(int x, int y) const {
    int ile=0;
    if((!MinesweeperBoard::board[y][x].isRevealed) or OutOf(x,y))
        return -1;

   else

    for(int i=-1; i<=1; i++)
        for(int j=-1; j<=1; j++)
            if( !(x+i<0 or y+j<0 or x+i>width or y+j> height) and OutOf(x-1 + j , y - 1 +i))
                if(hasMine(x,y))
                    ile ++;

    return ile ;
}
*/
void MinesweeperBoard::toggleFlag(int x, int y)
{
    if(isRevealed(x,y) or OutOf(x,y) or condition==FINISHED_LOSS or condition==FINISHED_WIN )
        return ;

    else if(!isRevealed(x,y) and hasFlag(x,y))
        board[x][y].hasFlag = false;

    else if (!isRevealed(x,y) and !hasFlag(x,y))
        board[x][y].hasFlag = true;

}
void MinesweeperBoard::revealField(int x, int y)
{
    if (board[x][y].isRevealed or OutOf(x, y) or board[x][y].hasFlag or condition==FINISHED_WIN or condition==FINISHED_LOSS)
        return ;
    if (MinesweeperBoard::condition == RUNNING and !board[x][y].isRevealed and !board[x][y].hasMine) {
        MinesweeperBoard::board[x][y].isRevealed = true;
    }
    if (MinesweeperBoard::board[y][x].hasMine && MinesweeperBoard::condition == START) {
        MinesweeperBoard::board[y][x].hasMine = false;

        for (int i = 0; i > 0;) {

            int p = rand() % width;
            int q = rand() % height;
            if (!board[p][q].hasMine) {
                board[p][q].hasMine = true;
                i++;
            }
        }
        condition = RUNNING;

    }
    if (board[x][y].hasMine) {
        board[x][y].isRevealed = true;
        condition = FINISHED_LOSS;
    }
    if (!isRevealed(x, y)) {
        board[x][y].isRevealed = true;
    }
    if (getFieldInfo(x, y) == ' ') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                revealField(x - 1 + i, y + j - 1);
            }
        }
    }
}
/*
bool MinesweeperBoard::hasMine(int x, int y) const {
    return 1;
}
*/
GameState MinesweeperBoard::getGameState() const
{
    int mines1 = mines;
    int mines2 = mines;
    for (int i = 0; i < getBoardHeight(); i++) {
        for (int j = 0; j < getBoardWidth(); j++) {
            if (getFieldInfo(i, j) == 'x')
                return FINISHED_LOSS;
            if (hasFlag(j, i)) {
                if (!board[i][j].hasMine && hasFlag(j, i))
                    mines1++;
                if (board[i][j].hasMine && hasFlag(j, i))
                    mines1--;
            }
            if (!isRevealed(i, j) && board[i][j].hasMine)
                mines2--;
            if (!isRevealed(i, j) && !board[i][j].hasMine)
                mines2++;
        }
    }
    if (mines2 == 0 || mines1 == 0)
        return FINISHED_WIN;
    return RUNNING;
}

       /* {
            if(condition == FINISHED_LOSS)
            {
                return FINISHED_LOSS;
            }
            if(condition == FINISHED_WIN and mines==0 )
            {
                return FINISHED_WIN;
            }
            else {
                return RUNNING;
            }
        }
*/
        bool MinesweeperBoard::isRevealed(int x, int y) const
        {
            return board[x][y].isRevealed;
        }


      /*  MinesweeperBoard::MinesweeperBoard()
        {
            width=10;
            height=10;
            for(int i=0; i<width ; i++){
                for(int j=0; j<height ; j++) {
                    board[i][j].hasFlag= false;
                    board[i][j].isRevealed=false;
                    board[i][j].hasMine=false;
                }}
            board[0][0].hasMine=true;
            board[1][1].isRevealed=true;
            board[2][0].hasMine=true;
            board[2][0].hasFlag=true;

        }
*/
 void MinesweeperBoard::debug_display() const
{
    for(int i=0; i<width ; i++ ) {
        for (int j = 0; j < height ; j++) {
            std::cout << "[";
            if (board[i][j].hasMine){
                std::cout<<"M";
            }
            else
            {
                std::cout<<".";
            }
            if(board[i][j].isRevealed)
            {
                std::cout<<"O";
            }
            else
            {
                std::cout<<".";
            }
            if(board[i][j].hasFlag)
            {
                std:: cout<<"f";
            }
            else
            {
                std:: cout<<".";
            }
            std::cout<<"]";

        }
        std::cout<<endl;
    }}

char MinesweeperBoard::getFieldInfo(int x, int y) const {
    if (x > width or x < 0 or y > height or y < 0)
        return '#';
    if (!board[x][y].isRevealed and !board[x][y].hasFlag)
        return '_';
    if (board[x][y].isRevealed  and board[x][y].hasMine )
        return 'X';
    if (board[x][y].isRevealed  and countMines(x, y) == 0)
        return ' ';
    if (board[x][y].isRevealed  and countMines(x, y) != 0) {
        if (countMines(x, y) == 1) {
            return '1';
        }
        if (countMines(x, y) == 2) {
            return '2';
        }
        if (countMines(x, y) == 3) {
            return '3';
        }
        if (countMines(x, y) == 4) {
            return '4';
        }
        if (countMines(x, y) == 5) {
            return '5';
        }
        if (countMines(x, y) == 6) {
            return '6';
        }
        if (countMines(x, y) == 7) {
            return '7';
        }
        if (countMines(x, y) == 8) {
            return '8';
        }

    }
}