#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int board[105][105];
int iland[105][105];
bool vis[105][105];
int dist[105][105];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void print_iland() {
    cout << "iland print\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << iland[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_dist() {
    cout << "dist print\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void clear_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }
}

void bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push({x, y});
    iland[x][y] = num;
    vis[x][y] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || iland[nx][ny] > 0) continue;
            if (board[nx][ny] != 1) continue;

            q.push({nx, ny});
            iland[nx][ny] = num;
            vis[nx][ny] = true;
        }
    }
}

int find_min_dist(int x, int y) {
    clear_dist();

    queue<pair<int, int>> q;
    int cur_iland_num = iland[x][y];
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (iland[cur.X][cur.Y] > 0 && iland[cur.X][cur.Y] != cur_iland_num) {
            // cout << dist[cur.X][cur.Y] << '\n';
            return dist[cur.X][cur.Y] - 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + cur.X;
            int ny = dirY[i] + cur.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (iland[nx][ny] == cur_iland_num) continue;
            if (dist[nx][ny] > 0) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }

    return 0;
}

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

    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && iland[i][j] == 0) {
                bfs(i, j, num++);
            }
        }
    }

    // print_iland();

    int minv = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                int curv = find_min_dist(i, j);
                if (curv != 0) {
                    minv = min(minv, curv);
                }
            }
        }
    }

    cout << minv << '\n';
}