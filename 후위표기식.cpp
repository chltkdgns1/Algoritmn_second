#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
char sign[3][2] = {
	{'*','/'},
	{'+','-'},
	{'('}
};
int search(char a) {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			if (sign[i][k] == a) {
				return i;
			}
		}
	}
}
int main() {
	string s;
	cin >> s;
	stack <char> st;
	queue <char> q;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) q.push(s[i]);
		else {
			if (st.empty()) st.push(s[i]);
			else if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')') {
				while (st.top() != '(') {
					q.push(st.top());
					st.pop();
				}
				st.pop();
			}
			else {
				if (st.top() == '(') st.push(s[i]);
				else if (search(st.top()) <= search(s[i])) { // 우선순위가 낮은게 들어오면
					while (!st.empty() && search(st.top()) <= search(s[i])) {
						q.push(st.top());
						st.pop();
					}st.push(s[i]);
				}
				else st.push(s[i]);
			}
		}
	}while (!st.empty()) { 
		q.push(st.top());
		st.pop();
	}
	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
	cout << "\n";
}