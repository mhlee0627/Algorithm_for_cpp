#include <bits/stdc++.h>
using namespace std;

int a, b;
multiset<int> as;
multiset<int> bs;
multiset<int> ret;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int elem;
		cin >> elem;
		as.insert(elem);
	}

	for (int i = 0; i < b; i++) {
		int elem;
		cin >> elem;
		bs.insert(elem);
	}

	for (auto elem : as) {
		if (bs.find(elem) == bs.end()) {
			ret.insert(elem);
		}
	}

	for (auto elem : bs) {
		if (as.find(elem) == as.end()) {
			ret.insert(elem);
		}
	}

	cout << ret.size() << '\n';
}
