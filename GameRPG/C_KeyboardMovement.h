#pragma once
#include "Component.h"
#include "Input.h"
#include "C_Animation.h"

class C_KeyboardMovement:
	public Component
{
public:
	C_KeyboardMovement(Object* owner);
	~C_KeyboardMovement();

	void SetInput(Input* input);
	void SetMovementSpeed(int moveSpeed);

	void Awake()override;


	void Update(float deltaTime);

private:
	int moveSpeed;
	Input* input;
	std::shared_ptr<C_Animation> animation;

};

