#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// time, score
	stack<pair<int, int>> s;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		if (d == 1) {
			int a, t;
			cin >> a >> t;
			
			if (t-1 == 0) {
				ret += a;
			}
			else {
				s.push({t-1, a});
			}
		}
		else {
			if (s.empty()) continue;

			auto cur = s.top();
			s.pop();
			
			if (cur.first-1 == 0) {
				ret += cur.second;
			}
			else {
				s.push({cur.first-1, cur.second});
			}
		}
	}
	
	cout << ret << '\n';
}
