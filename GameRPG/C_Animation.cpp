#include "pch.h"
#include "C_Animation.h"
#include "Object.h"
#include "Animation.h"

C_Animation::C_Animation(Object * owner) :Component(owner),
currentAnimation(AnimationState::None, nullptr)
{
}

void C_Animation::Awake()
{
	sprite = owner->GetComponent<C_Sprite>();
}

void C_Animation::Update(float deltaTime)
{
	if (currentAnimation.first != AnimationState::None)
	{
		bool newFrame = currentAnimation.second->UpdateFrame(deltaTime);

		if (newFrame)
		{
			FrameData data = currentAnimation.second->GetCurrentFrame();

			sprite->Load(data.id);

			sprite->SetTextureRect(data.x, data.y, data.width, data.height);
		}

	}
}

void C_Animation::AddAnimation(AnimationState state, std::shared_ptr<Animation> animation)
{
	auto inserted = animations.insert(std::make_pair(state, animation));
	if (currentAnimation.first == AnimationState::None)
	{
		SetAnimation(state);
	}
}

void C_Animation::SetAnimation(AnimationState state)
{
	if (currentAnimation.first == state)
	{
		return;
	}

	auto animation = animations.find(state);
	if (animation != animations.end())
	{
		currentAnimation.first = animation->first;
		currentAnimation.second = animation->second;

		currentAnimation.second->Reset();
	}

}

void C_Animation::SetAnimationDirection(FacingDirection dir)
{
	if (currentAnimation.first != AnimationState::None)
	{
		currentAnimation.second->SetDirection(dir);
	}
}

const AnimationState & C_Animation::GetAnimationState() const
{
	return currentAnimation.first;
}

C_Animation::~C_Animation()
{
}
