#include "MSSFMLView.h"

void MSSFMLView::draw (sf::RenderWindow& window)
{
  for(int i=0; i<board.getBoardWidth(); i++)
      for(int j=0; j<board.getBoardHeight(); j++)
      {

          rectangle.setPosition(((size_+2)*i),((size_+2)*j));

          text.setPosition(((size_+2)*i)+10,((size_+2)*j));
          if(board.isRevealed(i,j))
              rectangle.setFillColor(sf::Color(100,100,100));
          else
              rectangle.setFillColor(sf::Color(60,60,60));
          text.setString((board.getFieldInfo(i,j)));

          window.draw(rectangle);
          window.draw(text);
      }


}