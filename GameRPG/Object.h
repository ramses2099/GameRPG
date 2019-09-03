#pragma once
#include "Window.h"
#include <vector>
#include "Component.h"
#include "C_Transform.h"

class Object
{
public:
	Object();
	~Object();

	std::shared_ptr<C_Transform> transform;
	
	template <typename T> std::shared_ptr<T> AddComponent() // 1
	{
		// This ensures that we only try to add a class the derives 
		// from Component. This is tested at compile time.
		static_assert(std::is_base_of<Component, T>::value,
			"T must derive from Component");

			// Check that we don't already have a component of this type.
			for (auto& exisitingComponent : components)
			{
				// Currently we prevent adding the same component twice. 
				// This may be something we will change in future.
				if (std::dynamic_pointer_cast<T>(exisitingComponent))
				{
					return std::dynamic_pointer_cast<T>(exisitingComponent); // 2
				}
			}

		// The object does not have this component so we create it and 
		// add it to our list.
		std::shared_ptr<T> newComponent = std::make_shared<T>(this);
		components.push_back(newComponent);

		return newComponent;
	};

	template <typename T> std::shared_ptr<T> GetComponent()
	{
		static_assert(std::is_base_of<Component, T>::value,
			"T must derive from Component");

			// Check that we don't already have a component of this type.
			for (auto& exisitingComponent : components)
			{
				if (std::dynamic_pointer_cast<T>(exisitingComponent))
				{
					return std::dynamic_pointer_cast<T>(exisitingComponent);
				}
			}

		return nullptr;
	};
	
	bool IsQueuedForRemoval();
	void QueueForRemoval();


	void Awake();
	void Start();

	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);
private:
	std::vector<std::shared_ptr<Component>> components;
	//
	bool queuedForRemoval;
};

