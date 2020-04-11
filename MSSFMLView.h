#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include <string>

#ifndef UNTITLED18_MSSFMLVIEW_H
#define UNTITLED18_MSSFMLVIEW_H


class MSSFMLView {
    MinesweeperBoard& board;
    sf::Font font;
    sf::RectangleShape y(int width, int height, int size);
    sf::RectangleShape x(int width, int height, int size);
    sf::Text Mines(int width, int height, int size);
    sf::Text Mine(int width, int height, int size);
    sf::Text Flag(int width, int height, int size);
    sf::Sprite sprite;
    int width,height;
    sf::Texture block,mine,flag,revealed[5],mine_revealed;
    
public:
    explicit MSSFMLView(MinesweeperBoard& b);
    void draw(sf::RenderWindow& window);
};


#endif //UNTITLED18_MSSFMLVIEW_H
