#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[101];
int dist[101][101];
queue<pair<int, int>> Q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int N, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) fill(dist[i], dist[i] + M, -1);

    Q.push({0, 0});
    dist[0][0] = 0;
    while(!Q.empty()) {
        pair<int, int> curPos = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.X + dirX[i];
            int ny = curPos.Y + dirY[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '0' || dist[nx][ny] != -1) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[curPos.X][curPos.Y] + 1;
        }
    }

    cout << dist[N-1][M-1] + 1;
}