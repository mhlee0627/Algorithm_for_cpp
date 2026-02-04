#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
string board[55];
bool vis[55][55];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (board[cur.X][cur.Y] == '-') {
			int nx = cur.X;
			int ny = cur.Y + 1;
			if (ny < 0 || ny >= m) continue;
			if (board[nx][ny] != '-') continue;
			if (vis[nx][ny] == true) continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
		else { 
			int nx = cur.X + 1;
			int ny = cur.Y;
			if (nx < 0 || nx >= n) continue;
			if (board[nx][ny] != '|') continue;
			if (vis[nx][ny] == true) continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == true) continue;
			bfs(i, j);
			ret++;
		}
	}

	cout << ret << '\n';
}
