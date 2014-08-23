#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#include "Types.h"



using namespace std;


class Map
{
private:
	
	FILE *pFile;
	const int _height;
	const int _width;
	int _obstacleCount2;
	int _obstacleCount3;
	int _pointCount;
	int _moneyScore;
	double _totalScore;
	


	char **_table;

	static const char _bulletChar = 'o';
	static const char _backgroundChar = '.';
	static const char _obstalceChar = '|';
	static const char _aimChar = ']';
	static const char _randChar = '$';
	static const int _pointLimit = 1;
	

	Point2D posBullet;
	Point2D posObstacle;
	Point2D posObstacle2;
	Point2D posObstacle3;
	Point2D posRandom;

	
	BestScore *arrayScores;
	short _countBestScore;

	//BestScore tmpAr; 
	BestScore tmpAr;

public:
	Map( int height, int width, int obstacleCount2, int obstacleCount3 );
		
	~Map();

	void SetPosition( int x, int y );

	// Rysuje mape.
	//
	void DrawMap();
	
	// Zaznacza kulke. Sprawdza pozycje kulki i pieniadza. Liczy punkty.
	// 
	bool MarkBullet();

	// Odznacza kulke. Dodaje 1 pozycje x kulce.
	//
	bool UnmarkBullet();
	
	// Ruch kulki w gore.
	//
	void MoveBulletUp();
	
	// Ruch kulki w dol.
	//
	void MoveBulletDown();
	
	// Koñczy wczesniej gre w celu zapisania wynkiu bez zdezenia z przeszkoda.
	//
	void EarlyEndOfGame();

	// Sprawdza czy kulka nie jest na pozycji przeszkody.
	//
	bool BulletConditions();
	
	// Zaznacza cel.
	//
	void MarkAim();
	
	// Odznacza cel.
	//
	void UnmarkAim();
	
	// Co 1 iteracje glownej petli zaznacza wszystkie przeszkody.
	// Zeruje pozycje przeszkody1 jesli > wysokosci mapy.
	//
	void MarkObstacle();

	// Odznacza przeszkode1. Dodaje 1 pozycje y przeszkodzie1.
	//
	void UnmarkObstalce();
	
	// Odznaczenie przeszkody2. 
	// Zeruje pozycje przeszkody2 jesli > wysokosci mapy.
	// Dodaje 1 pozycje y przeszkodzie2. Zaznacza przeszkode2.
	//
	void MarkObstacle2();

	// Odznacza przeszkode2.
	//
	void UnmarkObstacle2();
	
	// Odznaczenie przeszkody3. 
	// Zeruje pozycje przeszkody3 jesli > wysokosci mapy.
	// Dodaje 1 pozycje y przeszkodzie3. Zaznacza przeszkode3.
	//
	void MarkObstacle3();
	
	// Odznacza przeszkode3.
	//
	void UnmarkObstacle3();
	
	// Ruch i warunki wywolan wszystkich przeszkod. 
	//
	bool MoveObstacles();
	
	// Sprawdza czy moze wylosowac punkt.
	//
	void RandomPoints();
	
	// Losuje i zaznacza punkt na mapie po sprawdzeniu odpowiednich warunkow.
	//
	bool RandomPoint();
	
	// Warunki sprawdzajace czy wylosowana pozycja nie jest pozycja gracza lub przeszkod.
	//
	bool ConditionRandom();

	// Wyswietla wynik i odliczanie czasu.
	//
	void ShowScore();

	// Wypisuje napis Top Best:
	//
	void PutsTop();

	// Wczytuje dane z pliku do tablicy[ MAX_SAVE_SCORE - 1 ];
	//
	void LoadBestScore();

	// Wspolpracuje z LoadBestScore().
	// Wypisuje z pliku wyniki na ekran.
	//
	void DrawInfo( BestScore * info);


	// Zapis gracza. Imie i punkty.
	// Wywoluje Getinfo() i SortScore().
	//
	bool SaveBestScore();

	// Wspolpracuje z SaveBestScore().
	// Pobiera dane od gracza do zapisu.
	//
	void GetInfo( BestScore * info );
};
