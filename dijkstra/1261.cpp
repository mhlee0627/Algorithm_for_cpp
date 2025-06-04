#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define X first
#define Y second

int n, m;
string board[105];

vector<pair<int, int>> adj[10005];
int dist[10005];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 0; i <= n*m; i++)  dist[i] = INF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int w;
            if (board[i][j] == '1') w = 1;
            else w = 0;

            for (int k = 0; k < 4; k++) {
                int nx = dirX[k] + i;
                int ny = dirY[k] + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                adj[m*nx + ny].push_back({w, i*m + j});
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (dist[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }

    cout << dist[n*m -1] << '\n';
}
