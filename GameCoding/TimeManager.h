#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager);

public:
	void Init();
	void Update();

	uint64 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltatime; }

private:
	uint64 _frequency = 0;
	uint64 _prevCount = 0;
	float _deltatime = 0.f;

private:
	uint32 _frameCount = 0;
	float _frameTime = 0.f;
	uint32 _fps = 0;
};