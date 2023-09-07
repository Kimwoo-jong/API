#include "pch.h"
#include "DevScene.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{

}

DevScene::~DevScene()
{

}

void DevScene::Init()
{

}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// 거리 = 시간 * 속도

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Left))
	{
		_playerPos.x -= _speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Right))
	{
		_playerPos.x += _speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Up))
	{
		_playerPos.y -= _speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Down))
	{
		_playerPos.y += _speed * deltaTime;
	}
}

void DevScene::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _playerPos, 50);
}
