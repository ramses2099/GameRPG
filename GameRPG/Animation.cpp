#include "pch.h"
#include "Animation.h"



Animation::Animation(FacingDirection direction) :direction(direction), frames(0), currentFrameIndex(0), currentFrameTime(0.f)
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(int textureId, int x, int y, int width, int height, float frameTime)
{
	FrameData data;
	data.id = textureId;
	data.x = x;
	data.y = y;
	data.width = width;
	data.height = height;
	data.displayTimeSeconds = frameTime;
	frames.push_back(data);
}

const FrameData& Animation::GetCurrentFrame() const
{
	if (frames.size())
	{
		return frames[currentFrameIndex];
	
	}
	
}

void Animation::SetDirection(FacingDirection dir)
{
	if (direction != dir) 
	{
	
		direction = dir;
		for (auto& f : frames)
		{
			f.x += f.width;
			f.width *= -1;
		}
	}


}

FacingDirection Animation::GetDirection() const
{
	return direction;
}

bool Animation::UpdateFrame(float deltaTime)
{
	if (frames.size() > 0) 
	{
		currentFrameTime += deltaTime;
		if(currentFrameTime >= frames[currentFrameTime].displayTimeSeconds)
		{
			currentFrameTime = 0.f;
			IncrementFrame();
			return true;
		}	
	}

	return false;
}

void Animation::Reset()
{
	currentFrameIndex = 0;
	currentFrameTime = 0.f;
}

void Animation::IncrementFrame()
{
	currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}
