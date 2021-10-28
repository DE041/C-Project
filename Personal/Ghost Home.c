#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

#define COMPLETE 100

int map_, job = 0, decoder = 4, item = 1, x = 13, y = 14;
int map[2][31][28] = {
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,3,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,3,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,5,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,0,6,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,7,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,1,1,0,8,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,9,0,1,1,1},
		{1,1,1,0,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,1,1,0,1,1,1},
		{1,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	},
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,5,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,6,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1},
		{1,1,1,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1},
		{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,0,0,2,0,0,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1},
		{1,1,1,0,1,1,0,1,1,0,1,1,1,7,1,1,1,0,1,1,0,1,1,0,1,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,1,1,0,8,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,9,0,1,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	}
};

enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};
void fullscreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };

	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void setcolor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void gotoxy(int x, int y) {
	COORD Pos;

	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int title(int x, int y) { // 출처 : ㅕㅇㄴ우
	char key;
	int check = 1;

	gotoxy(x + 1, y - 5); printf("고 스 트 홈");
	gotoxy(x, y - 1); printf("┌──────────┐");
	gotoxy(x, y + 1); printf("└──────────┘");

	gotoxy(x + 1, y); printf("   규 칙");
	gotoxy(x + 1, y + 2); printf("시 작 하 기");
	gotoxy(x + 1, y + 4); printf("  나 가 기");

	while (1) {
		key = _getch();

		if (key == 13) {
			return check;
		}
		else if (key == 80 && check < 3) {
			check++;
			y += 2;

			gotoxy(x, y - 3); printf("            ");
			gotoxy(x, y - 1); printf("┌──────────┐");
			gotoxy(x, y + 1); printf("└──────────┘");
		}
		else if (key == 72 && check > 1) {
			check--;
			y -= 2;

			gotoxy(x, y + 3); printf("            ");
			gotoxy(x, y - 1); printf("┌──────────┐");
			gotoxy(x, y + 1); printf("└──────────┘");
		}
	}
}
void run();

int main() {
	fullscreen();
	CursorView();

	switch (title(13, 10)) {
	case 1: {
		system("cls");
		printf("==============  EXPLANATION  ===============");

		printf("\n\n아래에 있는 5개의 직업 중 한 직업을 선택한 뒤, 각 직업마다");
		printf("\n가지고 있는 고유한 스킬들을 잘 활용하여 해독기를 해독해 탈출 하는 탈출 게임");

		printf("\n\n\n\t△ - 위");
		printf("\n\n◁ - 왼쪽\t▷ - 오른쪽\tSPACE - 해독  TAB - 아이템");
		printf("\n\n\t▽ - 아래");

		setcolor(VIOLET);
		printf("\n\n\n샤먼 : 정해진 범위에서 벗어나지 않게 맵 중 한곳으로 텔레포트 한다.");
		setcolor(GRAY);
		printf("\n리퍼 : 고스트에게 공격받아도 죽지 않는 은신 상태에 돌입한다. 은신은 움직이기 전까지 풀리지 않는다.");
		setcolor(YELLOW);
		printf("\n건축가 : 플레이어의 좌표에 한칸짜리 블럭 벽을 설치한다. 고스트는 이 벽을 통과할 수 없으며, 플레이어가 지나가면 사라진다.");
		setcolor(SKYBLUE);
		printf("\n탐정 : 일정 시간마다 해독에 큰 도움이 되는 단서를 얻는다. 단서를 해독 중에 사용하게 되면 해독률이 크게 증가한다.");
		setcolor(WHITE);
		printf("\n행운아 : 그저 행운아\n\n\n\n※ ");
		system("pause");
	}
	case 2: run();
	case 3: printf("\n"); return 0;
	}
}

int myrand(int ghost_x, int ghost_y) {
	static int random1, random2;

	srand(clock());
	if (job == 5) {
		random1 = rand() % 4 + 1;
		random2 = rand() % 4 + 1;
	}
	else {
		random1 = rand() % 19 + 1;
		random2 = rand() % 19 + 1;
	}

	if ((decoder < 3 && ((abs(x - ghost_x) > 10 || abs(y - ghost_y) > 10)) || (random1 == random2))) {
		if (random1 > 4) random1 /= 4;
		return random1;
	}
	else {
		if (abs(x - ghost_x) > abs(y - ghost_y)) {
			if (ghost_x > x) return 1;
			else if (ghost_x < x) return 3;
			else if (ghost_y > y) return 2;
			else if (ghost_y < y) return 4;
		}
		else {
			if (ghost_y > y) return 2;
			else if (ghost_y < y) return 4;
			else if (ghost_x > x) return 1;
			else if (ghost_x < x) return 3;
		}
	}
}
void dieprint(int x, int y) {
	system("cls");

	int originY = y;
	setcolor(RED);
	gotoxy(x, y++);
	printf("□□□□");
	gotoxy(x, y++);
	printf("□    □□");
	gotoxy(x, y++);
	printf("□      □");
	gotoxy(x, y++);
	printf("□      □");
	gotoxy(x, y++);
	printf("□    □□");
	gotoxy(x, y++);
	printf("□□□□");

	x += 13;
	y = originY;
	gotoxy(x, y++);
	printf("□□□");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("□□□");

	x += 10;
	y = originY;

	gotoxy(x, y++);
	printf("□□□□□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□□□□□");
	gotoxy(x, y++);
	printf("□□□□□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□□□□□");
}
void _stdcall ghost1(void* arg) {
	char moving;
	int direction, ghost_x = 1, ghost_y = 1, bb = 0;

	while (1) {
		srand(clock());
		direction = myrand(ghost_x, ghost_y);

		if (direction == 1 && (map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x - 1] == 2 || map[map_][ghost_y][ghost_x - 1] == 3) && bb != 3) {
			bb = 1;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 0 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 26;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 2 && map[map_][ghost_y][ghost_x - 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x - 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 2 && (map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y - 1][ghost_x] == 2 || map[map_][ghost_y - 1][ghost_x] == 3) && bb != 4) {
			bb = 2;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 2 && map[map_][ghost_y - 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y - 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 3 && (map[map_][ghost_y][ghost_x + 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 2 || map[map_][ghost_y][ghost_x + 1] == 3) && bb != 1) {
			bb = 3;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 26 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 0;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 2 && map[map_][ghost_y][ghost_x + 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x + 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 4 && (map[map_][ghost_y + 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 2 || map[map_][ghost_y + 1][ghost_x] == 3) && bb != 2) {
			bb = 4;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x] != 2 && map[map_][ghost_y + 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y + 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}
void _stdcall ghost2(void* arg) {
	char moving;
	int direction, ghost_x = 25, ghost_y = 1, bb = 0;

	while (1) {
		srand(clock());
		direction = myrand(ghost_x, ghost_y);

		if (direction == 1 && (map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x - 1] == 2 || map[map_][ghost_y][ghost_x - 1] == 3) && bb != 3) {
			bb = 1;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 0 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 26;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 2 && map[map_][ghost_y][ghost_x - 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x - 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 2 && (map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y - 1][ghost_x] == 2 || map[map_][ghost_y - 1][ghost_x] == 3) && bb != 4) {
			bb = 2;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 2 && map[map_][ghost_y - 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y - 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 3 && (map[map_][ghost_y][ghost_x + 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 2 || map[map_][ghost_y][ghost_x + 1] == 3) && bb != 1) {
			bb = 3;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 26 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 0;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 2 && map[map_][ghost_y][ghost_x + 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x + 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 4 && (map[map_][ghost_y + 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 2 || map[map_][ghost_y + 1][ghost_x] == 3) && bb != 2) {
			bb = 4;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x] != 2 && map[map_][ghost_y + 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y + 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}
void _stdcall ghost3(void* arg) {
	char moving;
	int direction, ghost_x = 1, ghost_y = 28, bb = 0;

	while (1) {
		srand(clock());
		direction = myrand(ghost_x, ghost_y);

		if (direction == 1 && (map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x - 1] == 2 || map[map_][ghost_y][ghost_x - 1] == 3) && bb != 3) {
			bb = 1;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 0 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 26;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 2 && map[map_][ghost_y][ghost_x - 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x - 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 2 && (map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y - 1][ghost_x] == 2 || map[map_][ghost_y - 1][ghost_x] == 3) && bb != 4) {
			bb = 2;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 2 && map[map_][ghost_y - 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y - 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 3 && (map[map_][ghost_y][ghost_x + 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 2 || map[map_][ghost_y][ghost_x + 1] == 3) && bb != 1) {
			bb = 3;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 26 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 0;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 2 && map[map_][ghost_y][ghost_x + 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x + 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 4 && (map[map_][ghost_y + 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 2 || map[map_][ghost_y + 1][ghost_x] == 3) && bb != 2) {
			bb = 4;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x] != 2 && map[map_][ghost_y + 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y + 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}
void _stdcall ghost4(void* arg) {
	char moving;
	int direction, ghost_x = 25, ghost_y = 28, bb = 0;

	while (1) {
		srand(clock());
		direction = myrand(ghost_x, ghost_y);

		if (direction == 1 && (map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x - 1] == 2 || map[map_][ghost_y][ghost_x - 1] == 3) && bb != 3) {
			bb = 1;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 0 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 26;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 2 && map[map_][ghost_y][ghost_x - 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x - 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 2 && (map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y - 1][ghost_x] == 2 || map[map_][ghost_y - 1][ghost_x] == 3) && bb != 4) {
			bb = 2;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y--;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 2 && map[map_][ghost_y - 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y - 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 3 && (map[map_][ghost_y][ghost_x + 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 2 || map[map_][ghost_y][ghost_x + 1] == 3) && bb != 1) {
			bb = 3;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_x++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if (ghost_x == 26 && ghost_y == 14) {
					map[map_][ghost_y][ghost_x] = 0;
					ghost_x = 0;
					map[map_][ghost_y][ghost_x] = 3;
				}

				if ((map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 2 && map[map_][ghost_y][ghost_x + 1] != 3) || map[map_][ghost_y - 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 0) {
					if ((map[map_][ghost_y - 1][ghost_x] != 0 && map[map_][ghost_y - 1][ghost_x] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x + 1 == x && ghost_y == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
		else if (direction == 4 && (map[map_][ghost_y + 1][ghost_x] == 0 || map[map_][ghost_y + 1][ghost_x] == 2 || map[map_][ghost_y + 1][ghost_x] == 3) && bb != 2) {
			bb = 4;
			while (1) {
				map[map_][ghost_y][ghost_x] = 0;
				ghost_y++;
				map[map_][ghost_y][ghost_x] = 3;

				if (decoder < 4) Sleep(250);
				else if (decoder >= 4) Sleep(200);
				if (job == -2) {
					Sleep(5000);
					job = 2;
				}

				if ((map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x] != 2 && map[map_][ghost_y + 1][ghost_x] != 3) || map[map_][ghost_y][ghost_x - 1] == 0 || map[map_][ghost_y][ghost_x + 1] == 0) {
					if ((map[map_][ghost_y][ghost_x - 1] != 0 && map[map_][ghost_y][ghost_x - 1] != 3) && (map[map_][ghost_y][ghost_x + 1] != 0 && map[map_][ghost_y][ghost_x + 1] != 3) && (map[map_][ghost_y + 1][ghost_x] != 0 && map[map_][ghost_y + 1][ghost_x - 1] != 3)) bb = 0;
					break;
				}
				if (((ghost_x == x && ghost_y + 1 == y) || (map[map_][ghost_y][ghost_x] != 3 && map[map_][ghost_y][ghost_x] != 0)) && job != -1) {
					while (1) {
						dieprint(10, 6);

						if (_kbhit()) {
							moving = getch();

							if (moving == 13) {
								gotoxy(0, 15);
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}

void _stdcall cooltime(void* arg) {
	while (1) {
		while (1) {
			if (job == 1 && item == 0) {
				Sleep(15000);
				break;
			}
			else if (job == 2 && item == 0) {
				Sleep(20000);
				break;
			}
			else if (job == 3 && ((decoder < 4 && item < 3) || (decoder >= 4 && item < 5))) {
				Sleep(17500);
				break;
			}
			else if (job == 4 && item < 3) {
				Sleep(17500);
				break;
			}
		}
		item++;
	}
}
void job_(int x, int y) {
	char key;
	int check = 1;

	system("cls");
	gotoxy(x, y - 5); printf("직 업    선 택		 맵    선 택");
	gotoxy(x, y - 1); printf("┌──────────┐");
	gotoxy(x, y + 1); printf("└──────────┘");

	gotoxy(x + 1, y); printf("   샤 먼			    맵 1");
	gotoxy(x + 1, y + 2); printf("   리 퍼			    맵 2");
	gotoxy(x + 1, y + 4); printf("  건 축 가		    구글");
	gotoxy(x + 1, y + 6); printf("   탐 정");
	gotoxy(x + 1, y + 8); printf("  행 운 아");

	while (1) {
		key = _getch();

		if (key == 13) {
			job = check;
			check = 1;

			x += 25;
			y = 9;
			gotoxy(x, y - 1); printf("┌──────────┐");
			gotoxy(x, y + 1); printf("└──────────┘");

			while (1) {
				key = _getch();

				if (key == 13) {
					map_ = check - 1;
					return 0;
				}
				else if (key == 80 && check < 2) {
					check++;
					y += 2;

					gotoxy(x, y - 3); printf("            ");
					gotoxy(x, y - 1); printf("┌──────────┐");
					gotoxy(x, y + 1); printf("└──────────┘");
				}
				else if (key == 72 && check > 1) {
					check--;
					y -= 2;

					gotoxy(x, y + 3); printf("            ");
					gotoxy(x, y - 1); printf("┌──────────┐");
					gotoxy(x, y + 1); printf("└──────────┘");
				}
			}
		}
		else if (key == 80 && check < 5) {
			check++;
			y += 2;

			gotoxy(x, y - 3); printf("            ");
			gotoxy(x, y - 1); printf("┌──────────┐");
			gotoxy(x, y + 1); printf("└──────────┘");
		}
		else if (key == 72 && check > 1) {
			check--;
			y -= 2;

			gotoxy(x, y + 3); printf("            ");
			gotoxy(x, y - 1); printf("┌──────────┐");
			gotoxy(x, y + 1); printf("└──────────┘");
		}
	}
}
void printmap(int dec_on) {
	gotoxy(0, 0);
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 28; j++) {
			if (map[map_][i][j] == 0) printf("  ");
			else if (map[map_][i][j] == 1) {
				setcolor(BLUE);
				if (map_ == 0 && (j < 5 || j > 21) && ((i >= 10 && i < 13) || (i > 15 && i < 19)) /*|| 1 == 1*/) printf("  ");
				else printf("□");
			}
			else if (map[map_][i][j] == 2) {
				setcolor(YELLOW);
				printf("●");
			}
			else if (map[map_][i][j] == 3) {
				setcolor(DARK_GRAY);
				printf("○");
			}
			else if (map[map_][i][j] == 4) {
				setcolor(YELLOW);
				printf("□");
			}
			else if (map[map_][i][j] == 5) {
				if (dec_on != 1) setcolor(DARK_GRAY);
				else if (dec_on == 1) setcolor(YELLOW);
				printf("☎");
			}
			else if (map[map_][i][j] == 6) {
				if (dec_on != 2)setcolor(DARK_GRAY);
				else if (dec_on == 2) setcolor(YELLOW);
				printf("☎");
			}
			else if (map[map_][i][j] == 7) {
				if (dec_on != 3)setcolor(DARK_GRAY);
				else if (dec_on == 3) setcolor(YELLOW);
				printf("☎");
			}
			else if (map[map_][i][j] == 8) {
				if (dec_on != 4) setcolor(DARK_GRAY);
				else if (dec_on == 4) setcolor(YELLOW);
				printf("☎");
			}
			else if (map[map_][i][j] == 9) {
				if (dec_on != 5)setcolor(DARK_GRAY);
				else if (dec_on == 5) setcolor(YELLOW);
				printf("☎");
			}
			else if (map[map_][i][j] == 10) {
				if (decoder < 4)setcolor(BLUE);
				else if (decoder >= 4) setcolor(DARK_BLUE);
				printf("□");
			}
			else printf("  ");
			setcolor(WHITE);
		}
		printf("\n");
	}
}

void winprint(int x, int y) {
	system("cls");

	int originY = y;
	setcolor(DARK_SKYBLUE);
	gotoxy(x, y++);
	printf("□      □");
	gotoxy(x, y++);
	printf("□  □  □");
	gotoxy(x, y++);
	printf("□  □  □");
	gotoxy(x, y++);
	printf("□  □  □");
	gotoxy(x, y++);
	printf("□□□□□");
	gotoxy(x, y++);
	printf("  □  □  ");

	y = originY;

	x += 13;
	setcolor(DARK_GREEN);
	gotoxy(x, y++);
	printf("□□□");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("  □");
	gotoxy(x, y++);
	printf("□□□");


	y = originY;

	x += 10;
	setcolor(DARK_VOILET);
	gotoxy(x, y++);
	printf("□      □");
	gotoxy(x, y++);
	printf("□□    □");
	gotoxy(x, y++);
	printf("□□□  □");
	gotoxy(x, y++);
	printf("□  □□□");
	gotoxy(x, y++);
	printf("□    □□");
	gotoxy(x, y++);
	printf("□      □");
	setcolor(WHITE);

	y = originY;
	x += 15;
	setcolor(YELLOW);
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, ++y);
	printf("□");

	y = originY;
	x += 5;
	setcolor(YELLOW);
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, y++);
	printf("□");
	gotoxy(x, ++y);
	printf("□");
	setcolor(WHITE);
}
void run() {
	char moving;
	int dec_on = 0, decipher[6] = { 0,0,0,0,0,0 };

	job_(6, 9);
	if (map_ == 1) y += 1;

	_beginthreadex(NULL, 0, cooltime, 0, 0, NULL);
	_beginthreadex(NULL, 0, ghost1, 0, 0, NULL);
	_beginthreadex(NULL, 0, ghost2, 0, 0, NULL);
	_beginthreadex(NULL, 0, ghost3, 0, 0, NULL);
	_beginthreadex(NULL, 0, ghost4, 0, 0, NULL);

	system("cls");
	while (1) {
		printmap(dec_on);
		/* printinfo */ {
			for (int i = 0; i < 5; i++) {
				gotoxy(60, i + 1);

				if (decipher[i] >= 0) printf("Decoder %d decoder Rate : %d %%", i + 1, decipher[i]);
				else printf("Decoder %d decoder Rate : END ", i + 1);
			}
			gotoxy(60, 6);
			if (decipher[5] >= 0) printf("Password Input Rate : %d %%", decipher[5]);
			else printf("Password Input Rate : OPEN");


			gotoxy(60, 9);
			printf("Number of Decoders Completed : %d/4", decoder);

			gotoxy(60, 10);
			if (job == 1 || job == 2 || job == 6) {
				if (item == 0) printf("Item Available : OFF");
				else printf("Item Available : ON ");
			}
			else if (job == 3 || job == 4) printf("Number of Items available : %d", item);
			else if (job == 5) printf("Item Available : Just Lucky");


			if (decoder < 4) {
				gotoxy(60, 13);
				printf("→ Decrypt all the decoders and get out of here.");
			}
		}

		if (_kbhit()) {
			moving = getch();

			if (moving == 75 && (map[map_][y][x - 1] == 0 || map[map_][y][x - 1] == 3 || map[map_][y][x - 1] == 4)) {
				if (job == -1) job = 2;
				while (1) {
					if (job == 0) {
						map[map_][y][x] = 4;
						job = 3;
					}
					else map[map_][y][x] = 0;
					x--;
					map[map_][y][x] = 2;

					printmap(dec_on);
					Sleep(150);

					if (x == 0 && y == 14) {
						map[map_][y][x] = 0;
						x = 26;
						map[map_][y][x] = 2;
					}

					if (_kbhit() || (map[map_][y][x - 1] != 0 && map[map_][y][x - 1] != 3 && map[map_][y][x - 1] != 4)) break;
					if (map[map_][y][x] != 2 && map[map_][y][x] != 0 && map[map_][y][x] != 4 && job != -1) {
						while (1) {
							dieprint(10, 6);

							if (_kbhit()) {
								moving = getch();

								if (moving == 13) {
									gotoxy(0, 15);
									exit(0);
								}
							}
						}
					}
				}
			}
			else if (moving == 9 && item > 0) {
				if (((x != 5 && y != 3) || (x != 21 && y != 3) || (x != 13 && y != 17) || (x != 3 && y != 24) || (x != 23 && y != 24)) && job < 4) dec_on = 0;

				if (job == 1) {
					item--;
					if (decoder < 4 || (x == 12 && y == 1) || (x == 14 && y == 1)) {
						static int _x, _y;
						_x = x;
						_y = y;

						map[map_][y][x] = 0;
						while (1) {
							srand(clock());
							x = rand() % 27;
							y = rand() % 30;

							if (map[map_][y][x] == 0 && abs(_x - x) > 0 && abs(_x - x) <= 5 && abs(_y - y) > 0 && abs(_y - y) <= 5) {
								map[map_][y][x] = 2;
								break;
							}
							x = _x;
							y = _y;
						}
					}
					else if (decoder >= 4) {
						if (x < 14) {
							map[map_][y][x] = 0;
							x = 12;
							y = 1;
							map[map_][y][x] = 2;
						}
						else {
							map[map_][y][x] = 0;
							x = 14;
							y = 1;
							map[map_][y][x] = 2;
						}
					}
				}
				else if (job == 2) {
					item--;
					if (decoder < 4) {
						map[map_][y][x] = 0;
						job = -1;
					}
					else if (decoder >= 4) job = -2;
				}
				else if (job == 3) {
					item--;
					map[map_][y][x] = 4;
					job = 0;
				}
				else if (job == 4) {
					for (int i = 0; i < 5; i++)
						if (dec_on == i + 1) {
							item--;
							decipher[i] += 50;
						}
				}
			}
			else if (moving == 32 && map[map_][y][x] == 2) {
				if ((map_ == 0 && x == 5 && y == 3) || (map_ == 1 && x == 5 && y == 6)) dec_on = 1;
				else if ((x == 21 && y == 3) || (map_ == 1 && x == 21 && y == 6)) dec_on = 2;
				else if (x == 13 && y == 17) dec_on = 3;
				else if (x == 3 && y == 24) dec_on = 4;
				else if (x == 23 && y == 24) dec_on = 5;
				else if ((x == 12 && y == 1) || (x == 14 && y == 1)) dec_on = 6;
			}
			else if (moving == 113) {
				gotoxy(0, 30);
				exit(0);
			}
			else if (moving == 72 && (map[map_][y - 1][x] == 0 || map[map_][y - 1][x] == 3 || map[map_][y - 1][x] == 4)) {
				if (job == -1) job = 2;
				while (1) {
					if (job == 0) {
						map[map_][y][x] = 4;
						job = 3;
					}
					else map[map_][y][x] = 0;
					y--;
					map[map_][y][x] = 2;

					printmap(dec_on);
					Sleep(150);

					if (_kbhit() || (map[map_][y - 1][x] != 0 && map[map_][y - 1][x] != 3 && map[map_][y - 1][x] != 4)) break;
					if (map[map_][y][x] != 2 && map[map_][y][x] != 0 && map[map_][y][x] != 4 && job != -1) {
						while (1) {
							dieprint(10, 6);

							if (_kbhit()) {
								moving = getch();

								if (moving == 13) {
									gotoxy(0, 15);
									exit(0);
								}
							}
						}
					}
				}
			}
			else if (moving == 77 && (map[map_][y][x + 1] == 0 || map[map_][y][x + 1] == 3 || map[map_][y][x + 1] == 4)) {
				if (job == -1) job = 2;
				while (1) {
					if (job == 0) {
						map[map_][y][x] = 4;
						job = 3;
					}
					else map[map_][y][x] = 0;
					x++;
					map[map_][y][x] = 2;

					printmap(dec_on);
					Sleep(150);

					if (x == 26 && y == 14) {
						map[map_][y][x] = 0;
						x = 0;
						map[map_][y][x] = 2;
					}

					if (_kbhit() || (map[map_][y][x + 1] != 0 && map[map_][y][x + 1] != 3 && map[map_][y][x + 1] != 4)) break;
					if (map[map_][y][x] != 2 && map[map_][y][x] != 0 && map[map_][y][x] != 4 && job != -1) {
						while (1) {
							dieprint(10, 6);

							if (_kbhit()) {
								moving = getch();

								if (moving == 13) {
									gotoxy(0, 15);
									exit(0);
								}
							}
						}
					}
				}
			}
			else if (moving == 80 && (map[map_][y + 1][x] == 0 || map[map_][y + 1][x] == 3 || map[map_][y + 1][x] == 4)) {
				if (job == -1) job = 2;
				while (1) {
					if (job == 0) {
						map[map_][y][x] = 4;
						job = 3;
					}
					else map[map_][y][x] = 0;
					y++;
					map[map_][y][x] = 2;

					printmap(dec_on);
					Sleep(150);

					if (_kbhit() || (map[map_][y + 1][x] != 0 && map[map_][y + 1][x] != 3 && map[map_][y + 1][x] != 4)) break;
					if (map[map_][y][x] != 2 && map[map_][y][x] != 0 && map[map_][y][x] != 4 && job != -1) {
						while (1) {
							dieprint(10, 6);

							if (_kbhit()) {
								moving = getch();

								if (moving == 13) {
									gotoxy(0, 15);
									exit(0);
								}
							}
						}
					}
				}
			}
			else dec_on = 0;
		}
		for (int i = 0; i < 5; i++)
			if (dec_on == i + 1 && decipher[i] < COMPLETE && decipher[i] >= 0) {
				if (job == 4) decipher[i] += 2;
				else decipher[i]++;
			}
		if (dec_on == 6 && decipher[5] < COMPLETE && decipher[5] >= 0 && decoder >= 4) decipher[5] += 2;
		/* block */ {
			if (decipher[0] >= COMPLETE) {
				if (map_ == 0) map[map_][3][4] = 1;
				else map[map_][6][4] = 1;

				map[map_][y][x] = 1;
				x++;
				map[map_][y][x] = 2;

				decipher[0] = -1;
				decoder++;
			}
			else if (decipher[1] >= COMPLETE) {
				if (map_ == 0)map[map_][3][22] = 1;
				else map[map_][6][22] = 1;

				map[map_][y][x] = 1;
				x--;
				map[map_][y][x] = 2;

				decipher[1] = -1;
				decoder++;
			}
			else if (decipher[2] >= COMPLETE) {
				map[map_][18][13] = 1;

				decipher[2] = -1;
				decoder++;
			}
			else if (decipher[3] >= COMPLETE) {
				map[map_][24][4] = 1;

				decipher[3] = -1;
				decoder++;
			}
			else if (decipher[4] >= COMPLETE) {
				map[map_][24][22] = 1;

				decipher[4] = -1;
				decoder++;
			}
			else if (decipher[5] >= COMPLETE) {
				map[map_][1][13] = 0;
				map[map_][0][13] = 0;

				decipher[5] = -1;
			}
		}

		if (decoder >= 4) {
			gotoxy(60, 13);
			printf("→ You got the password.                       ");
			gotoxy(60, 14);
			printf("   Use your password to open the door.");
		}
		/* Result */ {
			if (map[map_][y][x] != 2 && map[map_][y][x] != 0 && map[map_][y][x] != 4 && job != -1) {
				while (1) {
					dieprint(10, 6);

					if (_kbhit()) {
						moving = getch();

						if (moving == 13) {
							gotoxy(0, 15);
							exit(0);
						}
					}
				}
			}
			if (x == 13 && y == 0) {
				winprint(10, 6);
				Sleep(1500);

				gotoxy(0, 18);
				exit(0);
			}
		}
	}
}