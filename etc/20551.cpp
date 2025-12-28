#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;

		vec.push_back(in);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < m; i++) {
		int in;
		cin >> in;

		if (!binary_search(vec.begin(), vec.end(), in)) {
			cout << -1 << '\n';
		}
		else {
			cout << lower_bound(vec.begin(), vec.end(), in) - vec.begin() << '\n';
		}
	}
}
