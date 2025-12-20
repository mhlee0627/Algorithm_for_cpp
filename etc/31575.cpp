#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[305][305];
bool vis[305][305];
int dirX[2] = {1, 0};
int dirY[2] = {0, 1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push({0, 0});
	vis[0][0] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.X == m-1 && cur.Y == n-1) {
			cout << "Yes\n";
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] == 0) continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}

	cout << "No\n";
	return 0;
}

