#include <bits/stdc++.h>
using namespace std;

int n, r, qc;
vector<int> adj[100005];
int parent[100005];
int deps[100005];

void clear() {
    for (int i = 0; i <= n; i++) parent[i] = 0;
}

int bfs(int root) {
    clear ();
    int ret = 0;
    
    queue<int> q;
    q.push(root);
    ret++;
    parent[root] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (parent[cur] == nxt) continue;
            if (deps[root] > deps[nxt]) continue;

            q.push(nxt);
            ret++;
            parent[nxt] = cur;
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> qc;
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    queue<int> q;
    q.push(r);
    parent[r] = 0;
    deps[r] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (parent[cur] == nxt) continue;
            q.push(nxt);
            parent[nxt] = cur;
            deps[nxt] = deps[cur] + 1;
        }
    }

    for (int i = 0; i < qc; i++) {
        int in;
        cin >> in;
        cout << bfs(in) << '\n';
    }
}