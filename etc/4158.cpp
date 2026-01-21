#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;
		
		unordered_set<int> us;
		int ret = 0;

		for (int i = 0; i < n; i++) {
			int cd;
			cin >> cd;

			us.insert(cd);
		}
	
		for (int i = 0; i < m; i++) {
			int cd;
			cin >> cd;

			if (us.find(cd) != us.end()) {
				ret++;
			}
		}

		cout << ret << '\n';
	}
}
