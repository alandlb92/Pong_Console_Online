#pragma once
#include "Component.h"
#include "Vector2.h"

class BoxColliderComponent : public Component
{
private:
	typedef Component super;
	int _widht;
	int _height;
	void GetExtends(Vector2& result);

public:
	bool isInCollision;
	BoxColliderComponent(int widht, int height);
	void GetMin(Vector2& result);
	void GetMax(Vector2& result);
	void FixedUpdate(double Time) override;

};

