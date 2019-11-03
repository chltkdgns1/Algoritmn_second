#include <iostream>
#include <string>
using namespace std;
int main() {
	string six = "666";
	int n;
	cin >> n;
	if (n - 1 == 0) cout << six << "\n";
	else {
		int cnt = 1;
		int number = 1666;
		while (1) {
			int temp,temp_cnt = 0;
			temp = number;
			while (temp) {
				if (temp % 10 == 6) {
					temp_cnt++;
					if (temp_cnt == 3) { cnt++; break; }
				}
				else temp_cnt = 0;
				temp /= 10;
			}
			if (cnt == n) { cout << number << "\n"; break; }
			number++;
		}
	}
}

/*
666 1666 2666 3666 4666 5666 6660 6661 6662 6663 6664 6665 6666 
6667 6668 6669 7666


*/