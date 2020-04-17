#include "MinesweeperBoard.h"
#include <iostream>
#include<cstdlib>


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
    int NrMines = mines;
    while (NrMines > 0) {
        int a = rand() % height;
        int b = rand() % width;
        if (!board[a][b].hasMine) {
            board[a][b].hasMine = rand() % 2;
            if (board[a][b].hasMine)
                NrMines--;
        }
    }
}


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
        std::cout<<std::endl;
    }}


int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}

int MinesweeperBoard::getMineCount() const {
    return mines;
}

int MinesweeperBoard::countMines(int x, int y) const {
    int min = 0;
    if ((!board[y][x].isRevealed) or OutOf(x, y))
        return -1;
    else
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[y - 1 + i][x + j - 1].hasMine and !OutOf(x - 1 + j, y - 1 + i))
                    min++;
            }
        }
    return min;
}

bool MinesweeperBoard::hasFlag(int x,int y) const
{
    if (OutOf(x, y) or board[x][y].isRevealed or !board[x][y].hasFlag)
        return false;
    return board[y][x].hasFlag;
}



void MinesweeperBoard::toggleFlag(int x, int y) {
    if (isRevealed(x, y) or OutOf(x, y) or condition == FINISHED_LOSS or condition == FINISHED_WIN)
        return;

    else if (!isRevealed(x, y) and hasFlag(x, y))
        board[x][y].hasFlag = false;

    else if (!isRevealed(x, y) and !hasFlag(x, y))
        board[x][y].hasFlag = true;

}

void MinesweeperBoard::revealField(int x, int y) {
    if (isRevealed(x, y) or OutOf(x, y) or hasFlag(x, y))
        return;
    if (condition == RUNNING and !board[y][x].hasMine) {
        board[y][x].isRevealed = true;
    }
    if (board[y][x].hasMine and condition == START) {
        board[y][x].hasMine = false;
        for (int i = 0; i > 0;) {
            int a = rand() % height;
            int b = rand() % width;
            if (!board[a][b].hasMine) {
                board[a][b].hasMine = true;
                i++;
            }
        }
    }
    condition = RUNNING;
    if (board[y][x].hasMine) {
        board[y][x].isRevealed = true;
        condition = FINISHED_LOSS;
    }
    if (!isRevealed(x, y)) {
        board[y][x].isRevealed = true;
    }

    if (getFieldInfo(x, y) == ' ') // odsłanianie pól bocznych
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                revealField(x - 1 + i, y + j - 1);
            }
        }
    }
}

bool MinesweeperBoard::isRevealed(int x, int y) const {
    return board[y][x].isRevealed;
}

GameState MinesweeperBoard::getGameState() const {
    int min1 = 0;
    for (int i = 0; i < getBoardHeight(); i++) {
        for (int j = 0; j < getBoardWidth(); j++) {
            if (getFieldInfo(i, j) == 'x')
                return FINISHED_LOSS;

            if ( isRevealed(j, i) && !board[i][j].hasMine)
                min1++;
        }
    }
    if ( min1 == getBoardWidth()*getBoardHeight()-mines)
        return FINISHED_WIN;
    return RUNNING;
}

bool MinesweeperBoard::OutOf(int x, int y) const {
    return x > width or x < 0 or y > height or y < 0;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const {
    if (OutOf(x, y))
        return '#';
    else if (!isRevealed(x, y) && hasFlag(x, y))
        return 'F';
    else if (!isRevealed(x, y) && !hasFlag(x, y))
        return ' ';
    else if (isRevealed(x, y) && board[y][x].hasMine)
        return 'x';
    else if (isRevealed(x, y) && countMines(x, y) == 0)
        return ' ';
    else if (isRevealed(x, y) && countMines(x, y) != 0)
        return countMines(x, y) + 48;
    else
        return '?';
}
