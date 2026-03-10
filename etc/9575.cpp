#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> vec[3];

bool check(int sum) {
	string str = to_string(sum);

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '5' && str[i] != '8') {
			return false;
		}
	}

	return true;
}

int func() {
	set<int> s;

	for (int i = 0; i < vec[0].size(); i++) {
		for (int j = 0; j < vec[1].size(); j++) {
			for (int k = 0; k < vec[2].size(); k++) {
				int sum = vec[0][i] + vec[1][j] + vec[2][k];
				if (check(sum)) {
					s.insert(sum);
				}
			}
		}
	}

	return s.size();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			int n;
			cin >> n;
			for (int j = 0; j < n; j++) {
				int v;
				cin >> v;
				vec[i].push_back(v);
			}
		}
		
		cout << func() << '\n';

		vec[0].clear();
		vec[1].clear();
		vec[2].clear();
	}
}
