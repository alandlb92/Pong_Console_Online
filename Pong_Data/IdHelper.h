#pragma once
class IdHelper
{
private:
	static int _lastId;
public:
	static int GetNewId();
};

