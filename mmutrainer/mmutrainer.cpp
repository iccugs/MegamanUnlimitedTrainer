// Megaman Unlimited Trainer
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"
#include "mem.h"
#include "ascii.h"

int main()
{
	HANDLE hProcess = 0;

	uintptr_t moduleBase = 0, localPlayerPtr = 0, healthAddr = 0;
	bool bScrews = false, bHealth = false, bAmmo = false, bLives = false, bShock = false;
	bool bBeat = false, bEddie = false, bEtanks = false, bWtanks = false, bZprot = false;

	const int screwsMax = 999, livesMax = 9, shockMax = 9, beatMax = 9, eddieMax = 9;
	const int etanksMax = 4, wtanksMax = 4, healthMax = 28;
	const float ammoMax = 28;

	//look for MMU.exe process
	DWORD procId = GetProcId(L"MMU.exe");

	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		//define moduleBase
		moduleBase = GetModuleBaseAddress(procId, L"MMU.exe");

		//set console colors
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 9);
		AsciiArt();
		getchar();
		ClearScreen();
		AsciiMenu();
		std::cout << "Infinite Screws = " << bScrews << std::endl;
		std::cout << "Infinite Health = " << bHealth << std::endl;
		std::cout << "Infinite Ammo = " << bAmmo << std::endl;
		std::cout << "Infinite Lives = " << bLives << std::endl;
		std::cout << "Infinite Shock Boots = " << bShock << std::endl;
		std::cout << "Infinite Beat Call = " << bBeat << std::endl;
		std::cout << "Infinite Eddie = " << bEddie << std::endl;
		std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
		std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
		std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
	}
	//exit trainer if process not found
	else
	{
		std::cout << "MMU.exe process not found, press enter to exit\n";
		getchar();
		return 0;
	}

	DWORD dwExit = 0;

	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		//define pointers
		localPlayerPtr = moduleBase + 0x2C55F0;
		healthAddr = FindDMAAddy(hProcess, localPlayerPtr, { 0xC,0x150 });

		//infinite screws toggle
		if (GetAsyncKeyState(VK_NUMPAD0) & 1)
		{
			bScrews = !bScrews;

			if (bScrews)
			{
				mem::PatchEx((BYTE*)0x19FC3C, (BYTE*)&screwsMax, sizeof(screwsMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x49A5), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x49A5), (BYTE*)"\x89\x48\x24", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite health toggle
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bHealth = !bHealth;

			if (bHealth)
			{
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//continuous write to health if infinite health is toggled
		if (bHealth)
		{
			mem::PatchEx((BYTE*)healthAddr, (BYTE*)&healthMax, sizeof(healthMax), hProcess);
		}

		//infinite ammo toggle
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			bAmmo = !bAmmo;

			if (bAmmo)
			{
				mem::NopEx((BYTE*)(moduleBase + 0x20ECC), 2, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x20ECC), (BYTE*)"\xD9\x18", 2, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite lives toggle
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			bLives = !bLives;

			if (bLives)
			{
				mem::PatchEx((BYTE*)0x19FC44, (BYTE*)&livesMax, sizeof(livesMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x49E5), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x49E5), (BYTE*)"\x89\x48\x2C", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite shock boots toggle
		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			bShock = !bShock;

			if (bShock)
			{
				mem::PatchEx((BYTE*)0x19FC2C, (BYTE*)&shockMax, sizeof(shockMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x20D25), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x20D25), (BYTE*)"\x89\x48\x14", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite beat toggle
		if (GetAsyncKeyState(VK_NUMPAD5) & 1)
		{
			bBeat = !bBeat;

			if (bBeat)
			{
				mem::PatchEx((BYTE*)0x19FC24, (BYTE*)&beatMax, sizeof(beatMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x20CE5), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x20CE5), (BYTE*)"\x89\x48\x0C", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite eddie toggle
		if (GetAsyncKeyState(VK_NUMPAD6) & 1)
		{
			bEddie = !bEddie;

			if (bEddie)
			{
				mem::PatchEx((BYTE*)0x19FC28, (BYTE*)&eddieMax, sizeof(eddieMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x29EE5), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x29EE5), (BYTE*)"\x89\x48\x10", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite e-tanks
		if (GetAsyncKeyState(VK_NUMPAD7) & 1)
		{
			bEtanks = !bEtanks;

			if (bEtanks)
			{
				mem::PatchEx((BYTE*)0x19FC34, (BYTE*)&etanksMax, sizeof(etanksMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x330E5), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x330E5), (BYTE*)"\x89\x48\x1C", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite w-tanks
		if (GetAsyncKeyState(VK_NUMPAD8) & 1)
		{
			bWtanks = !bWtanks;

			if (bWtanks)
			{
				mem::PatchEx((BYTE*)0x19FC38, (BYTE*)&wtanksMax, sizeof(wtanksMax), hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x4965), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x4965), (BYTE*)"\x89\x48\x20", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//infinite z abilities
		if (GetAsyncKeyState(VK_NUMPAD9) & 1)
		{
			bZprot = !bZprot;

			if (bZprot)
			{
				mem::NopEx((BYTE*)(moduleBase + 0x1AD1D7), 6, hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x1AB834), 6, hProcess);
				mem::NopEx((BYTE*)(moduleBase + 0x1AD75D), 6, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x1AD1D7), (BYTE*)"\x89\x81\x50\x01\x00\x00", 6, hProcess);
				mem::PatchEx((BYTE*)(moduleBase + 0x1AB834), (BYTE*)"\x89\x81\x50\x01\x00\x00", 6, hProcess);
				mem::PatchEx((BYTE*)(moduleBase + 0x1AD75D), (BYTE*)"\x89\x8A\x50\x01\x00\x00", 6, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Screws = " << bScrews << std::endl;
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Lives = " << bLives << std::endl;
				std::cout << "Infinite Shock Boots = " << bShock << std::endl;
				std::cout << "Infinite Beat Call = " << bBeat << std::endl;
				std::cout << "Infinite Eddie = " << bEddie << std::endl;
				std::cout << "Infinite E-Tanks = " << bEtanks << std::endl;
				std::cout << "Infinite W-Tanks = " << bWtanks << std::endl;
				std::cout << "Infinite Z Abilities = " << bZprot << std::endl;
			}
		}

		//exit
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			return 0;
		}
		Sleep(10);
	}
	ClearScreen();
	std::cout << "MMU.exe process not found, press enter to exit\n";
	getchar();
	return 0;
}