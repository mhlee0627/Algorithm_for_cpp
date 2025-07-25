#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;

		s.insert(in);
	}

	for (auto elem : s) cout << elem << ' ';
	cout << '\n';
}
