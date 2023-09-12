#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	virtual ~Bullet() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetAngle(float angle) { _angle = angle; }


protected:
	float _angle = 0.f;

	float _sumTime = 0.f;
	Object* _target = nullptr;
};