#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):board(board),view(view) {}
void MSTextController::play() {
    int x, y, opcja;
    std:: cout<<"GRA SAPER"<<std::endl;
    std:: cout<<"------------------"<<std::endl;
    while(board.getGameState() != FINISHED_LOSS && board.getGameState() != FINISHED_WIN) {
        std::cout << "Co chcesz zrobic: " << std::endl;
        std::cout << "1.odkryj pole" << std::endl;
        std::cout << "2.Flaguj pole" <<std:: endl;
        std::cin >> opcja;
        std::cout << "Podaj wspolrzedne: " << std::endl;
        std::cin >> x >> y;
        switch (opcja) {
            case 1:
                board.revealField(x, y);
                break;
            case 2:
                board.toggleFlag(x, y);
                break;
            default:
                std::cout << "brak opcji" << std::endl;
                break;
        }
        view.display();
    }
        if (board.getGameState() == FINISHED_LOSS)
            std:: cout << "Przegrales" << std::endl;
        if (board.getGameState() == FINISHED_WIN)
            std::cout << "Wygrales" <<std:: endl;
}