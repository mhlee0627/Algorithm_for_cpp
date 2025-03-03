#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec[105];
bool vis[105];

bool bfs(int s, int e) {
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : vec[cur]) {
			if (nxt == e) return true;
			if (vis[nxt]) continue; 
			q.push(nxt);
			vis[nxt] = true;
		}
	}

	return false;
}

void vis_clear() {
	for (int i = 0; i < 105; i++) vis[i] = 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (tmp) vec[i].push_back(j);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis_clear();
			cout << bfs(i, j) << ' ';
		}
		cout << '\n';
	}
}
