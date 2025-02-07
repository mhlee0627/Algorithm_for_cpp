#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int board[101][101];
int safe[101][101];
int rain;
int cnt;

queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void print_s() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << safe[i][j] << ' ';
		}
		cout << '\n';
	}
}

void clear_safe() {
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) safe[i][j] = 0;
}

void bfs(int x, int y) {
	if (board[x][y] <= rain || safe[x][y] > 0) return;
	q.push({x, y});
	safe[x][y] = rain;
	cnt++;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (safe[nx][ny] > 0 || board[nx][ny] <= rain) continue;
			q.push({nx, ny});
			safe[nx][ny] = rain;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int max_val = 0;
	for (rain = 1; rain <= 100; rain++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bfs(i, j);
			}
		}
		//cout << cnt << '\n';
		
		max_val = max(max_val, cnt);

		cnt = 0;
		clear_safe();
	}

	if (max_val == 0) cout << 1 << '\n';
	else cout << max_val << '\n';
}
