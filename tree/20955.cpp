#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int parent[100005];
int connect_cnt;
int disconnect_cnt;

void bfs(int root) {
    connect_cnt++;

    queue<int> q;
    q.push(root);
    parent[root] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (parent[cur] == nxt) continue;
            if (parent[nxt] >= 0) {
                // cout << "nxt: " << nxt << "| cur: " << cur  << '\n';
                disconnect_cnt++;
                continue;
            }
            q.push(nxt);
            parent[nxt] = cur;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i <= n; i++) parent[i] = -1;

    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) {
            bfs(i);
        }
    }

    cout << (connect_cnt-1) + (disconnect_cnt/2) << '\n';
}