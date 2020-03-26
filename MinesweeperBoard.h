
#ifndef UNTITLED18_MINESWEEPERBOARD_H
#define UNTITLED18_MINESWEEPERBOARD_H
using namespace std;
enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;

};

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    GameState condition;
    int mines;

public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode );
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    bool hasMine(int x, int y) const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool isRevealed(int x, int y) const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;
    void debug_display() const;
};

#endif //UNTITLED18_MINESWEEPERBOARD_H
