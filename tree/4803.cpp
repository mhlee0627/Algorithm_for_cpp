#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[505];
int parent[505];

void clear_adj() {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
}

void clear_parent() {
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
    }
}

bool bfs(int root) {
    queue<int> q;
    q.push(root);
    parent[root] = 0;

    bool isCycle = false;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int cnt = 0;
        for (auto nxt : adj[cur]) {
            if (parent[nxt] >= 0) {
                cnt++;
                continue;
            }

            q.push(nxt);
            parent[nxt] = cur;
        }

        if (cnt >= 2) isCycle = true;
    }

    if (isCycle) return false;
    else return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ret;

    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        clear_adj();
        clear_parent();

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cycle = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] >= 0) continue;
            if (bfs(i)) cycle++;
        }

        ret.push_back(cycle);
    }

    int nb = 1;
    for (auto elem : ret) {
        if (elem == 0) {
            cout << "Case " << nb++ << ": No trees.\n";
        }
        else if (elem == 1) {
            cout << "Case " << nb++ << ": There is one tree.\n";
        }
        else {
            cout << "Case " << nb++ << ": A forest of " << elem << " trees.\n";
        }
    }
}