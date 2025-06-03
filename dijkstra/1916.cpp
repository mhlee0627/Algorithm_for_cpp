#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

#define X first
#define Y second

int n, m, st, dt;
vector<pair<int, int>> adj[1005];
int dist[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; i++) dist[i] = INF;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    cin >> st >> dt;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});

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

    cout << dist[dt] << '\n';
}