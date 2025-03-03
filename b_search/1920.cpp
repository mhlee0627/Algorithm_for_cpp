#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int tmp = 0;
	while (n--) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());

	cin >> m;
	while (m--) {
		cin >> tmp;
		cout << binary_search(vec.begin(), vec.end(), tmp) << '\n';
	}
}
