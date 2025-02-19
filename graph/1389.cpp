#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[105];
int dist[105];

void dist_clear() {
	for (int i = 0; i < 105; i++) dist[i] = -1;
}

int get_dist_sum() {
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += dist[i];
	return sum;
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : vec[cur]) {
			if (dist[nxt] >= 0) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int s = 0;
	int e = 0;
	while (m--) {
		cin >> s >> e;
		vec[s].push_back(e);
		vec[e].push_back(s);
	}

	vector<pair<int, int>> ret;

	for (int i = 1; i <= n; i++) {
		dist_clear();
		bfs(i);
		//cout << get_dist_sum() << '\n';
		ret.push_back({get_dist_sum(), i});
	}

	stable_sort(ret.begin(), ret.end());

	cout << ret[0].second << '\n';
}
