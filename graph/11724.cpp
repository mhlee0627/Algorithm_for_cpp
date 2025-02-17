#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gr[1005];
bool vis[1005];
int cnt;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : gr[cur]) {
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
	int a = 0;
	int b = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			bfs(i);
		}
	}

	cout << cnt << '\n';
}
