#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> s_adj[505];
vector<int> b_adj[505];
bool vis[505];

void clear_vis() {
    for (int i = 0; i <= n; i++) vis[i] = false;
}

int s_bfs(int x) {
    clear_vis();
    
    queue<int> q;
    q.push(x);
    vis[x] = true;

    int ret = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : s_adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
            ret++;
        }
    }

    return ret;
}

int b_bfs(int x) {
    clear_vis();
    
    queue<int> q;
    q.push(x);
    vis[x] = true;

    int ret = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : b_adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
            ret++;
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        s_adj[a].push_back(b);
        b_adj[b].push_back(a);
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int total = b_bfs(i) + s_bfs(i) + 1;
        if (total == n) ret++;
    }

    cout << ret << '\n';
}