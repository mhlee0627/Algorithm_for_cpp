#include <bits/stdc++.h>
using namespace std;

int k, w, h;
int board[205][205];
int dist[205][205][31];
int dirX[12] = {1, 0, -1, 0, -1, -2, -2, -1, 1, 2,  2,  1};
int dirY[12] = {0, 1, 0, -1, -2, -1,  1,  2, 2, 1, -1, -2};

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();

        if (get<0>(cur) == h-1 && get<1>(cur) == w-1) {
            cout << dist[h-1][w-1][get<2>(cur)] << '\n';
            return;
        }

        for (int i = 0; i < 12; i++) {
            int nx = dirX[i] + get<0>(cur);
            int ny = dirY[i] + get<1>(cur);
            int nk = get<2>(cur);
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            if (i >= 4) {
                if (nk == k) continue;
                if (dist[nx][ny][nk+1] > 0 || board[nx][ny] == 1) continue;

                q.push({nx, ny, nk+1});
                dist[nx][ny][nk+1] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
            else {
                if (dist[nx][ny][nk] > 0 || board[nx][ny] == 1) continue;

                q.push({nx, ny, nk});
                dist[nx][ny][nk] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
    }

    cout << -1 << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    bfs();
}