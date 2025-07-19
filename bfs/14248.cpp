#include <bits/stdc++.h>
using namespace std;

int n;
int sl[100005];
int s;

bool vis[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> sl[i];

	cin >> s;

	queue<int> q;
	q.push(s);
	vis[s] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nx = 0;

			if (i == 0) nx = cur - sl[cur];
			else        nx = cur + sl[cur];

			if (nx <= 0 || nx > n) continue;
			if (vis[nx]) continue;

			q.push(nx);
			vis[nx] = true;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) cnt++;
	}

	cout << cnt << '\n';
}
