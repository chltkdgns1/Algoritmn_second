#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Data {
public:
	string arr[3];
};
 Data split(string s) {
	int cnt = 0;
	Data e;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') cnt++;
		else {
			if (!cnt) e.arr[0] += s[i];
			else if (cnt == 1) e.arr[1] += s[i];
			else e.arr[2] += s[i];
		}
	}
	return e;
}

 map <string, string> m;
 vector <Data> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s; getline(cin, s);
		Data d = split(s);
		v.push_back(d);
		if (d.arr[0] == "Enter" || d.arr[0] == "Change") {
			m[d.arr[1]] = d.arr[2];
		}
	}
	for (auto a : v) {
		if (a.arr[0] == "Enter") {
			cout << m[a.arr[1]] << "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù." << "\n";
		}
		else if (a.arr[0] == "Leave") {
			cout << m[a.arr[1]] << "´ÔÀÌ ³ª°¬½À´Ï´Ù." << "\n";
		}
	}
}