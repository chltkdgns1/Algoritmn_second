#include <iostream>
#include <vector>
using namespace std;


vector <int> nodeList[100001];
bool visitList[100001];
int temp;

bool Isposible(int N)
{
	if (N == 1)
		return true;

	for (int i = 0; i < nodeList[N].size(); i++)
	{
		if (visitList[nodeList[N][i]])
		{
			if (temp == -1)
				return true;

			if (nodeList[N][i] == temp)
				return true;
		}
	}

	return false;
}

int Settemp(int N)
{
	int count = 0;

	if (N == 1)
	{
		temp = N;
		return 1;
	}

	for (int i = 0; i < nodeList[N].size(); i++)
	{
		int ttemp = nodeList[N][i];
		if (!visitList[nodeList[N][i]])
		{
			temp = N;
			return 1;
		}
	}

	temp = -1;
	return 1;
}

int main()
{
	int N;

	cin >> N;
	temp = -1;

	for (int i = 1; i < N; i++)
	{
		int parent, child;
		cin >> parent >> child;

		nodeList[parent].push_back(child);
		nodeList[child].push_back(parent);
	}

	for (int i = 0; i < N; i++)
	{
		int Input;
		cin >> Input;

		if (Isposible(Input))
		{
			visitList[Input] = true;
			Settemp(Input);
		}
		else
		{
			cout << 0;
			return 0;
		}

	}

	cout << 1;
	return 0;
}