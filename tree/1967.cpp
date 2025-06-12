#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
vector<pair<int, int>> adj[10005];
int dist[10005];

pair<int, int> bfs(int root) {
    for (int i = 0; i <= n; i++) dist[i] = -1;
    
    queue<pair<int, int>> q;
    dist[root] = 0;
    q.push({root, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : adj[cur.X]) {
            if (dist[nxt.X] >= 0) continue;
            dist[nxt.X] = dist[cur.X] + nxt.Y;
            q.push({nxt.X, nxt.Y});
        }
    }

    int node = 0;
    int curdist = 0;
    for (int i = 1; i <= n; i++) {
        if (curdist < dist[i]) {
            node = i;
            curdist = dist[i];
        }
    }

    return make_pair(node, dist[node]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    auto first_node = bfs(1);
    auto ret = bfs(first_node.X);

    cout << ret.Y << '\n';
}