#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
vector<pair<int, int>> adj[5005];
long long dist[5005];
long long ret;

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

    for (int i = 0; i <= n; i++) dist[i] = -1;

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        ret = max(ret, dist[cur]);

        for (auto nxt : adj[cur]) {
            if (dist[nxt.X] >= 0) continue;
            
            q.push(nxt.X);
            dist[nxt.X] = dist[cur] + nxt.Y;
        }
    }

    cout << ret << '\n';
}   