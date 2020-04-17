#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <iostream>

int main()
{


    MinesweeperBoard board(15, 15, NORMAL);
    sf::RenderWindow win(sf::VideoMode((size_+2)*board.getBoardWidth(),(size_+2)*board.getBoardHeight()),"SAPER");
    MSSFMLView view (board);
    sf::Font font;


    if (!font.loadFromFile("arial.ttf"))
        abort();

    sf::Text text;
    text.setFont(font);
    text.setPosition(75,250);
    text.setCharacterSize(80);


    // rysujemy
    while (win.isOpen())
    {

        win.clear();
        sf::Event event;


        if (event.type == sf::Event::MouseButtonPressed)
        {

            int wiersz =(event.mouseButton.y-( 2*(event.mouseButton.y)/size_)) /size_;
            int kolumna =(event.mouseButton.x-( 2*(event.mouseButton.y)/size_)) /size_;
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                board.revealField(kolumna, wiersz);
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                board.toggleFlag(kolumna, wiersz);
            }
        }
        while( win.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                win.close();

        }
        view.draw(win);

        win.display();
        if(board.getGameState()==FINISHED_WIN)
        {


            text.setString("VICTORY!");

            text.setFillColor(sf::Color::Green);
            while(1)
            {
                while( win.pollEvent( event ) ) {
                    if (event.type == sf::Event::Closed)
                        win.close();


                }
                win.clear();
                view.draw(win);

                    win.draw(text);
                    win.display();
            }
        }
        if(board.getGameState()==FINISHED_LOSS)
        {


            text.setFillColor(sf::Color::Red);
            text.setString("GAME OVER");
            while(1)
            {
                while( win.pollEvent( event ) ) {
                    if (event.type == sf::Event::Closed)
                        win.close();


                }
                win.clear();
                view.draw(win);
                win.draw(text);
                win.display();
            }
        }
    }
}