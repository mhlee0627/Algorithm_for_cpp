#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[15];
int dist[15][15];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	dist[x][y] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (board[cur.X][cur.Y] == 'L') {
			cout << dist[cur.X][cur.Y] - 2 << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
			if (board[nx][ny] == 'R' || dist[nx][ny] >= 1) continue;
			
			q.push({nx, ny});
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 'B') {
				bfs(i, j);
				return 0;
			}
		}
	}
}
