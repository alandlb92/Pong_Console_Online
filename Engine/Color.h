#pragma once
#include <iostream>
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
