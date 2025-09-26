#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
string board[3005];
int dist[3005][3005];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
pair<int, int> pos;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '2') pos = {i, j};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({pos.X, pos.Y});
    dist[pos.X][pos.Y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] == '1') continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;

            if (board[nx][ny] != '0') {
                cout << "TAK\n";
                cout << dist[nx][ny] << '\n';;
                return 0;
            }
        }
    }

    cout << "NIE\n";
}
