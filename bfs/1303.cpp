#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
string board[105];
bool vis[105][105];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;
	int ret = 1;
	char sol = board[x][y];

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dirX[i] + cur.X;
			int ny = dirY[i] + cur.Y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (vis[nx][ny]) continue;
			if (board[nx][ny] != sol) continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
			ret++;
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> board[i];

	int w = 0;
	int b = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;

			int score = bfs(i, j);

			if (board[i][j] == 'W') {
				w += (score * score);
			}
			else {
				b += (score * score);
			}

		}
	}

	cout << w << ' ' << b << '\n';
}
