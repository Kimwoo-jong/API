#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Flipbook.h"
#include "CameraComponent.h"
#include "Collider.h"

Player::Player()
{
	_flipbookUp = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveUp");
	_flipbookDown = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveDown");
	_flipbookLeft = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveLeft");
	_flipbookRight = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveRight");

	CameraComponent* camera = new CameraComponent();
	AddComponent(camera);
}

Player::~Player()
{

}

void Player::BeginPlay()
{
	Super::BeginPlay();

	SetFlipbook(_flipbookRight);
}

void Player::Tick()
{
	Super::Tick();

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	// TODO
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W)
		|| GET_SINGLE(InputManager)->GetButton(KeyType::Up))
	{
		_pos.y -= 200 * deltaTime;
		SetFlipbook(_flipbookUp);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::S)
		|| GET_SINGLE(InputManager)->GetButton(KeyType::Down))
	{
		_pos.y += 200 * deltaTime;
		SetFlipbook(_flipbookDown);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::A)
		|| GET_SINGLE(InputManager)->GetButton(KeyType::Left))
	{
		_pos.x -= 200 * deltaTime;
		SetFlipbook(_flipbookLeft);
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::D)
		|| GET_SINGLE(InputManager)->GetButton(KeyType::Right))
	{
		_pos.x += 200 * deltaTime;
		SetFlipbook(_flipbookRight);
	}
}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);


}

void Player::OnComponentBeginOverlap(Collider* collider, Collider* other)
{

}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{

}