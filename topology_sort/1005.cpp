#include <bits/stdc++.h>
using namespace std;

int t, n, k, w;
int deg[1005];
int wtime[1005];
int ret[1005];

void clear() {
	for (int i = 0; i < 1005; i++) {
		deg[i] = 0;
		wtime[i] = 0;
		ret[i] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		clear();
		
		cin >> n >> k;
		
		for (int i = 1; i <= n; i++) {
			int in;
			cin >> in;
			wtime[i] = in;
		}

		vector<int> adj[1005];
		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;

			adj[a].push_back(b);
			deg[b]++;
		}

		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) {
				q.push(i);	
				ret[i] = wtime[i];
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : adj[cur]) {
				deg[nxt]--;
				ret[nxt] = max(ret[nxt], ret[cur] + wtime[nxt]);
				if (deg[nxt] == 0) q.push(nxt);
			}
		}

		cout << ret[w] << '\n';
	}
}
