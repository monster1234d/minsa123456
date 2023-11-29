#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define UP = 1;
#define DOWN = 2;
#define RIGHT = 3;
#define LEFT = 4;

int main() {

	int hp = 200;
	int d = 0;
	int playerX = 1;
	int playerY = 1;
	int move = 0;
	int map[10][10] =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,1,2,0,1},
		{1,0,2,1,0,0,0,0,0,1},
		{1,0,1,0,0,0,1,1,0,1},
		{1,0,1,1,1,0,1,0,0,1},
		{1,0,0,0,1,0,1,1,0,1},
		{1,0,1,0,1,0,1,0,0,1},
		{1,0,2,0,0,0,1,0,0,1},
		{1,0,0,1,0,0,1,1,3,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	while (1)

	{

		srand(time(NULL));

		move = (rand() % 4) + 1;

		system("cls");
		printf(">>> p: 유저, ▩ : 함정, □ : 벽,■ : 출구\n");
		printf("\n");
		printf(">>> 이동 횟수 : %d\n", d);
		printf("\n");
		printf(">>> healthpoint : %d\n", hp);
		printf("\n");
		for (int y = 0; y < 10; y++)

		{

			for (int x = 0; x < 10; x++)

			{
				if ((playerY == y) && (playerX == x))

				{

					printf("P ");

				}
				else
				{
					switch (map[y][x])

					{

					case 0:

						printf("  ");

						break;

					case 1:

						printf("□ ");

						break;

					case 2:

						printf("▩ ");

						break;

					case 3:

						printf("■ ");

						break;


					}
				}






			}

			printf("\n");

		}
		
		if (hp <= 0 || map[playerY][playerX] == 3)
		{
			map[playerY][playerX] = 0;
			printf("게임 종료");
			break;
		}

		Sleep(1000);



		switch (move)
		{

		case 1:
			printf("  ");
			playerY--;
			printf("P ");
			d++;
			if (map[playerY][playerX] == 1)
			{
				
				playerY++;
				d--;

			}
			if (map[playerY][playerX] == 2)
			{
				map[playerY][playerX] = 0;
				hp -= 100;
			}

			break;
		case 2:
			printf("  ");
			playerY++;
			printf("P ");
			d++;
			if (map[playerY][playerX] == 1)
			{
				
				playerY--;
				d--;

			}
			if (map[playerY][playerX] == 2)
			{
				map[playerY][playerX] = 0;
				hp -= 100;
			}

			break;
		case 3:
			printf("  ");
			playerX++;
			printf("P ");
			d++;
			if (map[playerY][playerX] == 1)
			{
				
				playerX--;
				d--;

			}
			if (map[playerY][playerX] == 2)
			{
				map[playerY][playerX] = 0;
				hp -= 100;
			}

			break;
		case 4:
			printf("  ");
			playerX--;
			printf("P ");
			d++;
			if (map[playerY][playerX] == 1)
			{
				
				playerX++;
				d--;

			}
			if (map[playerY][playerX] == 2)
			{
				map[playerY][playerX] = 0;
				hp -= 100;

			}

			break;

		default:

			break;

		}
	

	}
}
