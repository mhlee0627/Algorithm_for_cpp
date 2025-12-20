#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t;
int h, w;
string board[105];
bool vis[105][105];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void clear_vis() {
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			vis[i][j] = false;
		}
	}
}

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
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (vis[nx][ny] || board[nx][ny] != '#') continue;

			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}
		
		clear_vis();

		int ret = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '#' && vis[i][j] == false) {
					bfs(i, j);
					ret++;
				}
			}
		}
	
		cout << ret << '\n';
	}
}
