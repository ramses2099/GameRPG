#pragma once

#include "Component.h"
#include "C_Transform.h"
#include "ResourceAllocator.h"

class C_Sprite:public Component
{
public:
	C_Sprite(Object* owner);
	~C_Sprite();
	void Load(int id);
	void Load(const std::string& path);

	void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

	void LateUpdate(float deltaTime)override;
	void Draw(Window& window)override;

private:
	ResourceAllocator<sf::Texture>* allocator;
	sf::Sprite sprite;
};

