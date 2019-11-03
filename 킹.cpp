#include <iostream>
#include <string>
using namespace std;
char map[9][9];
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,-1,1,1,1,-1,-1 };
bool checkIndex(int xpos, int ypos) {
	if (xpos >= 1 && ypos >= 1 && xpos <= 8 && ypos <= 8) return true;
	return false;
}
int xpos, ypos, xpos2, ypos2;
void checkGo(int d) {
	int ax, ay, bx, by;
	ax = xpos + dx[d];
	ay = ypos + dy[d];
	bx = xpos2 + dx[d];
	by = ypos2 + dy[d];
	if (checkIndex(ax, ay) == true) {
		if (ax == xpos2 && ay == ypos2) {
			if (checkIndex(bx, by) == true) {
				xpos += dx[d];
				ypos += dy[d];
				xpos2 += dx[d];
				ypos2 += dy[d];
			}
		}
		else {
			xpos += dx[d];
			ypos += dy[d];
		}
	}
}
int main() {
	string a, b;
	int n;
	cin >> a >> b;
	xpos = a[0] - 64, ypos = a[1] - 48;
	xpos2 = b[0] - 64, ypos2 = b[1] - 48;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;
		if (order == "R") checkGo(0);
		if (order == "L") checkGo(1);
		if (order == "B") checkGo(2);
		if (order == "T") checkGo(3);
		if (order == "RT") checkGo(4);
		if (order == "LT") checkGo(5);
		if (order == "RB") checkGo(6);
		if (order == "LB") checkGo(7);
	}
	string c, d;
	c += (xpos + 64);
	c += (ypos + 48);
	d += (xpos2 + 64);
	d += (ypos2 + 48);
	cout << c << endl;
	cout << d << endl;
}