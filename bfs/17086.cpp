#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[55][55];
int dist[55][55];

int dirX[8] = {1, 0, -1, 0, -1, 1,  1, -1};
int dirY[8] = {0, 1, 0, -1,  1, 1, -1, -1};

vector<pair<int, int>> spos;

void print_dist() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) spos.push_back({i, j});
        }
    }

    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
        dist[i][j] = -1;

    queue<pair<int, int>> q;
    for (auto elem : spos) {
        q.push({elem.X, elem.Y});
        dist[elem.X][elem.Y] = 0;
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret = max(ret, dist[i][j]);
        }
    }

    cout << ret << '\n';
}