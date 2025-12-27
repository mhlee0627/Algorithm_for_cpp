#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r, c;
string board[105];
bool vis[105][105];
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
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (vis[nx][ny] || board[nx][ny] == '.') continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vis[i][j] || board[i][j] == '.') continue;

			ret++;
			bfs(i, j);
		}
	}

	cout << ret << '\n';
}
