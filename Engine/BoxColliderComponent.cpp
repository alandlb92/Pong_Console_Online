#include "BoxColliderComponent.h"
#include "ActorBase.h"
#include <stdexcept>

BoxColliderComponent::BoxColliderComponent(int width, int height) : isInCollision(false)
{
	if (width < 1 || height < 1)
		throw std::invalid_argument("Colliders width and height must be greater than 0");

	super::_isPhysicsComponent = true;
	_widht = width;
	_height = height;
}

void BoxColliderComponent::FixedUpdate(double Time)
{
	super::FixedUpdate(Time);
}

void BoxColliderComponent::GetExtends(Vector2& result)
{
	int x = int (BaseActor->transform->position.x + (_widht - 1));
	int y = int (BaseActor->transform->position.y + (_height - 1));
	result = Vector2((float)x, (float)y);
}


void BoxColliderComponent::GetMin(Vector2& result)
{
	Vector2 extends;
	GetExtends(extends);
	result.x = extends.x > BaseActor->transform->position.x ? BaseActor->transform->position.x : extends.x;
	result.y = extends.y > BaseActor->transform->position.y ? BaseActor->transform->position.y : extends.y;
}


void BoxColliderComponent::GetMax(Vector2& result)
{
	Vector2 min;
	Vector2 extends;
	GetExtends(extends);
	result.x = extends.x < BaseActor->transform->position.x ? BaseActor->transform->position.x : extends.x;
	result.y = extends.y < BaseActor->transform->position.y ? BaseActor->transform->position.y : extends.y;
}