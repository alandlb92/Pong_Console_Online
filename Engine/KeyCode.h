#pragma once
#include <iostream>
enum class KeyCode
{
	UpArrow,
	DownArrow,
	RightArrow,
	LeftArrow,
	Escape

};
class KeyCodeUtils
{
public:
	static std::string KeyCodeToString(KeyCode key)
	{
		switch (key)
		{
		case KeyCode::UpArrow:
			return "UpArrow";
			break;
		case KeyCode::DownArrow:
			return "DownArrow";
			break;
		case KeyCode::RightArrow:
			return "RightArrow";
			break;
		case KeyCode::LeftArrow:
			return "LeftArrow";
			break;
		case KeyCode::Escape:
			return "Escape";
			break;
		default:
			return "Not found";
			break;
		}
	};
};