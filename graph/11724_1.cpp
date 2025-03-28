#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> gr[1005];
bool vis[1005];
int ans;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : gr[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;

        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
}