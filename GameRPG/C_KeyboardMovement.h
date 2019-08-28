#pragma once
#include "Component.h"
#include "Input.h"

class C_KeyboardMovement:
	public Component
{
public:
	C_KeyboardMovement(Object* owner);
	~C_KeyboardMovement();

	void SetInput(Input* input);
	void SetMovementSpeed(int moveSpeed);

	void Update(float deltaTime);

private:
	int moveSpeed;
	Input* input;

};

