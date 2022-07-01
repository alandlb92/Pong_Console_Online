#pragma once
struct Color
{
	unsigned __int8 r;
	unsigned __int8 g;
	unsigned __int8 b;

	Color()
	{
		r = 0;
		g = 0;
		b = 0;
	}

	Color(__int8 _r, __int8 _g, __int8 _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}
};
