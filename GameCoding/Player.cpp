#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"
#include "UIManager.h"
#include "Bullet.h"

Player::Player() : Object(ObjectType::Player)
{

}

Player::~Player()
{

}

void Player::Init()
{
	// Data
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// 거리 = 시간 * 속도
	if (_playerTurn == false)
		return;

	UpdateFireAngle();

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Left))
	{
		_pos.x -= _stat.speed * deltaTime;

		_dir = Dir::LEFT;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Right))
	{
		_pos.x += _stat.speed * deltaTime;

		_dir = Dir::RIGHT;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Up))
	{
		_fireAngle = ::clamp(_fireAngle + 50 * deltaTime, 0.f, 75.f);
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Down))
	{
		_fireAngle = ::clamp(_fireAngle - 50 * deltaTime, 0.f, 75.f);
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Q))
	{
		
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::E))
	{
		
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::SpaceBar))
	{
		// 투사체 발사
		float percent = GET_SINGLE(UIManager)->GetPowerPercent();
		percent = min(100, percent + 100 * deltaTime);
		GET_SINGLE(UIManager)->SetPowerPercent(percent);
	}

	if (GET_SINGLE(InputManager)->GetButtonUp(KeyType::SpaceBar))
	{
		// 슈팅
		_playerTurn = false;

		float percent = GET_SINGLE(UIManager)->GetPowerPercent();
		float speed = 10.f * percent;
		float angle = GET_SINGLE(UIManager)->GetBarrelAngle();

		Bullet* bullet = GET_SINGLE(ObjectManager)->CreateObject<Bullet>();
		bullet->SetOwner(this);
		bullet->SetPos(_pos);
		bullet->SetSpeed(Vector{ speed * ::cos(angle * PI / 180), -1 * speed * ::sin(angle * PI / 180)});
		GET_SINGLE(ObjectManager)->Add(bullet);
	}
}

void Player::Render(HDC hdc)
{
	if (_dir == Dir::LEFT)
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
		if (mesh)
			mesh->Render(hdc, _pos, 0.5f, 0.5f);
	}
	else
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
		if (mesh)
			mesh->Render(hdc, _pos, -0.5f, 0.5f);
	}

	if (_playerTurn)
	{
		RECT rect;
		rect.bottom = static_cast<LONG>(_pos.y - 60);
		rect.left = static_cast<LONG>(_pos.x - 10);
		rect.right = static_cast<LONG>(_pos.x + 10);
		rect.top = static_cast<LONG>(_pos.y - 80);

		HBRUSH brush = ::CreateSolidBrush(RGB(250, 236, 197));
		HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, brush);

		//Utils::DrawLine(hdc, _pos, GetFirePos());
		::Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);

		::SelectObject(hdc, oldBrush);
		::DeleteObject(brush);
	}
}

wstring Player::GetMeshKey()
{
	if (_playerType == PlayerType::MissileTank)
		return L"MissileTank";

	return L"CanonTank";
}

void Player::UpdateFireAngle()
{
	if (_dir == Dir::LEFT)
	{
		GET_SINGLE(UIManager)->SetPlayerAngle(180);
		GET_SINGLE(UIManager)->SetBarrelAngle(180 - _fireAngle);
	}
	else
	{
		GET_SINGLE(UIManager)->SetPlayerAngle(0);
		GET_SINGLE(UIManager)->SetBarrelAngle(_fireAngle);
	}
}
