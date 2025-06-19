#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MAXV (130 * 130 * 10)

int n;
int board[130][130];
int dist[130][130];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                dist[i][j] = MAXV;
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = board[0][0];

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = dirX[i] + cur.X;
                int ny = dirY[i] + cur.Y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] <= dist[cur.X][cur.Y] + board[nx][ny]) continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + board[nx][ny];
            }
        }

        cout << "Problem " << ++cnt << ": " << dist[n-1][n-1] << '\n';
    }
}