#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> big[100];
vector<int> small[100];
bool vis[100];

void clear_vis() {
	for (int i = 0; i < 100; i++) vis[i] = 0;
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : big[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}

void bfs2(int x) {
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : small[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}


int cnt_vis() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) cnt++;
	}

	return cnt-1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int st, en;
	for (int i = 0; i < m; i++) {
		cin >> st >> en;
		big[st].push_back(en);
		small[en].push_back(st);
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		clear_vis();
		bfs(i);
		if (cnt_vis() >= (n/2+1)) {
			ret++;
			continue;
		}

		clear_vis();
		bfs2(i);
		if (cnt_vis() >= (n/2+1)) {
			ret++;
		}
	}

	cout << ret << '\n';
}
