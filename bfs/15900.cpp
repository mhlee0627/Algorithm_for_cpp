#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[500005];
int dist[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> leafs;

	queue<int> q;
	q.push(1);
	dist[1] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		bool leaf = true;
		for (auto nxt : adj[cur]) {
			if (dist[nxt] > 0) continue;

			leaf = false;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}

		if (leaf) {
			leafs.push_back(dist[cur]);
		}
	}

	int ret = 0;
	for (auto elem : leafs) {
		ret += (elem - 1);
	}

	if (ret%2 == 0) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
}
