#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <iostream>


int main()
{
    sf::RenderWindow win(...);

    MinesweeperBoard board(7, 4, DEBUG);
    MSSFMLView view (board);


    board.toggleFlag(0,0);
    board.revealField(2,3);

    // rysujemy
    while (win.isOpen())
    {
        // obsługa zdarzeń
        //
        win.clear();
        view.draw(win);   // wywołujemy funkcję draw i dostarczamy jej okno na którym ma odbyć sie rysowanie
        win.display();
    }
}