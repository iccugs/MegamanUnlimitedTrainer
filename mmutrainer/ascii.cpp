#include "stdafx.h"
#include "ascii.h"
void AsciiArt()
{
	std::cout << "___  ___                  ___  ___\n";
	std::cout << "|  \\/  |                  |  \\/  |\n";
	std::cout << "| .  . | ___  __ _  __ _  | .  . | __ _ _ __\n";
	std::cout << "| |\\/| |/ _ \\/ _` |/ _` | | |\\/| |/ _` | '_ \\\n";
	std::cout << "| |  | |  __/ (_| | (_| | | |  | | (_| | | | |\n";
	std::cout << "\\_|  |_/\\___|\\__, |\\__,_| \\_|  |_/\\__,_|_| |_|\n";
	std::cout << "              __/ |\n";
	std::cout << "             |___/\n";
	std::cout << "  _   _       _ _           _ _           _\n";
	std::cout << " | | | |     | (_)         (_) |         | |\n";
	std::cout << " | | | |_ __ | |_ _ __ ___  _| |_ ___  __| |\n";
	std::cout << " | | | | '_ \\| | | '_ ` _ \\| | __/ _ \\/ _` |\n";
	std::cout << " | |_| | | | | | | | | | | | | ||  __/ (_| |\n";
	std::cout << "  \\___/|_| |_|_|_|_| |_| |_|_|\\__\\___|\\__,_|\n\n\n";
	std::cout << "       _____         _\n";
	std::cout << "      |_   _|       (_)\n";
	std::cout << "        | |_ __ __ _ _ _ __   ___ _ __\n";
	std::cout << "        | | '__/ _` | | '_ \\ / _ \\ '__|\n";
	std::cout << "        | | | | (_| | | | | |  __/ |\n";
	std::cout << "        \\_/_|  \\__,_|_|_| |_|\\___|_|\n\n";
	std::cout << "                                   By: Paradox\n\n";
	std::cout << "press enter to continue...\n";
}
void ClearScreen()
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count,cellCount;
	COORD homeCoords={0,0};
	hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	if(hStdOut==INVALID_HANDLE_VALUE)return;
	if(!GetConsoleScreenBufferInfo(hStdOut,&csbi))return;
	cellCount=csbi.dwSize.X*csbi.dwSize.Y;
	if(!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	))return;
	if(!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	))return;
	SetConsoleCursorPosition(hStdOut,homeCoords);
}