#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[305][305];
int down_iland[305][305];
int vis[305][305];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int iland_cnt;
int year;

void print_board() {
    cout << "print board\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_vis() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void clear_vis() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] <= 0 || vis[nx][ny] == 1) continue;

            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

void later_1year(int x, int y) {
    int down_iland_high = 0;

    for (int i = 0; i < 4; i++) {
        int nx = dirX[i] + x;
        int ny = dirY[i] + y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] != 0) continue;

        down_iland_high++;
    }

    down_iland[x][y] = down_iland_high;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0 && vis[i][j] != 1) {
                    iland_cnt++;
                    bfs(i, j);
                }
            }
        }

		if (iland_cnt == 0) {
			year = 0;
			break;
		}
        else if (iland_cnt >= 2) {
            // cout << "iland spilt\n";
            break;
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
					if (board[i][j] > 0) {
						later_1year(i, j);
					}
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
					if (board[i][j] > 0) {
	                    board[i][j] -= down_iland[i][j];
	                    if (board[i][j] < 0) board[i][j] = 0;
					}
                }
            }

            // print_board();
            // cout << "iland_cnt: " << iland_cnt << '\n';
            iland_cnt = 0;
            clear_vis();
            year++;
        }
    }

    cout << year << '\n';
}
