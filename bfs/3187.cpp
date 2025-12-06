#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r, c;
string board[255];
bool vis[255][255];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int k, v;

void checkkv(int x, int y, int *cur_k, int *cur_v) {
    if (board[x][y] == 'k') (*cur_k)++;
    else if (board[x][y] == 'v') (*cur_v)++;
}

void bfs(int x, int y) {
    int cur_k = 0;
    int cur_v = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    checkkv(x, y, &cur_k, &cur_v);

    while (!q.empty()) {
        auto cur =q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (board[nx][ny] == '#' || vis[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
            checkkv(nx, ny, &cur_k, &cur_v);
        }
    }

    if (cur_k > cur_v) {
        v -= cur_v;
    }
    else {
        k -= cur_k;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> board[i];

        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'k') k++;
            else if (board[i][j] == 'v') v++;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '#' || vis[i][j]) continue;
            bfs(i, j);
        }
    }

    cout << k << ' ' << v << '\n';
}