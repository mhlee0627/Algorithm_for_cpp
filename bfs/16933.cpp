#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
string board[1005];
int dist[1005][1005][11][2];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    dist[0][0][0][0] = 1;

    while (!q.empty()) {
        tuple<int, int, int, int> cur = q.front();
        q.pop();

        // std::cout << "pos(" << get<0>(cur) << "," << get<1>(cur) << "), kd(" << get<2>(cur) << "," << get<3>(cur)
        //          << ")-> dist(" << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][get<3>(cur)] << ")\n";

        if (get<0>(cur) == n-1 && get<1>(cur) == m-1) {
            cout << dist[n-1][m-1][get<2>(cur)][get<3>(cur)] << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = dirX[i] + get<0>(cur);
            int ny = dirY[i] + get<1>(cur);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int nk = get<2>(cur);
            int nd = 1 - get<3>(cur);

            if (board[nx][ny] == '1') {
                if (nk == k) continue;
                
                if (get<3>(cur) == 0) {
                    if (dist[nx][ny][nk+1][nd] > 0) continue;

                    q.push({nx, ny, nk+1, nd});
                    dist[nx][ny][nk+1][nd] = dist[get<0>(cur)][get<1>(cur)][nk][get<3>(cur)] + 1;
                }
                else {
                    if (dist[get<0>(cur)][get<1>(cur)][nk][nd] > 0) continue;

                    q.push({get<0>(cur), get<1>(cur), nk, nd});
                    dist[get<0>(cur)][get<1>(cur)][nk][nd] = dist[get<0>(cur)][get<1>(cur)][nk][get<3>(cur)] + 1;
                }
            }
            else {
                if (dist[nx][ny][nk][nd] > 0) continue;

                q.push({nx, ny, nk, nd});
                dist[nx][ny][nk][nd] = dist[get<0>(cur)][get<1>(cur)][nk][get<3>(cur)] + 1;
            }
        }
    }

    cout << -1 << '\n';
}