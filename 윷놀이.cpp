#include <iostream>
using namespace std;
int main() {
	int n;
	for (int i = 0; i < 3; i++) {
		int be = 0;
		int dng = 0;
		for (int j = 0; j < 4; j++) {
			cin >> n;
			if (n == 0) be++;
			else dng++;
		}
		if (be == 1) cout << "A" << endl;
		else if(be == 2) cout << "B" << endl;
		else if (be == 3) cout << "C" << endl;
		else if (be == 4) cout << "D" << endl;
		else if (be == 0) cout << "E" << endl;
	}
}