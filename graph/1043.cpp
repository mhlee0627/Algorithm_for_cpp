#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[105];
bool vis[105];
int t_c, t_n;
vector<int> t_vec;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
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
	cin >> t_c;
	for (int i = 0; i < t_c; i++) {
		cin >> t_n;
		t_vec.push_back(t_n);
	}

	for (int i = 51; i < 51+m; i++) {
		cin >> t_c;
		for (int j = 0; j < t_c; j++) {
			cin >> t_n;
			vec[i].push_back(t_n);
			vec[t_n].push_back(i);
		}
	}

	for (auto elem : t_vec) {
		bfs(elem);
	}

	int cnt = 0;
	for (int i = 51; i < 51+m; i++) {
		if (!vis[i]) cnt++;
	}

	cout << cnt << '\n';
}
