#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
int board[505][505];
bool vis[505][505];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny]) continue;
			int v = abs(board[cur.X][cur.Y] - board[nx][ny]);
			if (v > k) continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == true) continue;
			ret++;
			bfs(i, j);
		}
	}

	cout << ret << '\n';
}




