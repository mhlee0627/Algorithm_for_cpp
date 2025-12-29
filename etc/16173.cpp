#include <bits/stdc++.h>
using namespace std;

int n;
int board[5][5];
bool vis[5][5];
int dirX[2] = {0, 1};
int dirY[2] = {1, 0};

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

	stack<tuple<int, int, int>> s;
	s.push({0, 0, board[0][0]});

	while (!s.empty()) {
		auto cur = s.top();
		s.pop();

		if (get<0>(cur) == n-1 && get<1>(cur) == n-1) {
			cout << "HaruHaru\n";
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			if (board[get<0>(cur)][get<1>(cur)] == 0) continue;
			int nx = get<0>(cur) + dirX[i] * get<2>(cur);
			int ny = get<1>(cur) + dirY[i] * get<2>(cur);
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			
			s.push({nx, ny, board[nx][ny]});
		}
	}

	cout << "Hing\n";
}

