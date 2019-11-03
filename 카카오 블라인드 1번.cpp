#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string t;

bool solve(int a, int b) {
	int c = 0, d = 0;
	for (int i = a; i <= b; i++) {
		if (t[i] == '(') c++;
		if (t[i] == ')') d++;
	}
	if (c != d) return false;
	for (int i = a + 1; i < b; i += 2) {
		solve(a, i) , solve(i + 1, b);
	}
}
string solution(string p) {
	if (p.empty()) return p;
	t = p;
	string answer = "";
	

	return answer;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	cout << solution(s) << "\n";
	system("pause");
}