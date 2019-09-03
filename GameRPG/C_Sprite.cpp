#include "pch.h"
#include "C_Sprite.h"
#include "Object.h"

C_Sprite::C_Sprite(Object * owner) :Component(owner),currentTextureId(-1)
{
}

C_Sprite::~C_Sprite()
{
}

void C_Sprite::Load(int id)
{
	if (id >= 0 && id != currentTextureId)
	{
		currentTextureId = id;
		std::shared_ptr<sf::Texture>texture = allocator->Get(id);
		sprite.setTexture(*texture);
	}

}
void C_Sprite::Load(const std::string& path)
{
	if (allocator)
	{
		int textureID = allocator->add(path);

		if (textureID >= 0 && textureID != currentTextureId) 
		{
			currentTextureId = textureID;
			std::shared_ptr<sf::Texture>texture = allocator->Get(textureID);
			sprite.setTexture(*texture);
		}
	}

}



void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
	this->allocator = allocator;
}

void C_Sprite::SetTextureRect(int x, int y, int width, int height)
{
	sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void C_Sprite::SetTextureRect(const sf::IntRect & rect)
{
	sprite.setTextureRect(rect);
}

void C_Sprite::LateUpdate(float deltaTime)
{
	sprite.setPosition(owner->transform->GetPosition());
}

void C_Sprite::Draw(Window & window)
{
	window.Draw(sprite);
}
