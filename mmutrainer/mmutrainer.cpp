// Megaman Unlimited Trainer
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<Windows.h>
#include"proc.h"
#include"mem.h"
#include"ascii.h"
bool bScrews=false,bHealth=false,bAmmo=false,bLives=false,bShock=false;
bool bBeat=false,bEddie=false,bEtanks=false,bWtanks=false,bZprot=false;
void Menu()
{
	std::cout<<"HOTKEY = FUNCTIONS = STATUS\n";
	std::cout<<"===========================\n";
	std::cout<<"NUM0 = Infinite Screws = "<<bScrews<<"\n";
	std::cout<<"NUM1 = Infinite Health = "<<bHealth<< "\n";
	std::cout<<"NUM2 = Infinite Ammo = "<<bAmmo<<"\n";
	std::cout<<"NUM3 = Infinite Lives = "<<bLives<<"\n";
	std::cout<<"NUM4 = Infinite Shock Boots = "<<bShock<<"\n";
	std::cout<<"NUM5 = Infinite Beat Call = "<<bBeat<<"\n";
	std::cout<<"NUM6 = Infinite Eddie = "<<bEddie<<"\n";
	std::cout<<"NUM7 = Infinite E-Tanks = "<<bEtanks<<"\n";
	std::cout<<"NUM8 = Infinite W-Tanks = "<<bWtanks<<"\n";
	std::cout<<"NUM9 = Infinite Z Abilities = "<<bZprot<<"\n\n";
	std::cout<<"INSERT = EXIT TRAINER\n";
}
int main()
{
	HANDLE hProcess=0;
	uintptr_t moduleBase=0,localPlayerPtr=0,healthAddr=0;
	const int screwsMax=999,livesMax=9,shockMax=9,beatMax=9,eddieMax=9;
	const int etanksMax=4,wtanksMax=4,healthMax=99;
	const float ammoMax=28;
	DWORD procId=GetProcId(L"MMU.exe");
	if(procId)
	{
		hProcess=OpenProcess(PROCESS_ALL_ACCESS,NULL,procId);
		moduleBase=GetModuleBaseAddress(procId,L"MMU.exe");
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 9);
		AsciiArt();
		getchar();
		ClearScreen();
		Menu();
	}
	else
	{
		std::cout<<"MMU.exe process not found, press enter to exit\n";
		getchar();
		return(0);
	}
	DWORD dwExit=0;
	while(GetExitCodeProcess(hProcess,&dwExit)&&dwExit==STILL_ACTIVE)
	{
		localPlayerPtr=moduleBase+0x2C55F0;
		healthAddr=FindDMAAddy(hProcess,localPlayerPtr,{0xC,0x150});
		if(GetAsyncKeyState(VK_NUMPAD0)&1)
		{
			bScrews=!bScrews;
			if(bScrews)
			{
				mem::NopEx((BYTE*)(moduleBase+0x49A5),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x49A5),(BYTE*)"\x89\x48\x24",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bScrews)
		{
			mem::PatchEx((BYTE*)0x19FC3C,(BYTE*)&screwsMax,sizeof(screwsMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD1)&1)
		{
			bHealth=!bHealth;
			if(bHealth)
			{
				mem::NopEx((BYTE*)(moduleBase+0x1B01BA),6,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x1B01BA),(BYTE*)"\x89\x90\x50\x01\x00\x00",6,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bHealth)
		{
			mem::PatchEx((BYTE*)healthAddr,(BYTE*)&healthMax,sizeof(healthMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD2)&1)
		{
			bAmmo=!bAmmo;
			if(bAmmo)
			{
				mem::NopEx((BYTE*)(moduleBase+0x20ECC),2,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x20ECC),(BYTE*)"\xD9\x18",2,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(GetAsyncKeyState(VK_NUMPAD3)&1)
		{
			bLives=!bLives;
			if(bLives)
			{
				mem::NopEx((BYTE*)(moduleBase+0x49E5),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x49E5),(BYTE*)"\x89\x48\x2C",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bLives)
		{
			mem::PatchEx((BYTE*)0x19FC44,(BYTE*)&livesMax,sizeof(livesMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD4)&1)
		{
			bShock=!bShock;
			if(bShock)
			{
				mem::NopEx((BYTE*)(moduleBase+0x20D25),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x20D25),(BYTE*)"\x89\x48\x14",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bShock)
		{
			mem::PatchEx((BYTE*)0x19FC2C,(BYTE*)&shockMax,sizeof(shockMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD5)&1)
		{
			bBeat=!bBeat;
			if(bBeat)
			{
				mem::NopEx((BYTE*)(moduleBase+0x20CE5),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x20CE5),(BYTE*)"\x89\x48\x0C",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bBeat)
		{
			mem::PatchEx((BYTE*)0x19FC24,(BYTE*)&beatMax,sizeof(beatMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD6)&1)
		{
			bEddie=!bEddie;
			if(bEddie)
			{
				mem::NopEx((BYTE*)(moduleBase+0x29EE5),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x29EE5),(BYTE*)"\x89\x48\x10",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bEddie)
		{
			mem::PatchEx((BYTE*)0x19FC28,(BYTE*)&eddieMax,sizeof(eddieMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD7)&1)
		{
			bEtanks=!bEtanks;
			if(bEtanks)
			{
				mem::NopEx((BYTE*)(moduleBase+0x330E5),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x330E5),(BYTE*)"\x89\x48\x1C",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bEtanks)
		{
			mem::PatchEx((BYTE*)0x19FC34,(BYTE*)&etanksMax,sizeof(etanksMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD8)&1)
		{
			bWtanks=!bWtanks;
			if(bWtanks)
			{
				mem::NopEx((BYTE*)(moduleBase+0x4965),3,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x4965),(BYTE*)"\x89\x48\x20",3,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(bWtanks)
		{
			mem::PatchEx((BYTE*)0x19FC38,(BYTE*)&wtanksMax,sizeof(wtanksMax),hProcess);
		}
		if(GetAsyncKeyState(VK_NUMPAD9)&1)
		{
			bZprot=!bZprot;
			if(bZprot)
			{
				mem::NopEx((BYTE*)(moduleBase+0x1AD1D7),6,hProcess);
				mem::NopEx((BYTE*)(moduleBase+0x1AB834),6,hProcess);
				mem::NopEx((BYTE*)(moduleBase+0x1AD75D),6,hProcess);
				ClearScreen();
				Menu();
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase+0x1AD1D7),(BYTE*)"\x89\x81\x50\x01\x00\x00",6,hProcess);
				mem::PatchEx((BYTE*)(moduleBase+0x1AB834),(BYTE*)"\x89\x81\x50\x01\x00\x00",6,hProcess);
				mem::PatchEx((BYTE*)(moduleBase+0x1AD75D),(BYTE*)"\x89\x8A\x50\x01\x00\x00",6,hProcess);
				ClearScreen();
				Menu();
			}
		}
		if(GetAsyncKeyState(VK_INSERT)&1)
		{
			return(0);
		}
		Sleep(10);
	}
	ClearScreen();
	std::cout << "MMU.exe process not found, press enter to exit\n";
	getchar();
	return(0);
}