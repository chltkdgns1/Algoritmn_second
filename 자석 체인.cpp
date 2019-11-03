/*#include <iostream>
using namespace std;

int main()
{
	int arr[100];
	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 2 * n; i++)
	{
		if (arr[i] == arr[i + 1])
			count++;
	}

	if (count == 0)
		cout << "Yes" << endl;
	if (count != 0)
		cout << "No" << endl;
	system("pause");
	return 0;
}*/

#include <iostream>
#include <string>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b,c; cin >> a >> b;
	int x = 0, y = 0;
	for (int i = 0; i < 2*a.length(); i++) {
		if (i % 2 == 0) c += a[x],x++;
		else c += b[y],y++;
	}
	while (c.length() != 2) {
		string t;
		for (int i = 0; i < c.length() - 1; i++) {
			t += (c[i] - 48 + c[i + 1] - 48) % 10 + 48;
		}
		c = t;
	}
	cout << c << "\n";
	system("pause");
}
/*
74759336
36195974
*/
/*
#include <iostream>
using namespace std;

int main()
{
	int T;
	int n;
	int real[100] = { 0 };
	int j = 0;
	int a;
	int sum = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (a = 1; a <= n; a++) 
		{
			if (a % 3 == 0 || a % 7 == 0)
			{
				//cout << a << ' ';
				//cout << j << ' ';
				real[j] = a;
				//cout << real[j] << endl;
				j++;
			}
		}
		j = 0;
		sum = 0;
		for (int i = 0; i < 99; i++)
			sum += real[i];
		cout << sum << endl;
	}

	system("pause");
	return 0;
}*/