#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32005];
int deg[32005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	queue<int> q;
	vector<int> ret;

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ret.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (auto elem : ret) {
		cout << elem << ' ';
	}
	cout << '\n';
}
