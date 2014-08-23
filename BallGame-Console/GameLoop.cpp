#pragma once
#include "GameLoop.h"
#include "Map.h"

GameLoop::GameLoop(void)
{
}


GameLoop::~GameLoop(void)
{
}

void GameLoop::MainGameLoop()
{
	system("cls");

	Map *map = new Map(  10, 20, 1, 1 );

	map->DrawMap();
	map->MarkAim();
	map->LoadBestScore();	

	while(true)
	{
		map->MarkBullet();
		map->RandomPoints();
		map->MoveObstacles();
		map->ShowScore();

		if(_kbhit())
		{
			char key = _getch();

			switch(key)
			{
			case 'w':
				{
					map->MoveBulletUp();
				}
				break;

			case 's':
				{
					map->MoveBulletDown();
				}
				break;

			case 'l':
				{
					map->EarlyEndOfGame();
				}
				break;

			case 32:
				{
					do
					{
						map->ShowScore();
						map->MarkBullet();
						map->MoveObstacles();
						map->UnmarkBullet();

						if( map->BulletConditions() == false )
							break;

					}while( map->MarkBullet() != false );
				}
			}
		}
		if(map->BulletConditions() == false)
			break;

		continue;
	}
	map->SaveBestScore();

	map->~Map();

	//delete map;
}
