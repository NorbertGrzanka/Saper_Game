#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLView.h"


void MSSFMLView::draw(sf::RenderWindow &win)
{
    double x=50,y=0;
    char check;
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            check=board.getFieldInfo(row,col);
            if(check=='_') sprite.setTexture(block);
            if(check=='F') sprite.setTexture(flag);
            if(check==' ') sprite.setTexture(revealed[0]);
            for(int i=1;i<9;i++)
            {
                if(check==i+'0') sprite.setTexture(revealed[i]);
            }
            if(check=='X') sprite.setTexture(mine);
            if(check=='x') sprite.setTexture(mine_revealed);
            sprite.setPosition(sf::Vector2f(x, y));
            win.draw(sprite);
            x=x+50;
        }
        x=50;
        y=y+50;
    }


}