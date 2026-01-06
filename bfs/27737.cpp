#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
int board[105][105];
bool vis[105][105];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
	int ret = 1;
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 1 || vis[nx][ny]) continue;

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

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> mv;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1 || vis[i][j]) continue;
			mv.push_back(bfs(i, j));
		}
	}

	int ret = 0;
	for (auto elem : mv) {
		if (elem % k == 0) {
			ret += (elem/k);
		}
		else {
			ret += (elem/k);
			ret += 1;
		}
	}

	if (ret == 0) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	int tmp = m - ret;

	if (tmp >= 0) {
		cout << "POSSIBLE\n";
		cout << tmp << '\n';
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}




