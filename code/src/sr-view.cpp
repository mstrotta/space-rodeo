#include <SFML/Graphics.hpp>
#include "sr-view.h"
#include <iostream>

View::View(){
  _bgtexture.loadFromFile("bg.jpg");
  _bgsprite.setTexture(_bgtexture);
  _view.create(sf::VideoMode(800,600,32),"Space Rodeo");
  std::cout << _view.isOpen();
}


void View::setController(Control& controller){
  _controller = controller;
}


void View::drawAll(std::vector<CircleModel*>& mycirmodels){
  _view.clear(sf::Color::Black);
  _view.draw(_bgsprite);
  while (_view.pollEvent(_event)){//TODO: Use Control Class to handle the event
    switch (_event.type){
      case sf::Event::Closed:
        _view.close();
        break;
      case sf::Event::KeyPressed:
        _controller.handleEvent(_event);
	break;
      default:
        break;
				
    }
  }
  for (int i = 0; i < mycirmodels.size(); i++){
		if (mycirmodels[i]->draw)
      _view.draw(*mycirmodels[i]);
  }
  _view.display();
}

bool View::isRun(){
  if (_view.isOpen())
    return true;
  else
    return false;
}