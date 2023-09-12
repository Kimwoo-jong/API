#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	Monster();
	virtual ~Monster() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	// 내적을 이용
	/*Vector _start = { 400, 100 };
	Vector _end = { 600, 250 };*/

	// 외적을 이용
	/*Vector _pt1 = { 400, 150 };
	Vector _pt2 = { 600, 450 };
	Vector _pt3 = { 200, 450 };*/

	// 역삼각함수를 이용한 백어택 판정 만들기
	/*Vector _lookPos = {};
	Vector _lookDir = {};*/
};