#include <bits/stdc++.h>
using namespace std;

int a, b;
int n, m;
vector<int> adj[1005];
int dist[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i <= n; i++) {
        dist[i] = -1;
    }

    queue<int> q;
    q.push(a);
    dist[a] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (dist[nxt] >= 0) continue;

            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    cout << dist[b] << '\n';
}