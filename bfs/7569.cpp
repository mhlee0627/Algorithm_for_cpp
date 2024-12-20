#include <bits/stdc++.h>
using namespace std;

int m, n, h;
queue<tuple<int, int, int>> Q;
int dirX[6] = {1, 0, -1, 0, 0, 0};
int dirY[6] = {0, 1, 0, -1, 0, 0};
int dirZ[6] = {0, 0, 0, 0, 1, -1};
int board[100][100][100];
int dist[100][100][100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int k = 0; k < h; k++)
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
        cin >> board[i][j][k];
        dist[i][j][k] = -1;
    }

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j][k] == 1) {
                    Q.push(make_tuple(i, j, k));
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    while(!Q.empty()) {
        tuple<int, int, int> curPos = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = get<0>(curPos) + dirX[i];
            int ny = get<1>(curPos) + dirY[i];
            int nz = get<2>(curPos) + dirZ[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if (board[nx][ny][nz] != 0 || dist[nx][ny][nz] >= 0) continue;
            Q.push(make_tuple(nx, ny, nz));
            dist[nx][ny][nz] = dist[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
        }
    }

    int ret = 0;
    int maxValue = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < h; k++) {
                if (board[i][j][k] == 0 && dist[i][j][k] == -1) {
                    ret = -1;
                    cout << ret;
                    return 0;
                }
                else {
                    maxValue = dist[i][j][k] > maxValue ? dist[i][j][k] : maxValue;
                }
            }
        }
    }

    cout << maxValue;

}