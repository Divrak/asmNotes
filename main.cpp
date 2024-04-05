#include "main.h"


int main(void)
{
	HANDLE stdHandle, screenBufferHandle;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo {};
	CHAR_INFO *screenBuffer;
	COORD screenBufferPos {};
	int screenBufferSize {};

	stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	screenBufferHandle = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CONSOLE_TEXTMODE_BUFFER, 0); 

	if (stdHandle == INVALID_HANDLE_VALUE || screenBufferHandle == INVALID_HANDLE_VALUE)
	{
		printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	//Make the new screen buffer the active screen buffer
	if (!SetConsoleActiveScreenBuffer(screenBufferHandle))
	{
		printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	if (!GetConsoleScreenBufferInfo(screenBufferHandle, &screenBufferInfo))
	{
		printf("GetConsoleScreenBufferInfo failed - (%d)\n", GetLastError());
		return 1;
	}

	screenBufferSize = static_cast<int>(screenBufferInfo.dwSize.X) * static_cast<int>(screenBufferInfo.dwSize.Y);
	screenBuffer = new CHAR_INFO[screenBufferSize];
	memset(screenBuffer, 0, screenBufferSize * sizeof(CHAR_INFO));

	drawLine((int*)screenBuffer, 2, 1, 10, L'-', 0x50);
	//Copy from the remporary buffer to the new screen buffer
	if(!WriteConsoleOutput( screenBufferHandle, screenBuffer, screenBufferInfo.dwSize, screenBufferPos, &screenBufferInfo.srWindow))
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
		return 1;
	}
	Sleep(5000);

	//Restore the original active screen buffer
	if (!SetConsoleActiveScreenBuffer(stdHandle))
	{
		printf("SetConsoleActiveBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	return 0;
}

