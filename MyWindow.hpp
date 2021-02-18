
#ifndef __MYWINDOW_HPP__
#define __MYWINDOW_HPP__

#include "Constant.hpp"

// SFML
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class MyWindow: public sf::RenderWindow
{
public:
	MyWindow(int sizeX,int sizeY);
	~MyWindow();

	void drawParticle(float posX,float posY,float radius,sf::Color color = sf::Color::Red);
	void drawBox(float posX,float posY,float lenght,sf::Color color = sf::Color::Blue);

private:
	// The window
	int m_sizeX;
	int m_sizeY;

};



#endif //__MYWINDOW_HPP__
