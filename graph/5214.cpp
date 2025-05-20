#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<int> adj[101005];
int dist[101005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;

            adj[n+i].push_back(x);
            adj[x].push_back(n+i);
        }
    }

    for (int i = 0; i < 101005; i++) dist[i] = -1;

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n) {
            cout << dist[n]/2 + 1 << '\n';
            return 0;
        }

        for (auto nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;

            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    cout << -1 << '\n';
}