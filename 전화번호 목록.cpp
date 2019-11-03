#include <iostream>
#include <map>
#include <string>
using namespace std;

int checkNum(int number) {
	int cnt = 0;
	while (number) {
		number /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map <int,int> s;
		int phone;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			cin >> phone;
			cnt = checkNum(phone);
			cout << cnt << endl;
			int temp = 1;
			for (int i = 0; i < 10 - cnt; i++) temp = temp * 10;
			phone *= temp;
			cout << phone << "\n";
			s.insert({ phone,cnt });
		}
		int br = 0;
		for (map <int, int>::iterator iter = s.begin(); iter != s.end(); iter++) {
			cout << (*iter).first << "\n";
		}
		//for (map <int,int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		//	for (map <int, int>::iterator iter2 = s.begin(); iter2 != s.end(); iter2++) {
		//		if ((*iter).first != (*iter2).first) {
		//			if (checkNum((*iter2).first - (*iter).first) == (*iter2).second - (*iter2).second) {
		//				br = 1;
		//				cout << "NO" << "\n";
		//				break;
		//			}
		//			else break;
		//		}
		//	}
		//	if (br) break;
		//}
		//if (br == 0) cout << "YES" << "\n";
	}
	system("pause");
}