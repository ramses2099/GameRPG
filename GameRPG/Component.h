#pragma once
#include "Window.h"

class Object;
class Component
{
public:
	Component(Object* owner) :owner(owner) {};
	~Component() {};

	virtual void Awake() {};
	virtual void Start() {};
	virtual void Update(float deltaTime) {};
	virtual void LateUpdate(float deltaTime) {};
	virtual void Draw(Window& window) {};

protected:
	Object* owner;
};

