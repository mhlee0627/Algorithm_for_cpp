#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
string board[1005];
int dist[1005][1005][2];
int dirX[4] = {1, 0, -1 ,0};
int dirY[4] = {0, 1, 0, -1};

void clear_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = -1;
            }
        }
    }
}

void bfs() {
    // 좌표(x, y) , 벽을부숨여부(1, 0)
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.first.X;
            int ny = dirY[i] + cur.first.Y;
            int nblock = cur.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny][nblock] > 0) continue;
            
            if (board[nx][ny] == '1') {
                if (nblock == 1) {
                    continue;
                }
                else {
                    nblock = 1;
                    q.push({{nx, ny}, nblock});
                    dist[nx][ny][nblock] = dist[cur.first.X][cur.first.Y][cur.second] + 1;
                }
            }   
            else {
                q.push({{nx, ny}, nblock});
                dist[nx][ny][nblock] = dist[cur.first.X][cur.first.Y][nblock] + 1;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    clear_dist();
    bfs();

    if ((dist[n-1][m-1][0] > 0) && (dist[n-1][m-1][1] > 0)) {
        cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]) << '\n';
    }
    else if (dist[n-1][m-1][0] > 0) {
        cout << dist[n-1][m-1][0] << '\n';
    }
    else if (dist[n-1][m-1][1] > 0) {
        cout << dist[n-1][m-1][1] << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}