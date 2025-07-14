#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

#define S 1
#define W 2

int r, c;
pair<int, int> st;
pair<int, int> dt;
vector<pair<int, int>> wt;

string board[55];
int dist[55][55];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void bfs() {
	queue<tuple<int, int, int>> q;

	for (auto elem : wt) {
		q.push({elem.X, elem.Y, W});
	}
	q.push({st.X, st.Y, S});

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dirX[i] + get<0>(cur);
			int ny = dirY[i] + get<1>(cur);
			int nz = get<2>(cur);
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == 'X') continue;

			if (nz == S) {
				if (dist[nx][ny] > 0) continue;
				if (board[nx][ny] == '*') continue;
				if (board[nx][ny] == 'D') {
					cout << dist[get<0>(cur)][get<1>(cur)] + 1 << '\n';
					return;
				}

				q.push({nx, ny, S});
				dist[nx][ny] = dist[get<0>(cur)][get<1>(cur)] + 1;
			}
			else {
				if (board[nx][ny] == 'D') continue;
				if (board[nx][ny] == '*') continue;

				q.push({nx, ny, W});
				board[nx][ny] = '*';
			}

		}
	}

	cout << "KAKTUS\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'D') dt = {i, j};
			else if (board[i][j] == 'S') st = {i, j};
			else if (board[i][j] == '*') wt.push_back({i, j});
		}
	}

	bfs();
}

