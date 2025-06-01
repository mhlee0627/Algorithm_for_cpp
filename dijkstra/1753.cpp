#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define X first
#define Y second

int v, e, st;
vector<pair<int, int>> adj[20005];
int dist[20005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> st;
    for (int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    for (int i = 0; i <= v; i++) dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[st] = 0;
    pq.push({dist[st], st});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (dist[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}