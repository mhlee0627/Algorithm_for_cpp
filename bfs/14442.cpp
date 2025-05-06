#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
string board[1005];
int dist[1005][1005][10];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();

        if (get<0>(cur) == n-1 && get<1>(cur) == m-1) {
            cout << dist[n-1][m-1][get<2>(cur)] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + get<0>(cur);
            int ny = dirY[i] + get<1>(cur);
            int nk = get<2>(cur);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (board[nx][ny] == '1') {
                if (nk == k || dist[nx][ny][nk+1] > 0) continue;
                
                q.push({nx, ny, nk+1});
                dist[nx][ny][nk+1] = dist[get<0>(cur)][get<1>(cur)][nk] + 1;
            }
            else {
                if (dist[nx][ny][nk] > 0) continue;

                q.push({nx, ny, nk});
                dist[nx][ny][nk] = dist[get<0>(cur)][get<1>(cur)][nk] + 1;
            }
        }
    }

    cout << -1 << '\n';
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    bfs();
}