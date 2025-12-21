#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, t;
int board[1005][1005];
bool vis[1005][1005];
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
			if (vis[nx][ny] || board[nx][ny] == 0) continue;

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
		for (int j = 0; j < m; j++) {
			int r = 0;
			int g = 0;
			int b = 0;
			
			cin >> r >> g >> b;
			board[i][j] = (r + g + b) / 3;
		}
	}
	cin >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] >= t) {
				board[i][j] = 255;
			}
			else {
				board[i][j] = 0;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;

			ret++;
			bfs(i, j);
		}
	}

	cout << ret << '\n';
}

