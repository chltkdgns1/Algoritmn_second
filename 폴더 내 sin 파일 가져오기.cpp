#include <iostream>
#include <string>
#include <conio.h>
#include <io.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	_finddata_t fd;
	long hand;
	int res = 1;
	hand = _findfirst(".\\*.*", &fd);

	if (hand == -1) {
		cout << "there is no file" << "\n";
		return 0;
	}

	while (res != -1) {
		cout << "file name : " << fd.name << "\n";
		res = _findnext(hand, &fd);
	}

	_findclose(hand);
	system("pause");
}