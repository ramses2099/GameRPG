#include "pch.h"
#include "Input.h"


Input::Input()
{
}

Input::~Input()
{
}

bool Input::IsKeyPressed(Key keyCode)
{

	return thisFrameKeys.GetBit((int)keyCode);
}

bool Input::IsKeyDown(Key keyCode)
{
	bool lastFrame = lastFrameKeys.GetBit((int)keyCode);
	bool thisFrame = thisFrameKeys.GetBit((int)keyCode);

	return thisFrame && !lastFrame;
}

bool Input::IsKeyUp(Key keyCode)
{
	bool lastFrame = lastFrameKeys.GetBit((int)keyCode);
	bool thisFrame = thisFrameKeys.GetBit((int)keyCode);

	return !thisFrame && lastFrame;
}

void Input::Update()
{
	lastFrameKeys.SetMask(thisFrameKeys);

	thisFrameKeys.SetBit((int)Key::Left,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A)));

	thisFrameKeys.SetBit((int)Key::Right,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

	thisFrameKeys.SetBit((int)Key::Up,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
	
	thisFrameKeys.SetBit((int)Key::Down,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::S)));
	
	thisFrameKeys.SetBit((int)Key::Esc,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)));

}
