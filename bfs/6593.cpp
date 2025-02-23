#include <bits/stdc++.h>
using namespace std;

int l, r, c;
string board[35][35];
int dist[35][35][35];
int dirX[6] = {1, 0, -1, 0, 0, 0};
int dirY[6] = {0, 1, 0, -1, 0, 0};
int dirZ[6] = {0, 0, 0, 0, 1, -1};

void clear() {
	for (int i = 0; i < 35; i++)
	for (int j = 0; j < 35; j++)
	for (int k = 0; k < 35; k++)
		dist[i][j][k] = -1;
}

void bfs(int x, int y, int z) {
	queue<tuple<int, int, int>> q;
	q.push({x, y, z});
	dist[z][x][y] = 0;
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = get<0>(cur) + dirX[i];
			int ny = get<1>(cur) + dirY[i];
			int nz = get<2>(cur) + dirZ[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
			if (dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == '#') continue;
			q.push({nx, ny, nz});
			dist[nz][nx][ny] = dist[get<2>(cur)][get<0>(cur)][get<1>(cur)] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> board[i][j];
			}
		}
		
		clear();

		tuple<int, int, int> e;
		for (int i = 0; i < l; i++) 
		for (int j = 0; j < r; j++)
		for (int k = 0; k < c; k++) {
			if (board[i][j][k] == 'S') bfs(j, k, i);
			if (board[i][j][k] == 'E') e = {i, j, k};
		}

		int ret = dist[get<0>(e)][get<1>(e)][get<2>(e)];
		if (ret == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << ret << " minute(s).\n";

	}

}
