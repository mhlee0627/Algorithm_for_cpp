#include <bits/stdc++.h>
using namespace std;

int a, k;
int dist[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> k;

	queue<int> q;
	q.push(a);
	dist[a] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur == k) {
			cout << dist[cur] << '\n';
			return 0;
		}

		int n = 2 * cur;
		if (n <= k && dist[n] == 0) {
			q.push(n);
			dist[n] = dist[cur] + 1;
		}

		int m = cur + 1;
		if (m <= k && dist[m] == 0) {
			q.push(m);
			dist[m] = dist[cur] + 1;
		}
	}
}

