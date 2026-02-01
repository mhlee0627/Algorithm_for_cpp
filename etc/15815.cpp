#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	stack<int> s;
	for (auto ch : str) {
		if (ch >= '0' && ch <= '9') {
			s.push(ch - '0');
		}
		else {
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();

			int ret = 0;

			switch(ch) {
				case '*':
					ret = a * b;
					break;
				case '/':
					ret = a / b;
					break;
				case '+':
					ret = a + b;
					break;
				case '-':
					ret = a - b;
					break;
			}

			s.push(ret);
		}
	}

	cout << s.top() << '\n';
}
