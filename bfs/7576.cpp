#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int, int>> Q;
int box[1001][1001];
int dist[1001][1001];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int M, N;
int ret;
int maxValue;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> box[i][j];
    }

    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + M, -1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] != 1 || dist[i][j] >= 0) continue;
             
            Q.push({i, j});
            dist[i][j] = 0; 
        }
    }

    while(!Q.empty()) {
        pair<int, int> curPos = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (box[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[curPos.X][curPos.Y] + 1;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << dist[i][j] << "  "; 
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
             if (box[i][j] == 0 && dist[i][j] == -1) {
                ret = -1;
            }
            else {
                maxValue = dist[i][j] > maxValue ? dist[i][j] : maxValue;
            }
        }
    }

    if (ret == -1)
        cout << ret;
    else
        cout << maxValue;

}