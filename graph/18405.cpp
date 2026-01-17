#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;
int board[205][205];
queue<pair<int, int>> q[1005];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int s, x, y;

void print_brd() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bear(int v) {
    if (q[v].empty()) return;

    vector<pair<int, int>> vec;
    while (!q[v].empty()) {
        vec.push_back(q[v].front());
        q[v].pop();
    }

    for (auto pos : vec) {
        for (int i = 0; i < 4; i++) {
            int nx = pos.X + dirX[i];
            int ny = pos.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != 0) continue;

            q[v].push({nx, ny});
            board[nx][ny] = v;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] != 0) {
                q[board[i][j]].push({i, j});
            }
        }
    }

    cin >> s >> x >> y;

    for (int t = 0; t < s; t++) {
        for (int i = 1; i <= k; i++) {
            bear(i);
        }
    }

    // print_brd();

    cout << board[x-1][y-1] << '\n';
}