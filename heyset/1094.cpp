#include <bits/stdc++.h>
using namespace std;

int x;
vector<int> s;
int cnt;

void func() {
	int sum = 0;
	for (auto& elem : s) {
		sum += elem;
	}

	while (sum > x) {
		int last = s.size();
		int half = s[last-1]/2;

		s.pop_back();
		sum = 0;
		for (auto& elem : s) {
			sum += elem;
		}

		if ((sum + half) >= x) {
			s.push_back(half);
		}
		else {
			s.push_back(half);
			s.push_back(half);
		}

		sum = 0;
		for (auto& elem : s) {
			sum += elem;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x;
	s.push_back(64);

	func();

	cout << s.size() << '\n';
}
