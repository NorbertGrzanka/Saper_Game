#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include <string>

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#define size_ 40

class MSSFMLView {
    MinesweeperBoard& board;

    sf::Font font;
    sf::Text text;
    sf::RectangleShape rectangle;


public:
    explicit MSSFMLView(MinesweeperBoard& board) :board(board){
        rectangle.setSize(sf::Vector2f(size_,size_));
        text.setFillColor(sf::Color::Yellow);
        font.loadFromFile("arial.ttf");
        text.setFont(font);
    }
    void draw (sf::RenderWindow& window);
};


#endif //SAPER_MSSFMLVIEW_H
