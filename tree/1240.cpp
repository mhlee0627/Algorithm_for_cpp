#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[1005];
int dist[1005];

void clear() {
    for (int i = 0; i <= n; i++) dist[i] = -1;
}

void bfs(int st, int en) {
    clear();
    
    queue<pair<int, int>> q;
    q.push({st, 0});
    dist[st] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.X == en) {
            cout << dist[cur.X] << '\n';
            break;;
        }

        for (auto nxt : adj[cur.X]) {
            if (dist[nxt.X] >= 0) continue;
            q.push({nxt.X, nxt.Y});
            dist[nxt.X] = dist[cur.X] + nxt.Y;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;

        bfs(st, en);
    }

}