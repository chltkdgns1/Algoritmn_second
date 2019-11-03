#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "play.h"
#include "map.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(NULL));
	Map map;
	map.printMap();
	Player p; p.x = 15, p.y = 2;
	int a = rand() % 4, b = 0; // 맨 처음에는 임의로 시작함 그냥 귀찮음
	p.PrintBlock(a, b,map);
	while (1) {
		if (_kbhit()) {
			char ch = _getch();
			p.MoveXY(ch,a,b,map);
		}
	}
	system("pause");
}