#include "Component.h"
#include <algorithm>
#include "ActorBase.h"

void Component::Start()
{
}

void Component::Update(double DeltaTime)
{
}


void Component::FixedUpdate(double Time)
{

}

void Component::SetBaseActor(ActorBase* baseActor)
{
	BaseActor = baseActor;
}