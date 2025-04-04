#include <bits/stdc++.h>
using namespace std;

int a, b;
queue<pair<long long, int>> q;
bool findout;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	
	q.push({a, 0});

	while (!q.empty()) {
		pair<long long, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			pair<long long, int> nxt = {0, 0};
			if (i == 0) {
				nxt.first = cur.first * 2;
				nxt.second = cur.second + 1;
			}
			else {
				nxt.first = cur.first * 10 + 1;
				nxt.second = cur.second + 1;
			}

			if (nxt.first > 1000000000) continue;
			
			if (nxt.first == b) {
				findout = 1;
				cout << nxt.second + 1 << '\n';
				return 0;
			}

			q.push({nxt.first, nxt.second});
		}
	}

	if (!findout) cout << -1 << '\n';

}
