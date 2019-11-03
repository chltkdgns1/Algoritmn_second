#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include "player.h"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map *ma = new map();
	ma->readMapList("map/maplist.txt");
	ma->PrintMap(0);

	//ma->mapIndexCheck(0);  ÀÎµ¦½º Ã¼Å©

	system("pause");
	Shoot *s = new Shoot();

	print *p = new print();

	player *a = new player();

	monster *m = new monster();

	item *t = new item();

	p->gotoxy(0, 0);
	p->printMap();
	p->printScore();

	a->printAirplane();

	char rember = 'r';
	char c = 0;

	int t_get_time;
	int c_get_time;

	int get_time = c_get_time = t_get_time = GetTickCount();
	int b_time, c_time, t_time;

	while (1) {
		b_time = c_time = t_time = GetTickCount();
		if (_kbhit() == 1) {
			c = _getch();
			if (c == 'w' || c == 'a' || c == 's' || c == 'd')
				rember = c;
			a->action(c, rember, m, p, t);
		}
		a->Die(m);
		if (c_time - c_get_time > 50) {
			a->Shooting(c, rember, m, p, s);
			c_get_time = c_time;
			c = 0;
		}
		if (t_time - t_get_time > 2000) {
			t->makeItem(a->getXpos(), a->getYpos());
			t->printItem();
			t_get_time = t_time;
		}
		if (b_time - get_time > 1000) {
			m->createMonster(a->getXpos(), a->getYpos());
			m->move();
			get_time = b_time;
		}
	}
	system("pause");
}