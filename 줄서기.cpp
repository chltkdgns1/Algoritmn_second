#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
vector <pair<char,int>> v,e;
stack <pair<char, int>> s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 5; k++) {
			string s, b; cin >> s;
			char a;
			for (int z = 0; z < s.length(); z++) {
				if (s[z] >= 65 && s[z] <= 90) a = s[z];
				else if (s[z] >= 48 && s[z] <= 57) b += s[z];
			}
			v.push_back({ a, stoi(b) });
		}
	}
	int v_index = 0; // 
	while (v_index != v.size()) {
		if (s.empty()) {
			s.push(v[v_index]);
			v_index++;
		}
		else {
			if (s.top().first < v[v_index].first) e.push_back(s.top()),s.pop();
			else if (s.top().first > v[v_index].first) s.push(v[v_index]), v_index++;
			else if (s.top().first == v[v_index].first && s.top().second < v[v_index].second) e.push_back(s.top()),s.pop();
			else if (s.top().first == v[v_index].first && s.top().second > v[v_index].second) s.push(v[v_index]), v_index++;
		}
	}
	while (!s.empty()) {
		e.push_back(s.top());
		s.pop();
	}
	for (int i = 1; i < e.size(); i++) {
		if (e[i - 1].first > e[i].first || (e[i-1].first == e[i].first && e[i-1].second > e[i].second)) {
			cout << "BAD" << "\n";
			return 0;
		}
	}
	cout << "GOOD" << "\n";
}