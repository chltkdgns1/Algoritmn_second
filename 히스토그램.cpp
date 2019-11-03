#include <iostream>
#include <stack>
int h[100000];
int main(void)
{
	int n; std::cin >> n;
		std::stack<int> s;
		for (int i = 0; i < n; i++) std::cin >> h[i];
		long long area = 0;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && h[s.top()] > h[i]) {
				long long height = h[s.top()];
				s.pop();	
				long long width = i;
				if (!s.empty()) width = i - s.top() - 1;
				if (width*height > area) area = width * height;
			}
			s.push(i);
		}
		while (!s.empty()) {
			long long height = h[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) width = n - s.top() - 1;
			if (width*height > area) area = width * height;
		}
		std::cout << area << '\n';
		std::cin >> n;
	return 0;
}
