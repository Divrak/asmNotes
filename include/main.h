#pragma once
#include <windows.h>
#include <stdio.h>

struct Spos
{
	short X;
	short Y;
};

extern "C" void drawLine(int *screenBuffer, Spos coords, int len, wchar_t symbol, short attribute);
