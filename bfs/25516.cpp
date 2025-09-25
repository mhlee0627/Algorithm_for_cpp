#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[100005];
int dist[100005];
int ap[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> ap[i];
    }

    for (int i = 0; i <= n; i++) dist[i] = -1;

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (dist[cur] == k+1) break;

        for (auto nxt : adj[cur]) {
            if (dist[nxt] >= 0) continue;

            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == -1) continue;

        if (dist[i] <= k) {
            ret += ap[i];
        }
    }

    cout << ret << '\n';
}
