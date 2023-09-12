#include "pch.h"
#include "Monster.h"
#include "InputManager.h"

Monster::Monster() : Object(ObjectType::Monster)
{

}

Monster::~Monster()
{

}

void Monster::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 10;

	_pos = Pos{ 400, 300 };
#pragma region ���ﰢ
	/*_lookPos = Pos{ 500, 70 };
	_lookDir = _lookPos - _pos;
	_lookDir.Normalize();*/
#pragma endregion
}

void Monster::Update()
{
#pragma region ����
	/*Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();*/

	//// start -> end
	//Vector v1 = _end - _start;
	//
	//// start -> mousePos
	//Vector v2 = mousePos - _start;

	//float maxLength = v1.Length();
	//v1.Normalize();

	//float dot = v1.Dot(v2);
	//Pos pos = _start + v1 * dot;

	//if (dot < 0 || dot > maxLength)
	//	return;

	//_pos = pos;
#pragma endregion

}

void Monster::Render(HDC hdc)
{
#pragma region ����
	/*Utils::DrawCircle(hdc, _pos, 50);

	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldpen = (HPEN)::SelectObject(hdc, pen);
	{
		Utils::DrawLine(hdc, _start, _end);
	}

	::SelectObject(hdc, oldpen);
	::DeleteObject(pen);*/
#pragma endregion
#pragma region ����
	//// �ι� ���
	//HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	//HPEN oldPen = (HPEN)::SelectObject(hdc, (HGDIOBJ)pen);
	//{
	//	Utils::DrawLine(hdc, _pt1, _pt2);
	//	Utils::DrawLine(hdc, _pt2, _pt3);
	//	Utils::DrawLine(hdc, _pt3, _pt1);
	//}
	//::SelectObject(hdc, oldPen);
	//::DeleteObject(pen);

	////////////////////////

	//Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();
	//_pos = mousePos;

	//{
	//	Utils::DrawTextW(hdc, _pt1, L"P1");
	//	Utils::DrawTextW(hdc, _pt2, L"P2");
	//	Utils::DrawTextW(hdc, _pt3, L"P3");
	//	Utils::DrawLine(hdc, _pt1, mousePos);
	//}

	//Vector v12 = _pt2 - _pt1;
	//Vector v1m = mousePos - _pt1;
	//Vector v13 = _pt3 - _pt1;

	//v12.Normalize();
	//v1m.Normalize();
	//v13.Normalize();


	//float c1 = v12.Cross(v1m);
	//float c2 = v1m.Cross(v13);

	//if (c1 >= 0 && c2 >= 0)
	//{
	//	_pos = mousePos;
	//}
	//else
	//{
	//	_pos = { -1000, -1000 };
	//}

	//{
	//	POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
	//	wstring str = std::format(L"c1({0}) c2({1})", c1, c2);
	//	Utils::DrawTextW(hdc, { 20, 50 }, str);
	//}
#pragma endregion
#pragma region ���ﰢ�Լ�
	//Utils::DrawCircle(hdc, _pos, 100);

	//// �չ���
	//HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	//HPEN oldPen = (HPEN)::SelectObject(hdc, pen);
	//{
	//	Utils::DrawLine(hdc, _pos, _lookPos);
	//}
	//
	//::SelectObject(hdc, oldPen);
	//::DeleteObject(pen);

	////
	//Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();
	//Vector monsterToMouseDir = mousePos - _pos;
	//monsterToMouseDir.Normalize();

	//Vector dir = _lookDir;
	//dir.Normalize();

	//float dot = monsterToMouseDir.Dot(dir);
	//float radian = ::acos(dot);

	//// ������ ��(��)�� �ٲ��ִ� ����
	//float angle = radian * 180 / 3.14f;

	//// 1) �ٶ󺸴� ������ �޶��� ��� ����� ���� ����
	///*if (monsterToMouseDir.x < 0)
	//	angle = 360 - angle;*/

	//// 2) �ٶ󺸴� ������ �޶����� 360�� ǥ�Ⱑ ��
	///*float cross = _lookDir.Cross(monsterToMouseDir);
	//if (cross < 0)
	//	angle = 360 - angle;*/
	//{
	//	wstring str = std::format(L"angle ({0})", angle);
	//	Utils::DrawTextW(hdc, Pos{ 25, 50 }, str);
	//}
#pragma endregion
}