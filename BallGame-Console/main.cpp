#pragma once
#include "Map.h"
#include "GameLoop.h"



using namespace std;

int main()
{
	GameLoop *gameloop = new GameLoop();

	while(true)
	{
		gameloop->MainGameLoop();

		system("cls");

		char key;
		std::cout << "ponownie?: t/n";
		std::cin >> key;

		if( key == 't' )
		{
			continue;
		}
		else
		{
			break;
		}
	}

	delete gameloop;
}