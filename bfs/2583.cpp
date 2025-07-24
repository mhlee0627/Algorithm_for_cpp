#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int m, n, k;
bool board[105][105];
bool vis[105][105];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
	int ret = 0;
	queue<pair<int, int>> q;
	q.push({x, y});
	ret++;
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dirX[i] + cur.X;
			int ny = dirY[i] + cur.Y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny]) continue;

			q.push({nx, ny});
			ret++;
			vis[nx][ny] = true;
		}
	}

	return ret;
}

void func(int sx, int sy, int ex, int ey) {
	for (int x = sx; x < ex; x++) {
		for (int y = sy; y < ey; y++) {
			board[x][y] = true;
		}
	}
}

void print_brd() {
	cout << "print brd" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(void)
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		func(x1, y1, x2, y2);
	}

	vector<int> vec;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] || vis[i][j]) continue;

			vec.push_back(bfs(i, j));
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << '\n';
	for (auto elem : vec) cout << elem << ' ';
	cout << '\n';
}
