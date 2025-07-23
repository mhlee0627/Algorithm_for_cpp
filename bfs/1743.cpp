#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
int board[105][105];
bool vis[105][105];
int ret;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
	int t = 0;
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;
	t++;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dirX[i] + cur.X;
			int ny = dirY[i] + cur.Y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
			t++;
		}
	}
	
	return t;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		board[a-1][b-1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] != 1) continue;
			
			ret = max(ret, bfs(i, j));
		}
	}

	cout << ret << '\n';
}

