#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
string board[1005];
bool vis[1005][1005];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
bool ret;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.X == m-1) ret = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] == '1') continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		if (board[0][i] == '1' || vis[0][i]) continue;

		bfs(0, i);
		if (ret) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

