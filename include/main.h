#pragma once
#include <windows.h>
#include <stdio.h>

struct Spos
{
	short X;
	short Y;
};

extern "C" void drawLine(CHAR_INFO *screenBuffer, Spos pos, int len, CHAR_INFO symbol);
