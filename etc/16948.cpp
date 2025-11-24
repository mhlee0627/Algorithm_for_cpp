#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
pair<int, int> s;
pair<int, int> e;

int dirX[6] = {-2, -2, 0, 0, 2, 2};
int dirY[6] = {-1, 1, -2, 2, -1, 1};
int dist[205][205];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s.X >> s.Y >> e.X >> e.Y;

    queue<pair<int, int>> q;
    q.push({s.X, s.Y});
    dist[s.X][s.Y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.X == e.X && cur.Y == e.Y) {
            cout << dist[cur.X][cur.Y] << "\n";
            return 0;
        }

        for (int i = 0; i < 6; i++) {
            int nx = cur.X + dirX[i];
            int ny = cur.Y + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] > 0) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }

    cout << -1 << "\n";
}