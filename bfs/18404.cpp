#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int dirX[8] = {-2, -2, -1, -1,  1,  1,  2, 2};
int dirY[8] = {-1,  1, -2,  2, -2,  2, -1, 1};
int dist[505][505];
int x, y;
vector<pair<int, int>> pos;

void bfs(int s, int e) {
	queue<pair<int, int>> q;
	q.push({s, e});
	dist[s][e] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cur.X + dirX[i];
			int ny = cur.Y + dirY[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] >= 0) continue;

			q.push({nx, ny});
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pos.push_back({a-1, b-1});
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = -1;
		}
	}

	bfs(x-1, y-1);

	for (auto elem : pos) {
		cout << dist[elem.X][elem.Y] << ' ';
	}
	cout << '\n';
}

