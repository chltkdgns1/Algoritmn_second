#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int arr[27];
int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s;
	queue <string> q;
	stack <double> st;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			q.push(to_string(arr[s[i] - 65]));
		}
		else {
			string e;
			e += s[i];
			q.push(e);
		}
	}

	while (!q.empty()) {
		if (q.front() != "+" && q.front() != "-" && q.front() != "*" && q.front() != "/" ) {
			st.push(stoi(q.front()));
		}
		else {
			string t = q.front();
			if (t == "+") {
				double d = st.top();  st.pop();
				d += st.top(); st.pop(); st.push(d);
			}
			else if (t == "-") {
				double x, y;
				x = st.top(); st.pop();
				y = st.top(); st.pop();
				st.push(y - x);
			}
			else if (t == "*") {
				double d = st.top();  st.pop();
				d *= st.top(); st.pop(); st.push(d);
			}
			else {
				double x, y;
				x = st.top(); st.pop();
				y = st.top(); st.pop();
				st.push(y / x);
			}
		}
		q.pop();
	}
	printf("%.2lf", st.top());
}