#include <bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> adj[1005];
bool vis[1005];

void clear_vis() {
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        adj[i].clear();
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
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

    vector<int> retv;

    cin >> t;
    while (t--) {
        cin >> n;

        clear_vis();

        for (int u = 1; u <= n; u++) {
            int v;
            cin >> v;

            adj[u].push_back(v);
        }

        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            bfs(i);
            ret++;
        }

        retv.push_back(ret);
    }

    for (auto elem : retv) {
        cout << elem << '\n';
    }
}