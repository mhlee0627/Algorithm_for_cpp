#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int m, n;
int board[255][255];
bool vis[255][255];
int dirX[8] = {1, 0, -1, 0,  1, 1, -1, -1};
int dirY[8] = {0, 1, 0, -1, -1, 1,  1, -1};
int ret;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] == 0) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] == 0) continue;

            ret++;
            bfs(i, j);
        }
    }

    cout << ret << '\n';
}