#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int, int>> Q;
int t, r;
int cX, cY;
int dX, dY;
int dist[300][300];
int dirX[8] = {-1, -2, -2, -1, 1, 2,  2,  1};
int dirY[8] = {-2, -1,  1,  2, 2, 1, -1, -2};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> r >> cX >> cY >> dX >> dY;

        for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            dist[i][j] = -1;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) {
                if (dist[i][j] >= 0) continue;

                Q.push({cX, cY});
                dist[cX][cY] = 0;
                while(!Q.empty()) {
                    pair<int, int> curPos = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 8; dir++) {
                        int nx = curPos.X + dirX[dir];
                        int ny = curPos.Y + dirY[dir];
                        if (nx < 0 || nx >= r || ny < 0 || ny >= r) continue;
                        if (dist[nx][ny] >= 0) continue;
                        Q.push({nx, ny});
                        dist[nx][ny] = dist[curPos.X][curPos.Y] + 1;
                    }
                }
            }
        }

        // for (int i = 0; i < r; i++){
        //     for (int j = 0; j < r; j++) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << dist[dX][dY] << "\n";
    }

}