#include "pch.h"
#include "Object.h"


Object::Object():queuedForRemoval(false)
{
	transform = AddComponent<C_Transform>();
}
//
Object::~Object()
{
}
//
bool Object::IsQueuedForRemoval()
{
	return queuedForRemoval;
}
//
void Object::QueueForRemoval()
{
	queuedForRemoval = true;
}
//
void Object::Awake()
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Awake();
	}
}

void Object::Start()
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Start();
	}
}

void Object::Update(float timeDelta)
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Update(timeDelta);
	}
}

void Object::LateUpdate(float timeDelta)
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->LateUpdate(timeDelta);
	}
}

void Object::Draw(Window& window)
{
	for (int i = components.size() - 1; i >= 0; i--)
	{
		components[i]->Draw(window);
	}
}