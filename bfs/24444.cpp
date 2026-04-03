#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<int> adj[100005];
bool vis[100005];
int order[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int t = 1;
	queue<int> q;
	q.push(r);
	vis[r] = true;	

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		order[cur] = t++;

		sort(adj[cur].begin(), adj[cur].end());
		for (auto nxt : adj[cur]) {
			if (vis[nxt] == true) continue;

			q.push(nxt);
			vis[nxt] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << order[i] << '\n';
	}
}	
