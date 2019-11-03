#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
long long cnt;
vector<pair<int, int>> v;
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
string subtractOne(string num)
{
	vector<int> v;
	int back = num.back() - '0';
	num.pop_back();
	back -= 1;
	num.push_back(back + '0');
	return num;
}
void Hanoi(int num, int from, int by, int to)
{
	if (num == 1)
		v.push_back({ from, to });
	else
	{
		Hanoi(num - 1, from, to, by);
		v.push_back({ from, to });
		Hanoi(num - 1, by, from, to);
	}
}
int main(void) {
	cin >> N;
	if (N <= 20)
	{
		Hanoi(N, 1, 2, 3);
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++)
			cout << v[i].first << " " << v[i].second << "\n";
	}
	else
	{
		string num = "2";
		for (int i = 0; i < N - 1; i++)
		{
			string temp = bigNumAdd(num, num);
			num = temp;
		}
		cout << subtractOne(num) << "\n";
	}
	return 0;
}