#include "stdafx.h"
#include "ascii.h"

void AsciiArt()
{
	std::cout << "___  ___                  ___  ___            " << std::endl;
	std::cout << "|  \\/  |                  |  \\/  |            " << std::endl;
	std::cout << "| .  . | ___  __ _  __ _  | .  . | __ _ _ __  " << std::endl;
	std::cout << "| |\\/| |/ _ \\/ _` |/ _` | | |\\/| |/ _` | '_ \\ " << std::endl;
	std::cout << "| |  | |  __/ (_| | (_| | | |  | | (_| | | | |" << std::endl;
	std::cout << "\\_|  |_/\\___|\\__, |\\__,_| \\_|  |_/\\__,_|_| |_|" << std::endl;
	std::cout << "              __/ |                           " << std::endl;
	std::cout << "             |___/                            " << std::endl;
	std::cout << "  _   _       _ _           _ _           _   " << std::endl;
	std::cout << " | | | |     | (_)         (_) |         | |  " << std::endl;
	std::cout << " | | | |_ __ | |_ _ __ ___  _| |_ ___  __| |  " << std::endl;
	std::cout << " | | | | '_ \\| | | '_ ` _ \\| | __/ _ \\/ _` |  " << std::endl;
	std::cout << " | |_| | | | | | | | | | | | | ||  __/ (_| |  " << std::endl;
	std::cout << "  \\___/|_| |_|_|_|_| |_| |_|_|\\__\\___|\\__,_|  " << std::endl;
	std::cout << "                                              " << std::endl;
	std::cout << "                                              " << std::endl;
	std::cout << "       _____         _                        " << std::endl;
	std::cout << "      |_   _|       (_)                       " << std::endl;
	std::cout << "        | |_ __ __ _ _ _ __   ___ _ __        " << std::endl;
	std::cout << "        | | '__/ _` | | '_ \\ / _ \\ '__|       " << std::endl;
	std::cout << "        | | | | (_| | | | | |  __/ |          " << std::endl;
	std::cout << "        \\_/_|  \\__,_|_|_| |_|\\___|_|          " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "                                   By: Paradox" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "press enter to continue..." << std::endl;
}

void AsciiMenu()
{
	std::cout << "TOGGLE FUNCTIONS:" << std::endl;
	std::cout << "NUM0 = Infinite Screws" << std::endl;
	std::cout << "NUM1 = Infinite Health" << std::endl;
	std::cout << "NUM2 = Infinite Ammo" << std::endl;
	std::cout << "NUM3 = Infinite Lives" << std::endl;
	std::cout << "NUM4 = Infinite Shock Boots" << std::endl;
	std::cout << "NUM5 = Infinite Beat Call" << std::endl;
	std::cout << "NUM6 = Infinite Eddie" << std::endl;
	std::cout << "NUM7 = Infinite E-Tanks" << std::endl;
	std::cout << "NUM8 = Infinite W-Tanks" << std::endl;
	std::cout << "NUM9 = Infinite Z Abilities" << std::endl;
	std::cout << "Press INSERT to exit the trainer" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Hack Status:" << std::endl;
}

void ClearScreen()
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count, cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	//get number of cells in current buffer
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	//fill buffer with spaces
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	//fill buffer with current colors and attributes
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	//move cursor home
	SetConsoleCursorPosition(hStdOut, homeCoords);
}