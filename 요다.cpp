#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	
	cin >> t;
	cin.ignore();
	while(t--)
	{
		string s, a, b;
		getline(cin, s);
		int count = 0;
		int store = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
				count++;
			if (count < 2)
			{
				store++;
				a += s[i];
			}
		}
		for (int i = store+1; i < s.length(); i++)
		{
			cout << s[i];
		}
		cout <<' '<< a << '\n';
		
	}
	//system("pause");
}