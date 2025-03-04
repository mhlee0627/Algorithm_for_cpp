#include <bits/stdc++.h>
using namespace std;

int a, b;
int al[500005];
int bl[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> al[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> bl[i];
	}

	sort(bl, bl+b);
	
	vector<int> vec;
	for (int i = 0; i < a; i++) {
		if (!binary_search(bl, bl+b, al[i])) {
			vec.push_back(al[i]);
		}
	}
	
	int len = vec.size();
	cout << len << '\n';
	
	if (len != 0) {
		sort(vec.begin(), vec.end());

		for (auto elem : vec) {
			cout << elem << ' ';
		}
		cout << '\n';
	}
}
