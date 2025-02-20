#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[10005];
bool vis[10005];
int cnt;

void clear() {
	cnt = 0;
	for (int i = 0; i < 10005; i++) vis[i] = 0;
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cnt++;
		for (auto nxt : vec[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
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
		cin >> e >> s;
		vec[s].push_back(e);
	}

	vector<pair<int, int>> ret;
	for (int i = 1; i <= n; i++) {
		clear();
		bfs(i);
		ret.push_back({cnt, i});
	}

	sort(ret.begin(), ret.end());

	int max_v = ret[n-1].first;
	for (int i = 0; i < n; i++) {
		if (max_v > ret[i].first) continue;
		cout << ret[i].second << ' ';
	}
	cout << '\n';
}
