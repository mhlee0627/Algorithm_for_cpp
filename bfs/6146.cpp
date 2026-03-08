#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

#define S 500

int x, y, n;
bool board[1005][1005];
int dist[1005][1005];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        board[a+S][b+S] = true;
    }

    queue<pair<int, int>> q;
    q.push({S, S});
    dist[S][S] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.X == (x+S) && cur.Y == (y+S)) {
            cout << dist[cur.X][cur.Y] << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx > (500+S) || ny < 0 || ny >= (500+S)) continue;
            if (dist[nx][ny] > 0 || board[nx][ny] == true) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
}