#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, b, h, w, p ,total=500001,w_people;
	cin >> n >> b >> h >> w;
	for (int i = 1; i <= h; i++) { 
		cin >> p;
		bool on_off = false;
		for (int i = 1; i <= w; i++) {
			cin >> w_people;
			if (w_people >= n) {
				on_off = true;
 			}
		}
		if (on_off == true) {
			if (b >= p * n) {
				if (total > p * n) total = p * n;
			}
		}
		
	} 
	if (total == 500001) cout << "stay home" << endl;
	else cout << total << endl;
}