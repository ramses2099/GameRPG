#pragma once

#include <SFML/Graphics.hpp>


class Window
{
public:
	Window(const std::string& windowName);
	~Window();

	void Update();
	void BeginDraw();
	void Draw(const sf::Drawable& drawable);
	void EndDraw();
	sf::Vector2u GetCenter() const;

	bool IsOpen() const;
private:
	sf::RenderWindow window;

};

