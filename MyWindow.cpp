#define SFML_STATIC

#include "MyWindow.hpp"

// SFML
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

MyWindow::MyWindow(int sizeX,int sizeY):sf::RenderWindow(sf::VideoMode(sizeX,sizeY),TITLE),m_sizeX(sizeX),m_sizeY(sizeY)
{

}

MyWindow::~MyWindow()
{

}

void MyWindow::drawParticle(float posX,float posY,float radius,sf::Color color)
{
	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPosition(posX,posY);
	circle.setFillColor(color);
	draw(circle);
}

void MyWindow::drawBox(float posX,float posY,float lenght,sf::Color color)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(lenght,lenght));
	rectangle.setPosition(posX,posY);
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(color);
	rectangle.setFillColor(sf::Color::Black);
	draw(rectangle);
}
