#pragma once
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>

struct Form
{
	WORD wordAtributes;
	std::string form;
	Form(WORD _wordAtributes, std::string _form)
	{
		form = _form;
		wordAtributes = _wordAtributes;
	}
};
