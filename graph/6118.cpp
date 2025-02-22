#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[20005];
int dist[20005];

void clear_dist() {
    for (int i = 0; i < 20005; i++) dist[i] = -1;
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : vec[cur]) {
            if (dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int s = 0;
    int e = 0;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }

    clear_dist();
    bfs(1);

    int max_v = 0;
    for (int i = 1; i <= n; i++) {
        max_v = max(max_v, dist[i]);
    }

    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (max_v == dist[i]) ret.push_back(i);
    }

    cout << ret[0] << ' ' << max_v << ' ' << ret.size() << '\n';
}