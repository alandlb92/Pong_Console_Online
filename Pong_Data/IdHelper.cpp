#include "IdHelper.h"

int IdHelper::_lastId = 0;

int IdHelper::GetNewId()
{
	return ++_lastId;
}