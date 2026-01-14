#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<double> vec;
stack<double> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);

	cin >> n >> str;

	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		vec.push_back(num);
	}

	for (auto elem : str) {
		if (elem >= 'A' && elem <= 'Z') {
			s.push(vec[elem - 'A']);
		}
		else {
			double a = s.top(); s.pop();
			double b = s.top(); s.pop();

			if (elem == '+') {
				s.push(a+b);
			}
			else if (elem == '-') {
				s.push(b-a);
			}
			else if (elem == '*') {
				s.push(a*b);
			}
			else {
				s.push(b/a);
			}
		}
	}

	cout << s.top() << '\n';
}
