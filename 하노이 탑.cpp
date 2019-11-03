#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string bigNumAdd(string num1, string num2)
{
	long long sum = 0;
	string result;
	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}
string minusOne(string num) {
	int t = num.back() - '0';
	num.pop_back();
	t -= 1;
	num.push_back(t + '0');
	return num;
}
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		cout << "1 3\n";
		return 0;
	}
	long long cnt = 0;
	if (n > 20) {
		string t = "2";
		for (int i = 0; i < n - 1; i++) {
			string s = bigNumAdd(t, t);
			t = s;
		}
		cout << minusOne(t) << "\n";
		return 0;
	}
	int cur = 0;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	stack <pair<int,int>> s[4];
	vector<pair<int, int>> v; // from -> to 
	bool b = false;
	for (int i = n; i >= 1; i--) s[1].push({0,i }); 
	while (1) {
		for (int i = 1; i <= 3; i++) {
			if (cur != i && !s[i].empty()) {
				for (int k = 1; k <= 3; k++) {
					if (i != k && s[i].top().first != k) { 
						if (!s[k].empty()) {
							if (s[i].top().second < s[k].top().second) { 
								if(n <= 20) v.push_back({ i,k });
								cnt++;
								s[k].push(s[i].top());
								s[k].top().first = i; 
								s[i].pop(); 
								cur = k; 
							}
						}
						else {
							if (n <= 20) v.push_back({ i,k });
							cnt++;
							s[k].push(s[i].top());
							s[k].top().first = i;
							s[i].pop(); 
							cur = k; 
						}
						if (s[i].empty()) break;
					}
				}
			}
		}
		if (s[3].size() == n || s[2].size() == n) {
			break;
		}
	}
	cout << cnt << "\n";
	if (n <= 20) for (int i = 0; i < v.size(); i++)
		printf("%d %d\n", v[i].first, v[i].second);
}