#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int t;
int board[105][105];
int dist[105][105];
pair<int, int> gram;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void clear_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 1 || dist[nx][ny] > 0) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                gram = {i, j};
            }
        }
    }

    clear_dist();

    bfs(0, 0);

    int gram_dist = 200000;
    if (dist[gram.X][gram.Y] >= 0) {
        gram_dist = dist[gram.X][gram.Y] + (n - gram.X) + (m - gram.Y) - 2;
    }

    int nomal_dist = 200000;
    if (dist[n-1][m-1] >= 0) {
        nomal_dist = dist[n-1][m-1];
    }

    int minv = min(gram_dist, nomal_dist);

    if ( minv <= t) {
        cout << minv << '\n';
        return 0;
    }
     
    cout << "Fail\n";
}