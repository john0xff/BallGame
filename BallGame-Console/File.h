//
//void Map::saveBestScore()
//{
//	if (this->_moneyScore > 0)
//	{
//		setPosition (0, 13); 
//		long size;
//
//		FILE *pFile;
//
//		pFile = fopen ("Best Score.txt", "ab");
//
//
//		char *name = new char[10];
//			
//		std::cout << "imie ";
//		std::cin >> name;
//
//		
//		fseek (pFile, 0, SEEK_END);
//		fprintf (pFile, "%s", name);
//
//		fflush (pFile);
//
//		fprintf (pFile, " %i.", this->_moneyScore);
//
//
//		fclose(pFile);
//	}
//
//}
//
//
//void Map::loadBestScore()
//{
//	FILE *pFile;
//	long size;
//
//	char tab_char[50];
//	char c = NULL;
//	int a = 1;
//	static char number = NULL;
//	static char number2 = NULL;
//
//	if( (pFile = fopen("Best Score.txt", "rb")) != NULL)
//	{
//		fseek (pFile, 0, SEEK_END);
//		size = ftell (pFile);
//		rewind (pFile);
//
//		if( size == 0 )
//		{
//			fclose (pFile);
//			return;
//		}
//
//		setPosition( this->_width + 3, a );
//
//		while( c != EOF )
//		{
//			c = fgetc( pFile );
//			
//			printf( "%c", c );
//
//			if( c == '.' )
//			{
//				setPosition( this->_width + 3, ++a );
//			}
//		}
//
//		rewind( pFile );
//
//		c = NULL;
//
//		while( c != EOF )
//		{
//			c = fgetc( pFile );
//			
//
//			if( c == 51 )
//			{
//				number = c;
//			}
//			else if( c == 54 )
//			{
//				number2 = c;
//			}
//
//		
//		}
//
//		char tab[] = { number, number2 };
//	
//	
//		setPosition( 20, 20 );
//		cout << tab;
//	}
//
//	fclose (pFile);
//}





//
//
//#include "Map.h"
//
//
//Map::Map(int height = 10, int width = 20, int obstacleCount2 = 1, int obstacleCount3 = 1)
//	: _height(height), _width(width), 
//	  _obstacleCount2(obstacleCount2), _obstacleCount3(obstacleCount3)
//{
//	this->_table = new char*[_height];
//
//	posBullet.x = 0;
//	posBullet.y = 5;
//
//	posObstacle.x = 8;
//	posObstacle.y = 0;
//
//	posObstacle2.x = 14;
//	posObstacle2.y = 0;
//
//	posObstacle3.x = 17;
//	posObstacle3.y = 0;
//
//	posRandom.x = 0;
//	posRandom.y = 0;
//
//	this->_pointCount = 0;
//	this->_moneyScore = 0;
//	this->_totalScore = 0;
//
//	this->_countBestScore = NULL;
//	this->arrayScores = new BestScore[ MAX_SAVE_SCORE ];
//
//	for( int i = 0; i < MAX_SAVE_SCORE; ++i )
//	{
//		for( int j = 0; j < MAX_CHAR; ++j )
//		{
//			this->arrayScores[ i ].name[ j ] = NULL;
//		}
//
//		this->arrayScores[ i ].score = NULL;
//	}
//
//	this->tmpAr.score = NULL;
//}
//
//Map::~Map()
//{
//	delete[] this->arrayScores;
//	
//
//	for(int y = 0; y < this->_height; ++y)
//	{
//		delete[] this->_table[y];
//	}
//
//	delete[] this->_table;
//}
//
//void Map::SetPosition(int x, int y) 
//{ 
//	HANDLE _output = GetStdHandle (STD_OUTPUT_HANDLE);
//	COORD pos = {x, y};
//	SetConsoleCursorPosition(_output, pos);
//}
//	
//void Map::DrawMap()
//{
//	for(int y = 0; y < this->_height; ++y)
//	{
//		this->_table[y] = new char[this->_width];
//
//		char *&row = this->_table[y];
//
//		for(int x = 0; x < this->_width; ++x)
//		{
//			row[x] = _backgroundChar;
//			cout << row[x];
//		}
//			
//		cout << endl;
//	}
//}
//
//bool Map::MarkBullet()
//{
//	if(this->posBullet.x >= this->_width - 1)
//	{
//		this->posBullet.x = 0;
//
//		return false;
//	}
//
//	char &value = this->_table[this->posBullet.y][this->posBullet.x];
//
//
//	if(value == _randChar)
//	{
//		--this->_pointCount;
//		++this->_moneyScore;
//	}
//
//	value = _bulletChar;
//
//	SetPosition(this->posBullet.x, this->posBullet.y);
//	cout << _bulletChar;
//
//	return true;
//}
//
//bool Map::UnmarkBullet()
//{
//	if(BulletConditions() == false)
//	{
//		return false;
//	}
//
//	char &value = this->_table[this->posBullet.y][this->posBullet.x];
//	value = _backgroundChar;
//
//	SetPosition(this->posBullet.x, this->posBullet.y);
//	cout << value;
//
//	++this->posBullet.x;
//
//	return true;
//}
//
//void Map::MoveBulletUp()
//{
//	UnmarkAim();
//
//	char &value = this->_table[this->posBullet.y][this->posBullet.x];
//	value = _backgroundChar;
//
//	SetPosition(this->posBullet.x, this->posBullet.y);
//	cout << _backgroundChar;
//
//	--this->posBullet.y;
//
//	if(this->posBullet.y < 0)
//		++this->posBullet.y;
//
//	value = this->_table[this->posBullet.y][this->posBullet.x];
//	value = _bulletChar;
//
//	SetPosition(this->posBullet.x, this->posBullet.y);
//	cout << _bulletChar;
//
//	MarkAim();
//}
//
//void Map::MoveBulletDown()
//{
//	UnmarkAim();
//
//	char &value = this->_table[this->posBullet.y][this->posBullet.x];
//	value = _backgroundChar;
//
//	SetPosition(this->posBullet.x, this->posBullet.y);
//	cout << _backgroundChar;
//
//	++this->posBullet.y;
//
//	if(this->posBullet.y > this->_height - 1)
//		--this->posBullet.y;
//
//	value = this->_table[this->posBullet.y][this->posBullet.x];
//	value = _bulletChar;
//
//	SetPosition(this->posBullet.x, this->posBullet.y);
//	cout << _bulletChar;
//
//	MarkAim();
//}
//
//bool Map::BulletConditions()
//{
//	char &value = this->_table[this->posBullet.y][this->posBullet.x];
//		
//	if(value == _obstalceChar)
//	{
//		SetPosition( 0, this->_height + 2 );
//		cout << "Crash !";
//		Sleep(500);
//		return false;
//	}
//
//	return true;
//}
//
//void Map::MarkAim()
//{
//	char &value = this->_table[this->posBullet.y][this->_width - 1];
//	value = _aimChar;
//
//	SetPosition(this->_width - 1, this->posBullet.y);
//	cout << _aimChar;
//}
//
//void Map::UnmarkAim()
//{
//	char &value = this->_table[this->posBullet.y][this->_width - 1];
//	value = _backgroundChar;
//
//	SetPosition(this->_width - 1, this->posBullet.y);
//	cout << _backgroundChar;
//}
//
//void Map::MarkObstacle()
//{
//	if(this->posObstacle.y >= this->_height)
//	{
//		this->posObstacle.y = 0;
//	}
//
//	char &value = this->_table[this->posObstacle.y][this->posObstacle.x];
//	value = _obstalceChar;
//
//	SetPosition(this->posObstacle.x, this->posObstacle.y);
//	cout << _obstalceChar;
//
//
//
//	char &value2 = this->_table[this->posObstacle2.y][this->posObstacle2.x];
//	value2 = _obstalceChar;
//
//	SetPosition(this->posObstacle2.x, this->posObstacle2.y);
//	cout << _obstalceChar;
//
//
//
//	char &value3 = this->_table[this->posObstacle3.y][this->posObstacle3.x];
//	value3 = _obstalceChar;
//
//	SetPosition(this->posObstacle3.x, this->posObstacle3.y);
//	cout << _obstalceChar;
//}
//
//void Map::UnmarkObstalce()
//{
//	char &value = this->_table[this->posObstacle.y][this->posObstacle.x];
//	value = _backgroundChar;
//
//	SetPosition(this->posObstacle.x, this->posObstacle.y);
//	cout << _backgroundChar;
//
//	++this->posObstacle.y;
//}
//
//void Map::MarkObstacle2()
//{
//	this->UnmarkObstacle2();
//
//	if(this->posObstacle2.y >= this->_height - 1)
//	{
//		this->posObstacle2.y = 0;
//
//		return;
//	}
//
//	++this->posObstacle2.y;
//
//
//	char &value2 = this->_table[this->posObstacle2.y][this->posObstacle2.x];
//	value2 = _obstalceChar;
//		
//	SetPosition(this->posObstacle2.x, this->posObstacle2.y);
//	cout << _obstalceChar;
//
//}
//
//void Map::UnmarkObstacle2()
//{
//	char &value2 = this->_table[this->posObstacle2.y][this->posObstacle2.x];
//	value2 = _backgroundChar;
//
//	SetPosition(this->posObstacle2.x, this->posObstacle2.y);
//	cout << _backgroundChar;
//}
//
//void Map::MarkObstacle3()
//{
//	this->UnmarkObstacle3();
//
//	if(this->posObstacle3.y >= this->_height - 1)
//	{
//		this->posObstacle3.y = 0;
//
//		return;
//	}
//
//	++this->posObstacle3.y;
//
//
//	char &value3 = this->_table[this->posObstacle3.y][this->posObstacle3.x];
//	value3 = _obstalceChar;
//		
//	SetPosition(this->posObstacle3.x, this->posObstacle3.y);
//	cout << _obstalceChar;
//}
//
//void Map::UnmarkObstacle3()
//{
//	char &value3 = this->_table[this->posObstacle3.y][this->posObstacle3.x];
//	value3 = _backgroundChar;
//
//	SetPosition(this->posObstacle3.x, this->posObstacle3.y);
//	cout << _backgroundChar;
//}
//
//bool Map::MoveObstacles()
//{
//	MarkObstacle();
//
//	if(this->_obstacleCount2 == 2)
//	{
//		MarkObstacle2();
//	}
//
//	if(this->_obstacleCount3 == 3)
//	{
//		MarkObstacle3();
//	}
//
//	if(BulletConditions() == false)
//	{
//		return false;
//	}
//
//	Sleep(100);
//
//	UnmarkObstalce();
//
//	if(this->_obstacleCount2 == 2)
//	{
//		this->_obstacleCount2 = 1;
//	}
//	else
//	{
//		++this->_obstacleCount2;
//	}
//
//	if(this->_obstacleCount3 == 3)
//	{
//		this->_obstacleCount3 = 1;
//	}
//	else
//	{
//		++this->_obstacleCount3;
//	}
//
//	return true;
//}
//
//void Map::RandomPoints()
//{
//	while(this->RandomPoint() != true);
//}
//
//bool Map::RandomPoint()
//{
//	if(this->_pointCount >= _pointLimit)
//	{
//		return true;
//	}
//
//	this->posRandom.x = ((double)rand() / (double)RAND_MAX) * (this->_width - 1) + 0.5;
//	this->posRandom.y = ((double)rand() / (double)RAND_MAX) * (this->_height - 1) + 0.5;
//
//
//	if(this->ConditionRandom() == false)
//		return false;
//		
//	++this->_pointCount;
//
//	char &value = this->_table[this->posRandom.y][this->posRandom.x];
//	value = _randChar;
//
//	SetPosition(this->posRandom.x, this->posRandom.y);
//	cout << _randChar;
//
//	return true;
//}
//
//bool Map::ConditionRandom()
//{
//	if(this->posRandom.x == this->posBullet.x)
//	{
//		return false;
//	}
//	else if(this->posRandom.x == this->posObstacle.x)
//	{
//		return false;
//	}
//	else if(this->posRandom.x == this->posObstacle2.x)
//	{
//		return false;
//	}
//	else if(this->posRandom.x == this->posObstacle3.x)
//	{
//		return false;
//	}
//	else if(this->posRandom.x == this->_width - 1)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//void Map::ShowScore()
//{
//	int time = (clock() / 1000);
//
//	SetPosition(0, this->_height);
//	std::cout << "Money: " 
//			<< this->_moneyScore
//			<< " $";
//
//	SetPosition(0, this->_height + 1);
//	std::cout << "Time:  " 
//			<< time 
//			<< " sec";	
//}
//
//
//
//bool Map::SaveBestScore()
//{
//	if ( this->_moneyScore > 0 )
//	{
//		++this->_countBestScore;
//		// jesli w pliku jest 5 x wynikow
//		// zanim zwroci false musi sprawdzic czy gracz nie wpisal sie na lise 
//		if( this->_countBestScore > MAX_SAVE_SCORE )
//			return false;
//
//		pFile = fopen ( "Best Score.dat", "w+b" );
//
//		fwrite( &_countBestScore, sizeof( short ), 1, pFile ); 
//		// &_countBestScore dzialamy na adresie 1 zmiennej po to zeby 
//		// wiedziec ilu graczy mamy zapisanych :) zm aktualizowana co zmiane w pliku
//
//		this->GetInfo( &arrayScores[ this->_countBestScore - 1 ] );
//
//		// petla wysylajaca 2 zmienne do sortowania
//
//		if( this->_countBestScore > 0 );
//			this->SortScore( &arrayScores[ 0 ], &arrayScores[ 1 ] );
//
//		fwrite( this->arrayScores, sizeof( BestScore ), this->_countBestScore, pFile );
//		
//		fclose( pFile );
//	}
//
//	return true; 
//}
//
//bool Map::SortScore( BestScore * sort, BestScore * sort1 )
//{
//	if( sort->score > sort1->score )
//	{
//		return true;
//	}
//	else
//	{
//		this->tmpAr = this->arrayScores[ 1 ];
//		this->arrayScores[ 1 ] = this->arrayScores [ 0 ];
//		this->arrayScores[ 0 ] = this->tmpAr;
//	}
//
//	return true;
//}
//
//void Map::GetInfo( BestScore * info )
//{
//	SetPosition( 0, this->_height + 4 );
//	std::cout << "Max 5 signs";
//
//	SetPosition( 0, this->_height + 3 ); 
//
//	std::cout << "Please, your name: ";
//	std::cin >> info->name;
//
//	if( strlen( info->name ) >= MAX_CHAR )
//		info->name[ MAX_CHAR - 1 ] = '\0';
//
//	info->score = this->_moneyScore;
//}
//
//void Map::PutsTop()
//{
//	SetPosition( this->_width + 5, 0 );
//	std::cout << "Top Best:";
//}
//
//void Map::LoadBestScore()
//{
//	if(( pFile = fopen( "Best Score.dat", "rb" )) != NULL )
//	{
//		this->PutsTop();
//
//		fread( &_countBestScore, sizeof( short ), 1, pFile );
//
//		fread( this->arrayScores, sizeof( BestScore ), this->_countBestScore, pFile );
//
//		for( int n = 1; n < this->_countBestScore + 1; ++n )
//		{
//			SetPosition( this->_width + 5, n );
//
//			std::cout << n << ". ";
//
//			this->DrawInfo( &arrayScores[ n - 1 ] );
//		}
//
//		fclose( pFile );
//	}
//}
//
//void Map::DrawInfo( BestScore * info )
//{
//	std::cout << info->name;
//
//	int spaceSize = MAX_CHAR - strlen( info->name );
//
//	for(int i = 0; i < spaceSize; ++i)
//		std::cout << " ";
//
//
//	/*for(int i = MAX_CHAR - strlen( info->name ); i >= 1; --i)
//		std::cout << " ";*/
//	
//
//	/*if( strlen( info->name ) == MAX_CHAR - 1 )
//		std::cout << " ";
//	else if( strlen( info->name ) == MAX_CHAR - 2 )
//		std::cout << "  ";
//	else if( strlen( info->name ) == MAX_CHAR - 3 )
//		std::cout << "   ";
//	else if( strlen( info->name ) == MAX_CHAR - 4 )
//		std::cout << "    ";
//	else if( strlen( info->name ) == MAX_CHAR - 5 )
//		std::cout << "     ";*/
//
//	std::cout << info->score;
//}
//
//#include "Map.h"
//
//
//
//using namespace std;
//
//int main()
//{
//	
//	//
//	Map *map = new Map(  10, 20, 1, 1 );
//
//	
//	map->DrawMap();
//	map->MarkAim();
//	map->LoadBestScore();	
//
//	while(true)
//	{
//		map->MarkBullet();
//
//		map->RandomPoints();
//
//		map->MoveObstacles();
//
//		map->ShowScore();
//
//
//		if(_kbhit())
//		{
//			char key = _getch();
//
//			switch(key)
//			{
//			case 'w':
//				{
//					map->MoveBulletUp();
//				}
//				break;
//
//			case 's':
//				{
//					map->MoveBulletDown();
//				}
//				break;
//
//			case 32:
//				{
//					do
//					{
//						map->ShowScore();
//
//						map->MarkBullet();
//	
//						map->MoveObstacles();
//
//						map->UnmarkBullet();
//
//						if( map->BulletConditions() == false )
//							break;
//
//					}while( map->MarkBullet() != false );
//				}
//			}
//		}
//		if(map->BulletConditions() == false)
//			break;
//
//		continue;
//	}
//
//	map->SaveBestScore();
//
//	map->~Map();
//
//
//	system("cls");
//
//	char key;
//	std::cout << "ponownie?: t/n";
//	std::cin >> key;
//
//	if( key == 't' )
//	{
//		
//	}
//
//	_getch();
//}