#pragma once
#include <vector>

struct FrameData
{
	int id;
	int x;
	int y;
	int width;
	int height;
	float displayTimeSeconds;
};

enum class FacingDirection
{
	None,
	Left,
	Right

};


class Animation
{
public:
	Animation(FacingDirection direction);
	~Animation();

	void AddFrame(int textureId, int x, int y, int width, int height, float frameTime);

	const FrameData& GetCurrentFrame() const;

	void SetDirection(FacingDirection dir);

	FacingDirection GetDirection() const;

	bool UpdateFrame(float deltaTime);

	void Reset();


private:
	void IncrementFrame();

	std::vector<FrameData> frames;

	int currentFrameIndex;

	float currentFrameTime;

	FacingDirection direction;
};

